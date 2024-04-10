#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, s, t, lim, ans, Go[N][N], q[N], Dis[2][N];
bool Map[N][N];

void BFS(int st, int *dis)
{
	for (int i = 1; i <= n; i ++)
		dis[i] = n + 1;
	int l = 1, r = 0;
	q[++ r] = st, dis[st] = 0;
	while (l <= r)
	{
		int z = q[l ++];
		for (int i = 1; i <= Go[z][0]; i ++)
		{
			int d = Go[z][i];
			if (dis[d] > dis[z] + 1)
			{
				dis[d] = dis[z] + 1;
				q[++ r] = d;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Go[u][++ Go[u][0]] = v;
		Go[v][++ Go[v][0]] = u;
		Map[u][v] = Map[v][u] = 1;
	}
	BFS(s, Dis[0]), BFS(t, Dis[1]);
	lim = Dis[0][t];
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (!Map[i][j])
				if (Dis[0][i] + 1 + Dis[1][j] >= lim && Dis[1][i] + 1 + Dis[0][j] >= lim)
					ans ++;
	printf("%d\n", ans);
	return 0;
}