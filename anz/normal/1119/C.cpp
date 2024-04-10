#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int board[501][501];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		scanf("%d", &board[i][j]);

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		int t;
		scanf("%d", &t);
		board[i][j] ^= t;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (board[i][j])
		{
			int r = -1;
			for (int k = i + 1; k < n; k++)
			{
				if (board[k][j])
				{
					r = k;
					break;
				}
			}
			if (r == -1)
			{
				printf("No");
				return 0;
			}

			int c = -1;
			for (int k = j + 1; k < m; k++)
			{
				if (board[i][k])
				{
					c = k;
					break;
				}
			}

			if (c == -1)
			{
				printf("No");
				return 0;
			}

			board[i][j] = !board[i][j];
			board[r][j] = !board[r][j];
			board[i][c] = !board[i][c];
			board[r][c] = !board[r][c];
		}
	}
	printf("Yes");
}