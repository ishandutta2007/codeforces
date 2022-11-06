#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, m, tot = 1, done, cnt, Head[N], Fa[N], Dp[N], Dep[N];
bool Vis[N], Flag[N], Root[N], Ok[N], No[N];

struct Edge
{
	int next, node;
}h[N << 2];

void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

void dfs(int z)
{
	Vis[z] = 1;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (Vis[d]) continue ;
		if (z) Flag[i >> 1] = 1;
		else Root[d] = 1;
		Dep[d] = Dep[z] + 1;
		dfs(d);
	}
}

inline int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

void DFS(int z, bool op = 0)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if ((z && !Flag[i >> 1]) || (!z && !Root[d]) || Dep[z] > Dep[d]) continue ;
		DFS(d, op);
		Dp[z] += Dp[d];
		if (!op && z && Dp[d] == 1)
			Fa[d] = z;
		if (!op && z && Dp[d] == 0)
			No[i >> 1] = 1;
		if (op && z && Dp[d] == 0 && !No[i >> 1])
			Ok[i >> 1] = 1;
	}
}

void _DFS(int z)
{	
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if ((z && !Flag[i >> 1]) || (!z && !Root[d]) || Dep[z] > Dep[d]) continue ;
		Fa[d] = Fa[Fa[d]];
		_DFS(d);
	}	
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; i ++)
		addedge(0, i), Fa[i] = i;
	dfs(0);
	for (int i = 1; i <= m; i ++)
		if (!Flag[i])
		{
			int u = h[i << 1].node, v = h[i << 1 | 1].node;
			if (Dep[u] < Dep[v]) swap(u, v);
			Dp[u] ++, Dp[v] --;
		}
	DFS(0);
	_DFS(0);
	for (int i = 1; i <= n; i ++)
		Dp[i] = 0;
	for (int i = 1; i <= m; i ++)
		if (!Flag[i])
		{
			int u = h[i << 1].node, v = h[i << 1 | 1].node;
			if (Dep[u] < Dep[v]) swap(u, v);
			if (Dep[Fa[u]] <= Dep[v]) Ok[i] = 1;
				else Dp[u] ++, Dp[v] --;
		}
	DFS(0, 1);
	for (int i = 1; i <= m; i ++)
		cnt += Ok[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= m; i ++)
		if (Ok[i]) printf("%d ", i);
	puts("");
	return 0;
}