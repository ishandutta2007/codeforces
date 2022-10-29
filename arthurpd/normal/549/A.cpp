#include <stdio.h>

char c[112][112];
int tab[256];


int
main(void)
{
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf(" %c", &c[i][j]);
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m-1; j++)
		{
			tab['f'] = tab['a'] = tab['c'] = tab['e'] = 0;
			tab[c[i][j]]++, tab[c[i+1][j+1]]++, tab[c[i+1][j]]++, tab[c[i][j+1]]++;
			if(tab['f'] == 1 && tab['a'] == 1 &&  tab['c'] == 1 &&  tab['e'] == 1)
				ans++;
		}
	printf("%d\n", ans);
}