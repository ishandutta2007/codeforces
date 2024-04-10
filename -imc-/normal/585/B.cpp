#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char g[115][115];

bool free(char c) { return c == '.' || c == 's'; }

void solve()
{
	int w, k;
	scanf("%d %d", &w, &k);
	
	int h = 3;
	
	for (int y = 0; y < h; y++)
		for (int x = 0; x <= w + 10; x++)
			if (x < w)
				scanf(" %c", &g[x][y]);
			else
				g[x][y] = (x == w + 10 ? 0 : '.');
	
	bool win = false;
	for (int x = 0; x <= w + 5; x++)
		for (int y = 0; y < h; y++)
			if (g[x][y] == 's')
			{
				if (x > w)
				{
					win = true;
					goto breakAll;
				}
				
				if (!free(g[x + 1][y])) continue;
				
				if (y > 0 && free(g[x + 1][y - 1]))
				{
					if (free(g[x + 2][y - 1]) && free(g[x + 3][y - 1]))
						g[x + 3][y - 1] = 's';
				}
				
				if (y < 2 && free(g[x + 1][y + 1]))
				{
					if (free(g[x + 2][y + 1]) && free(g[x + 3][y + 1]))
						g[x + 3][y + 1] = 's';
				}
				
				if (free(g[x + 1][y]) && free(g[x + 2][y]) && free(g[x + 3][y]))
				{
					g[x + 3][y] = 's';
				}
			}
			
	breakAll:;
			
#if 0
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w + 10; x++)
			printf("%c", g[x][y]);
		printf("\n");
	}
#endif
			
	printf("%s\n", win ? "YES" : "NO");
}

int main()
{
#ifdef LOCAL
	freopen("b.in", "r", stdin);
#endif
	
	int nt;
	scanf("%d", &nt);
	for (int i = 0; i < nt; i++)
		solve();
	
	return 0;
}