#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 55;
const int MAXM = 55;
const int INF = (int)(1e+9);

char a[MAXN], b[MAXN];
bool f[MAXN][MAXN][26], g[MAXN][MAXN][26];

int F[MAXN][MAXN][MAXN][MAXN];

int next[MAXM];

char curr[MAXM];
int last[26][26];
int n, m, k;

int run(char a[MAXN], int &n, bool f[MAXN][MAXN][26])
{
	n = strlen(a);
	memset(f, 0, sizeof(f));
	
	for (int i = 0; i < n; i++)
		a[i] -= 'a';
	
	for (int i = 0; i < n; i++)
		f[i][i][a[i]] = true;
	
	for (int l = 1; l < n; l++)
		for (int i = 0; i < n - l; i++)
		{
			int j = i + l;
			
			for (int z = i; z < j; z++)
				for (int x = 0; x < 26; x++)
					if (f[i][z][x])
						for (int y = 0; y < 26; y++)
							if (f[z + 1][j][y])
							{
								int k = last[x][y];
								while (k)
								{
									f[i][j][curr[k]] = true;
									k = next[k];
								}
							}
		}
	return 0;
}

int main ()
{
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	gets(a);
	gets(b);
	scanf("%d\n", &k);
	for (int i = 1; i <= k; i++)
	{
		char x, y;
		scanf("%c->%c%c\n", &curr[i], &x, &y);
		
		x -= 'a';
		y -= 'a';
		curr[i] -= 'a';
		
		next[i] = last[x][y];
		last[x][y] = i;
	}
	
	run(a, n, f);
	run(b, m, g);
	
	for (int l1 = 0; l1 < n; l1++)
		for (int i1 = 0; i1 < n - l1; i1++)
		{
			int j1 = i1 + l1;
			for (int l2 = 0; l2 < m; l2++)
				for (int i2 = 0; i2 < m - l2; i2++)
				{
					int j2 = i2 + l2;
					F[i1][j1][i2][j2] = INF;
					
					for (int x = 0; x < 26; x++)
						if (f[i1][j1][x] && g[i2][j2][x])
						{
							F[i1][j1][i2][j2] = 1;
							break;
						}
					
					if (F[i1][j1][i2][j2] == 1) continue;
					
					for (int z1 = i1; z1 < j1; z1++)
						for (int z2 = i2; z2 < j2; z2++)
							F[i1][j1][i2][j2] = min(F[i1][j1][i2][j2], F[i1][z1][i2][z2] + F[z1 + 1][j1][z2 + 1][j2]);
				}
		}
	int ans = F[0][n - 1][0][m - 1];
	printf("%d\n", ans == INF? -1 : ans);
    return 0;
}