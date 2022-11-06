#include <stdio.h>

char arr[501][501];
int mem1[501][501];
int mem2[501][501];

int main()
{
	int h, w, q, a, b, c, d, r, i, j, k;
	scanf("%d%d", &h, &w);
	for(i = 1; i<=h; i++)
		scanf("%s", arr[i]+1);
	for(i = 1; i<=h; i++)
	{
		for(k = 2; k<=w; k++)
		{
			mem1[i][k] = mem1[i][k-1];
			if(arr[i][k-1]=='.'&&arr[i][k]=='.')
				mem1[i][k]++;
		}
	}
	for(i = 1; i<=w; i++)
	{
		for(k = 2; k<=h; k++)
		{
			mem2[i][k] = mem2[i][k-1];
			if(arr[k-1][i]=='.'&&arr[k][i]=='.')
				mem2[i][k]++;
		}
	}
	scanf("%d", &q);
	for(i = 0; i<q; i++)
	{
		r = 0;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(j = a; j<=c; j++)
		{
			r += mem1[j][d]-mem1[j][b-1];
			if(arr[j][b-1]=='.'&&arr[j][b]=='.')
				r--;
		}
		for(j = b; j<=d; j++)
		{
			r += mem2[j][c]-mem2[j][a-1];
			if(arr[a-1][j]=='.'&&arr[a][j]=='.')
				r--;
		}
		printf("%d\n", r);
	}
	return 0;
}