#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int n, m, cnt, Fa[N], Deg[N], Height[N], Size[N];
LL ans;
bool Flag[N];

inline int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		Fa[i] = i, Height[i] = 1;
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		if (u == v) cnt ++, Flag[u] = 1;
		else Deg[u] ++, Deg[v] ++;
		u = Find(u), v = Find(v);
		if (u == v) continue ;
		if (Height[u] < Height[v]) swap(u, v);
		Fa[v] = u, Height[u] = max(Height[u], Height[v] + 1);
	}
	int ret = 1;
	for (int i = 1; i <= n; i ++)
		Size[Find(i)] ++;
	for (int i = 1; i <= n; i ++)
		if (Size[i] > 1 || (Size[i] == 1 && Flag[i])) ret --;
	if (ret < 0) puts("0");
	else
	{
		for (int i = 1; i <= n; i ++)
			ans += 1LL * Deg[i] * (Deg[i] - 1) / 2;
		ans += 1LL * cnt * (m - cnt);
		ans += 1LL * cnt * (cnt - 1) / 2;
		printf("%I64d\n", ans);
	}
	return 0;
}