//http://codeforces.com/contest/543/problem/C

#include <stdio.h>
#include <vector>
using namespace std;

char s[25][25];
int c[25][25];
int d[25][25];
int e[25][25];
int n, m;
bool been[1 << 21];
int tab[1 << 21];

int pd(int mask)
{
	if(mask == 0)
		return 0;
	if(been[mask])
		return tab[mask];
	been[mask] = true;
	int x;
	for(x = 0; (mask & (1 << x)) == 0; x++);

	int retv = 0x3f3f3f3f;
	for(int i = 0; i < m; i++)
	{
		retv = min(retv, c[x][i] + pd(mask - (1 <<x) ));
		retv = min(retv, d[x][i] + pd(mask & e[x][i]) );
	}
	return tab[mask] = retv;
}

int
main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			int tmp = 0;
			for(int k = 0; k < n; k++)
				if(s[i][j] == s[k][j])
					d[i][j] += c[k][j], tmp = max(tmp, c[k][j]);
				else
					e[i][j] |= (1 << k);
			d[i][j] -= tmp;
		}
		
	printf("%d\n", pd((1 << n) - 1));
}