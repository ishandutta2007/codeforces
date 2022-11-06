#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, h;
int r[101], c[101];
int board[101][101];
int main()
{
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < m; i++)
		scanf("%d", &r[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		scanf("%d", &board[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (board[i][j] == 1)
			{
				printf("%d ", min(r[j], c[i]));
			}
			else
				printf("0 ");

		printf("\n");
	}

}