#include <stdio.h>

char g[112][112];
int a[112][112];
int cw[112][112];


int
main(void)
{
	int n, m;
	char c;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			scanf(" %c", &g[i][j]);
			a[i][j] = ((g[i][j] == 'W') ? 1 : -1);
		}
	int ans = 0;
	for(int i = n; i > 0; i--)
		for(int j = m; j > 0; j--)
			if(a[i][j] != 0)
			{
				ans++;
				for(int k = 1; k <= i; k++)
					for(int l = 1; l <= j; l++)
						a[k][l] -= a[i][j];
			}
	printf("%d\n", ans);
}