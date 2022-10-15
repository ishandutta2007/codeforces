#include <cstdio>
#include <cmath>
#include <set>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 100007;
const int MAXM = 200007;
const int MAXP = 20;

int last[MAXN];
int next[MAXM], dest[MAXM], id[MAXM];
int type[MAXM];
int g[MAXN], cnt;
int f[MAXN];
int comp[MAXN];
int LAST[MAXN];
int NEXT[MAXM], DEST[MAXM];
int n, m, k;
int up[MAXN][MAXP], deep[MAXN];
int lg[MAXN];

void dfs_second(int x, int t)
{
	if (comp[x]) return;
	comp[x] = t;
	for (int i = last[x]; i; i = next[i])
		if (!type[id[i]])
			dfs_second(dest[i], t);
}

void dfs(int x, int p)
{
	g[x] = ++cnt;
	f[x] = g[x];
	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (y == p) continue;
		if (g[y])
		{
			f[x] = min(f[x], g[y]);
			continue;
		}
		dfs(y, x);
		if (g[x] < f[y])
			type[id[i]] = true;
		f[x] = min(f[x], f[y]);
	}
}


void dfs_third(int x, int p)
{
	deep[x] = deep[p] + 1;
	up[x][0] = p;
	for (int i = 1; i < MAXP && up[x][i - 1]; i++)
		up[x][i] = up[up[x][i - 1]][i - 1];

	for (int i = LAST[x]; i; i = NEXT[i])
	{
		int y = DEST[i];
		if (deep[y]) continue;
		dfs_third(y, x);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
   	{
   		int x, y;
   		scanf("%d %d", &x, &y);

   		dest[i] = y;
   		id[i] = i;
   		next[i] = last[x];
   		last[x] = i;

   		dest[i + m] = x;
   		id[i + m] = i;
   		next[i + m] = last[y];
   		last[y] = i + m;
   	}

   	dfs(rand() % n + 1, 0);

   	for (int i = 1; i <= n; i++)
   		if (comp[i] == 0)
   			dfs_second(i, ++k);

   	m = 0;
   	for (int i = 1; i <= n; i++)
   		for (int j = last[i]; j; j = next[j])
   		{
   			if (!type[id[j]]) continue;

   			m++;
   			DEST[m] = comp[dest[j]];
   			NEXT[m] = LAST[comp[i]];
   			LAST[comp[i]] = m;
   		}
   	dfs_third(rand() % k + 1, 0);

   	lg[1] = 0;
   	for (int i = 2; i < MAXN; i++)
   		lg[i] = lg[i >> 1] + 1;

   	scanf("%d", &m);
   	while (m--)
   	{
   		int x, y;
   		scanf("%d %d", &x, &y);
   		x = comp[x];
   		y = comp[y];
   		int ans = deep[x] + deep[y];
   		while (deep[x] > deep[y]) x = up[x][lg[deep[x] - deep[y]]];
   		while (deep[x] < deep[y]) y = up[y][lg[deep[y] - deep[x]]];

   		if (x != y)
   		{
       		for (int t = MAXP - 1; t >= 0; t--)
       			if (up[x][t] != up[y][t])
       			{
       				x = up[x][t];
       				y = up[y][t];
       			}
			x = up[x][0];
		}
		printf("%d\n", ans - 2 * deep[x]);
	}
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}