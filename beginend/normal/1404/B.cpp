#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a, b, da, db, mx, pos;
vector<int> e[N];

void dfs(int x, int fa, int d)
{
	if (d > mx) mx = d, pos = x;
	for (int to : e[x])
		if (to != fa) dfs(to, x, d + 1);
}

int get_dis(int x, int fa, int d)
{
	if (x == b) return d;
	for (int to : e[x]) if (to != fa)
	{
		int w = get_dis(to, x, d + 1);
		if (w) return w;
	}
	return 0;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for (int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			e[x].push_back(y); e[y].push_back(x);
		}
		mx = 0; pos = 0;
		dfs(1, 0, 0);
		int rt = pos; pos = mx = 0;
		dfs(rt, 0, 0);
		int dis = get_dis(a, 0, 0);
		if (da * 2 < db && da * 2 < mx && dis > da) puts("Bob");
		else puts("Alice");
		for (int i = 1; i <= n; i++) e[i].clear();
	}
	return 0;
}