#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char arr[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool f(int x, int y, char t, char t2)
{
	int nx, ny, i;

	arr[x][y] = t2;

	for(i = 0; i<4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		while(0<=nx&&nx<n && 0<=ny&&ny<m && arr[nx][ny] != '*')
		{
			if(arr[nx][ny] == 'T')
				return 1;
			if(arr[nx][ny] == t)
				break;
			arr[nx][ny] = t2;
			nx += dx[i];
			ny += dy[i];
		}
	}

	return 0;
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i<n; i++)
		scanf("%s", arr[i]);

	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			if(arr[i][j] == 'S')
			{
				if(f(i, j, 'S', 'X'))
				{
					printf("YES");
					return 0;
				}
			}
		}
	}

	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			if(arr[i][j] == 'X')
			{
				if(f(i, j, 'X', 'Y'))
				{
					printf("YES");
					return 0;
				}
			}
		}
	}

	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			if(arr[i][j] == 'Y')
			{
				if(f(i, j, 'Y', 'Z'))
				{
					printf("YES");
					return 0;
				}
			}
		}
	}

	printf("NO");
	return 0;
}