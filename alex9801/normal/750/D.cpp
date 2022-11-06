#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[40];
int mem[310][310];
int tmp[310][310];
bool chk[310][310];
const int m = 155;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main()
{
	int n, x, y, r, i, j, k, l, t;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(i = 0; i<arr[1]; i++)
		chk[m][m-i] = 1;
	mem[m][m-(arr[1]-1)] = (1<<1) | (1<<7);

	for(i = 2; i<=n; i++)
	{
		for(j = 0; j<310; j++)
		{
			for(k = 0; k<310; k++)
			{
				if(!mem[j][k])
					continue;
				for(l = 0; l<8; l++)
				{
					if(mem[j][k] & (1<<l))
					{
						x = j;
						y = k;
						for(t = 0; t<arr[i]; t++)
						{
							x += dx[l];
							y += dy[l];
							chk[x][y] = 1;
						}
						tmp[x][y] |= 1<<((l+1)%8);
						tmp[x][y] |= 1<<((l+7)%8);
					}
				}
			}
		}

		for(j = 0; j<310; j++)
			for(k = 0; k<310; k++)
				mem[j][k] = tmp[j][k];
		memset(tmp, 0, sizeof(tmp));
	}

	r = 0;
	for(j = 0; j<310; j++)
		for(k = 0; k<310; k++)
			if(chk[j][k])
				r++;
	printf("%d", r);

	return 0;
}