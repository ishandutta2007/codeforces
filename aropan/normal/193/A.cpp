#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 55;

int n, m;
char a[MAXN][MAXN], b[MAXN][MAXN];

void dfs(int x, int y)
{
	if (b[x][y] != '#') return;
	b[x][y] = '.';
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
    	gets(a[i] + 1);

    int cnt = 0;
    int ans = 2;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    	{
    		if (a[i][j] != '#') continue;
    		cnt += 1;

    		int res = 0;
    		for (int dx = -1; dx <= 1; dx++)
    			for (int dy = -1 + (int)(dx != 0); dy <= 1; dy += 2)
    				res += a[i + dx][j + dy] == '#';
    		ans = min(ans, res);
    	}
    if (cnt < 3)
    {
    	puts("-1");
    	return 0;
    }

    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    	{
    		if (a[i][j] != '#') continue;
    		memmove(b, a, sizeof(a));
    		b[i][j] = '.';
    		int res = 0;
    		for (int I = 1; I <= n; I++)
	    		for (int J = 1; J <= m; J++)
	    			if (b[I][J] == '#')
	    			{
	    				res++;
	    				dfs(I, J);
	    			}
	    	 if (res > 1)
	    	 	ans = min(ans, 1);
    	}
    printf("%d\n", ans);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}