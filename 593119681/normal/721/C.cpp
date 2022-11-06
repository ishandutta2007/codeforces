#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, m, T, tot, l = 1, r, Head[N], Deg[N], q[N], Ans[N], Dp[N][N], Fa[N][N];

struct Edge
{
	int next, node, w;
}h[N];

inline void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

int main()
{
	scanf("%d%d%d", &n, &m, &T);
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		Deg[v] ++;
	}
	for (int i = 1; i <= n; i ++)
		if (!Deg[i]) q[++ r] = i;
	while (l <= r)
	{
		int z = q[l ++];
		for (int i = Head[z]; i; i = h[i].next)
		{
			int d = h[i].node;
			if (!(-- Deg[d])) q[++ r] = d;
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			Dp[i][j] = T + 1;
	Dp[1][1] = 0;
	for (int t = 1; t <= n; t ++)
	{
		int z = q[t];
		for (int j = 1; j < n; j ++)
		{
			if (Dp[z][j] == T + 1) continue ;
			for (int i = Head[z]; i; i = h[i].next)
			{
				int d = h[i].node, w = h[i].w;
				if (Dp[d][j + 1] <= Dp[z][j] + w || Dp[z][j] + w > T) continue ;
				Dp[d][j + 1] = Dp[z][j] + w;
				Fa[d][j + 1] = z;
			}
		}
	}
	int i;
	for (i = n; i && Dp[n][i] == T + 1; i --) ;
	printf("%d\n", i);
	for (int j = n, _i = i; j; j = Fa[j][_i --])
		Ans[_i] = j;
	for (int _i = 1; _i <= i; _i ++)
		printf("%d%c", Ans[_i], _i == i ? '\n' : ' ');
	return 0;
}