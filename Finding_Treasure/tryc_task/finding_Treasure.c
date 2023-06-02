#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//////////////////////////////////////////////////////
#define COL				GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK			SetConsoleTextAttribute(COL, 0x0000); 
#define DARK_BLUE		SetConsoleTextAttribute(COL, 0x0001);
#define GREEN			SetConsoleTextAttribute(COL, 0x0002);
#define BLUE_GREEN		SetConsoleTextAttribute(COL, 0x0003);
#define BLOOD			SetConsoleTextAttribute(COL, 0x0004);
#define PURPLE			SetConsoleTextAttribute(COL, 0x0005);
#define DARK_YELLOW		SetConsoleTextAttribute(COL, 0x0006);
#define WHITE			SetConsoleTextAttribute(COL, 0x0007);
#define GRAY			SetConsoleTextAttribute(COL, 0x0008);
#define BLUE			SetConsoleTextAttribute(COL, 0x0009);
#define LIGHT_GREEN		SetConsoleTextAttribute(COL, 0x000a);
#define LIGHT_BLUE		SetConsoleTextAttribute(COL, 0x000b);
#define RED				SetConsoleTextAttribute(COL, 0x000c);
#define PLUM			SetConsoleTextAttribute(COL, 0x000d);
#define YELLOW			SetConsoleTextAttribute(COL, 0x000e);
#define LIGHT_WHITE		SetConsoleTextAttribute(COL, 0x000f);
//////////////////////////////////////////////////////

#define LEFT   75      
#define RIGHT  77      
#define UP     72       
#define DOWN   80 
#define SUBMIT 3

#define ROW     40
#define COLUMN  41

int map[COLUMN][ROW];
int cx = COLUMN - 1;
int cy = ROW - 20;
int find_T = 0;
char* player = { "��" };

void gotoxy(int x, int y);
void start();
void bring_map();
int map_ptf();
void Quiz1();
void Quiz_love();
void Quiz2();
void Quiz3();
void Quiz4();
void find();
void action(int x, int y, int xp, int yp);
int keyControl();

struct keyboard {
	char temp;
	int enter;
	int space_bar;
};

int main()
{
	int input;

	system("mode con: cols=120 lines=46"); //cols=���� lines=���� 
	start();
	system("cls");
	bring_map();
	map_ptf();
	gotoxy(cx, cy);
	LIGHT_WHITE printf("%s", player);

	while (1)
	{
		LIGHT_WHITE printf("");
		input = _getch();

		switch (input)
		{
		case LEFT:
			action(cx / 2 - 1, cy, -2, 0);
			break;

		case RIGHT:
			action(cx / 2 + 1, cy, 2, 0);
			break;

		case UP:
			action(cx / 2, cy - 1, 0, -1);
			break;

		case DOWN:
			action(cx / 2, cy + 1, 0, 1);
			break;
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void bring_map()
{
	FILE* fp = fopen("map.txt", "r");
	for (int i = 0; i < 41; i++)
		for (int j = 0; j < 40; j++)
			fscanf(fp, " %d", &map[i][j]);
}

int map_ptf()
{

	for (int i = 0; i < 41; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				BLUE_GREEN printf("��");
				break;
			case 2:
				RED printf("��");
				break;
			case 3:
				LIGHT_GREEN printf("��");
				break;
			case 4:
				YELLOW printf("��");
				break;
			case 5:
				GREEN printf("��");
				break;
			case 6:
				WHITE printf("YY");
				break;
			case 7:
				LIGHT_WHITE printf("��");
				break;
			case 8:
				YELLOW printf("��");
				break;
			case 9:
				PLUM printf("��");
				break;
			case 10:
				BLUE printf("��");
				break;
			case 11:
				YELLOW printf("��");
				break;
			case 12:
				YELLOW printf("��");
				break;
			case 13:
				YELLOW printf("��");
				break;
			case 14:
				YELLOW printf("��");
				break;
			case 15:
				BLUE_GREEN printf("��");
				break;
			case 16:
				YELLOW printf("<<<");
				LIGHT_WHITE printf("4���� ���� �� %d���� ã�ҽ��ϴ�", find_T);
				YELLOW printf(">>>");
			default: break;
			}
		}
		putchar('\n');
	}
}

void action(int ax, int ay, int xp, int yp)
{
	if ((map[ay][ax] != 1) && (map[ay][ax] != 3) && (map[ay][ax] != 5) && (map[ay][ax] != 6))
	{
		gotoxy(cx, cy);
		if (map[ay][ax] == 10)
		{
			system("cls");
			BLOOD printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
			printf("                                        GAME OVER");
			printf("\n\n\n\n\n\n\n===============================================================================\n");
			Sleep(500);
			exit(0);
		}
		else if (map[ay][ax] == 8)
		{
			Quiz1();
			map[ay][ax] = 0;
		}
		else if (map[ay][ax] == 9)
		{
			Quiz_love();
			map[ay][ax] = 0;
		}
		else if (map[ay][ax] == 11)
		{
			Quiz2();
			map[ay][ax] = 0;
		}
		else if (map[ay][ax] == 12)
		{
			Quiz3();
			map[ay][ax] = 0;
		}
		else if (map[ay][ax] == 13)
		{
			Quiz4();
			map[ay][ax] = 0;
		}
		else if ((map[ay][ax] == 14) || map[ay][ax] == 15)
		{
			find_T++;
			find();
			map[ay][ax] = 0;

			if (find_T == 4)
			{
				system("cls");
				YELLOW printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
				printf("                               ������ ��� ã�Ҵ�!!");
				printf("\n\n\n\n\n\n\n===============================================================================\n");
				system("pause");
				system("cls");
				printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
				printf("                                     �׷���....");
				printf("\n\n\n\n\n\n\n===============================================================================\n");
				system("pause");
				system("cls");
				printf("\n\n\n===============================================================================\n\n\n\n\n\n\n");
				printf("        ������ ��� ã�� ���ڰ� �� ���ΰ��� �������� �ູ�ϰ� ��Ҵ�ϴ�\n\n\n");
				DARK_YELLOW printf("                                       ��");
				YELLOW printf("\n\n\n\n===============================================================================\n");
				exit(0);
			}
		}
		printf("  ");
		map[ay][ax] = 0;
		cx += xp;
		cy += yp;
		gotoxy(cx, cy);
		printf("%s", player);
		gotoxy(40, 20);
	}
}

void Quiz1()
{
	system("cls");

	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                         �ڳ� �ǳɰŸ��� Ŀ���� ������ �ʴ°�");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(1500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                    �� Ŀ�� ���̸� �������� ������ �� �� �����ų�..");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void Quiz_love()
{
	system("cls");

	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                                        ������...");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(1500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                                     ������ ���ܳ���");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void Quiz2()
{
	system("cls");

	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                     �ε鸱 �� �ִ� ���ٸ��� ����...(���� �����ϴٳ�)");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(1500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                        ���� ���� ���������� ������� �� ���ٳ�");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void Quiz3()
{
	system("cls");

	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                                  �߿��� ������");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(1500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                             �׻� ������ ��������...");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void Quiz4()
{
	system("cls");

	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                         ���� ����� �츱 ȥ�������� �Ѵٳ�");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(1500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                            ���� ��� ���� ��¥�ϱ�...");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void find()
{
	system("cls");

	WHITE printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	LIGHT_BLUE printf("                                        ��");
	WHITE printf("\n\n\n\n\n\n\n===============================================================================\n"); Sleep(500); system("cls");
	printf("\n\n\n===============================================================================\n\n\n\n\n\n\n\n");
	printf("                                    ã�Ҵ�!!");
	printf("\n\n\n\n\n\n\n===============================================================================\n"); system("pause"); system("cls");
	map_ptf();
}

void start()
{
	printf("\n\n\n\n");
	printf("                    �����������������������������������������          ��        \n");
	printf("    ��              �����������������������������������������                    \n");
	printf("               ��   �����������������������������������������                    \n");
	printf("                    �����������������������������������������                    \n");
	printf("                    �����������������������������������������                    \n");
	printf("                    �����������������������������������������    ��              \n");
	printf("          ��        �����������������������������������������                    \n");
	printf("                    �����������������������������������������                    \n");
	printf("                    �����������������������������������������                    \n");
	printf("                    �����������������������������������������              ��    \n");
	printf("    ��              �����������������������������������������                    \n");
	printf("                    �����������������������������������������                    \n");
	printf("                    �����������������������������������������        ��          \n");
	printf("                    �����������������������������������������                    \n");
	printf("              ��    �����������������������������������������                    \n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\n                                                        ���� ����");
	printf("\n                                                        ���� ����\n");

	int x = 54;
	int y = 31;

	gotoxy(x - 2, --y);
	printf("��");



	while (1)
	{
		int n = keyControl();

		switch (n)
		{
		case UP:
			if (y > 30)
			{
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, --y);
				printf("��");
			}
			break;
		case DOWN:
			if (y < 31)
			{
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, ++y);
				printf("��");
			}
			break;
		case SUBMIT:
			if (y == 30)
			{
				return 0;
			}
			if (y == 31)
			{
				exit(0);
			}
		}
	}
}

int keyControl()
{
	struct keyboard k;

	k.temp = _getch();
	k.enter = 13;
	k.space_bar = 32;

	if (k.temp == UP)
		return UP;

	else if (k.temp == DOWN)
		return DOWN;

	else if (k.temp == k.enter || k.temp == k.space_bar)
		return SUBMIT;
}

/* ���� �ڵ�
���ñ��: https://geundung.dev/18?category=699626
�� �׸���: https://inpa.tistory.com/entry/C-%F0%9F%92%BE-%EB%AF%B8%EB%A1%9C-%EA%B2%8C%EC%9E%84
gotoxy�Լ�: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=3th_october&logNo=140166614423 */