#include <cstdio>
#include <cmath>
#include <set>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 100007;
const int MAXP = 20;

int last[MAXN];
int next[MAXN << 1], dest[MAXN << 1], id[MAXN << 1];
int f[MAXN];
int n, m, k;

int up[MAXN][MAXP], deep[MAXN];
int lg[MAXN];
int ans[MAXN];

void dfs(int x, int p)
{
	deep[x] = deep[p] + 1;
	up[x][0] = p;
	for (int i = 1; i < MAXP && up[x][i - 1]; i++)
		up[x][i] = up[up[x][i - 1]][i - 1];

	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (y == p) continue;
		dfs(y, x);
	}
}

void DFS(int x, int p)
{
	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (y == p) continue;
		DFS(y, x);

		ans[id[i]] = f[y];
		f[x] += f[y];
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
   	{
   		int x, y;
   		scanf("%d %d", &x, &y);

   		dest[i] = y;
   		id[i] = i;
   		next[i] = last[x];
   		last[x] = i;

   		dest[i + n] = x;
   		id[i + n] = i;
   		next[i + n] = last[y];
   		last[y] = i + n;
   	}

   	dfs(1, 0);

   	lg[1] = 0;
   	for (int i = 2; i < MAXN; i++)
   		lg[i] = lg[i >> 1] + 1;

   	scanf("%d", &m);
   	while (m--)
   	{
   		int x, y;
   		scanf("%d %d", &x, &y);
   		f[x]++;
   		f[y]++;
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
		f[x] -= 2;
	}

	DFS(1, 0);

	for (int i = 1; i < n; i++)
	{
		if (1 < i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}