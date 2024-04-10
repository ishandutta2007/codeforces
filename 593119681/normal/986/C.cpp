#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 8388608 + 5

int n, m, sz, ans, tot, Head[N];
bool Flag[N];

struct Edge
{
	int next, node;
}h[N];

void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

void dfs(int z)
{
	if (Flag[z]) return ;
	Flag[z] = 1;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		dfs(d);
	}
	if (z >= m)
	{
		int x = z - m;
		for (int d = 0; d < n; d ++)
			if ((x >> d) & 1)
				dfs(m + x - (1 << d));
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	sz = (1 << n) - 1;
	for (int i = 0, x; i < m; i ++)
	{
		scanf("%d", &x);
		addedge(m + x, i);
		addedge(i, m + (sz - x));
	}
	for (int i = 0; i < m; i ++)
		if (!Flag[i])
		{
			ans ++;
			dfs(i);
		}
	printf("%d\n", ans);
	return 0;
}