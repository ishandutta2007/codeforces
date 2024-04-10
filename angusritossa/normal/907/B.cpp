#include <bits/stdc++.h>
using namespace std;
char grid[10][10];
int x, y;
int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) scanf(" %c", &grid[i][j]);
	}
	scanf("%d%d", &x, &y);
	x--;
	y--;
	int a = x%3;
	int b = y%3;
	int count = 0;
	for (int i = a*3; i < a*3+3; i++)
	{
		for (int j = b*3; j < b*3+3; j++)
		{
			if (grid[i][j] == '.') { grid[i][j] = '!'; count++; }
		}
	}
	if (count == 0)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (grid[i][j] == '.') { grid[i][j] = '!'; count++; }
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6) printf(" ");
			printf("%c", grid[i][j]);
		}
		if (i == 2 || i == 5) printf("\n");
		printf("\n");
	}
}