#include <cstdio>
using namespace std;

const char X = 'X';
const char O = '0';

char a[3][3];
int x, o;
int movo;
bool wx, wo;


int check(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (a[x1][y1] == a[x2][y2] && a[x2][y2] == a[x3][y3])
	{
		wx |= a[x1][y1] == X;
		wo |= a[x1][y1] == O;
	}
}

int win()
{
	wx = false;
	wo = false;

	for (int i = 0; i < 3; i++)
	{
		check(i, 0, i, 1, i, 2);
		check(0, i, 1, i, 2, i);
	}
	check(0, 0, 1, 1, 2, 2);
	check(2, 0, 1, 1, 0, 2);

	return wx || wo;
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%c", &a[i][j]);
		scanf("\n");
	}


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			x += a[i][j] == X;
			o += a[i][j] == O;
		}

	if (x != o && x != o + 1)
	{
		puts("illegal");
		return 0;
	}

	if (x + o == 0)
	{
		puts("first");
		return 0;
	}

	movo = x > o;

	if (win())
	{

		bool flag = true;
    
		for (int i = 0; i < 3 && flag; i++)
			for (int j = 0; j < 3 && flag; j++)
			if (a[i][j] != '.')
			{
				if (movo ^ (a[i][j] == O))
				{
					a[i][j] = '.';
    
					flag = flag && win();
    
					if (movo)
						a[i][j] = X;
					else
						a[i][j] = O;
				}
			}

		if (flag)
		{
			puts("illegal");
			return 0;
		}
	}

	win();
	if (wx && wo)
	{
		puts("illegal");
		return 0;
	}

	if (wx)
	{
		puts("the first player won");
		return 0;
	}

	if (wo)
	{
		puts("the second player won");
		return 0;
	}

	if (x + o == 9)
	{
		puts("draw");
		return 0;
	}


	if (movo)
	{
		puts("second");
		return 0;
	}

	if (!movo)
	{
		puts("first");
		return 0;
	}
	return 0;
}