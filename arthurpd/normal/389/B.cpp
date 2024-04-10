//http://codeforces.com/problemset/problem/389/B
#include <stdio.h>
char a[112][112];

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s", a[i]+1);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] == '#')
			{
				if(a[i+1][j] != '#' || a[i+2][j] != '#' || a[i+1][j-1] != '#' || a[i+1][j+1] != '#')
				{
					printf("NO\n");
					return 0;
				}
				a[i+1][j] = a[i+2][j] = a[i+1][j-1] = a[i+1][j+1] = a[i][j] = '.';
			}
	printf("YES\n");
}