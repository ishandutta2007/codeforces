#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, k, Dis[N], Fa[N];
vector <int> Vec[N];

void dfs(int z, int fa, int dep)
{
	Dis[z] = dep, Fa[z] = fa;
	for (int d : Vec[z])
		if (d != fa)
			dfs(d, z, dep + 1);
}

int FindCenter()
{
	dfs(1, 0, 0);
	int Max = 0;
	for (int i = 1; i <= n; i ++)
		if (!Max || Dis[i] > Dis[Max])
			Max = i;
	dfs(Max, 0, 0);
	Max = 0;
	for (int i = 1; i <= n; i ++)
		if (!Max || Dis[i] > Dis[Max])
			Max = i;
	int d = Dis[Max], rt = Max;
	if (d & 1) return -1;
	for (int r = d >> 1; r; r --)
		rt = Fa[rt];
	return rt;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	int rt = FindCenter();
	if (!~rt) puts("No");
	else
	{
		dfs(rt, 0, 0);
		int Max = 0;
		for (int i = 1; i <= n; i ++)
			if (!Max || Dis[i] > Dis[Max])
				Max = i;
		bool ok = (Dis[Max] == k);
		for (int i = 1; ok && i <= n; i ++)
			if (Dis[i] < Dis[Max] && ((i != rt && Vec[i].size() <= 3) || (i == rt && Vec[i].size() <= 2)))
				ok = false;
		puts(ok ? "Yes" : "No");
	}
	return 0;
}