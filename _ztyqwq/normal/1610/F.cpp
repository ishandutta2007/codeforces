#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
	bool banned;
}e[2][200010];
int ecnt = 0, head[2][100010];
bool col[100010];
inline void addedge(int from, int to, int val)
{
	e[val][ecnt].to = to;
	e[val][ecnt].nxt = head[val][from];
	e[val][ecnt].banned = false;
	head[val][from] = ecnt++;
}
int nxt[2][100010], bnd[200010];
int cur[2][100010], deg[2][100010];
bool vis[2][100010];
int dfs(int u, int op, vector<int> &vec)
{
	for(int &i = cur[op][u]; i != -1; i = e[op][i].nxt)
	{
		if(e[op][i].banned)
			continue;
		e[op][i].banned = true;
		e[op][i ^ 1].banned = true;
		vec.push_back(i);
		int v = e[op][i].to;
		deg[op][u]--, deg[op][v]--;
		return dfs(e[op][i].to, op, vec);
	}
	return u;
}
int d[100010];
int ans[100010];
inline void Work(int u, int w)
{
	vector<int> vec;
	int v = dfs(u, w, vec);
	if(u != v)
	{
		nxt[w][u] = v, nxt[w][v] = u;
		d[u]++, d[v]++;
		for(auto x: vec)
			bnd[(x >> 1) + 1] = (x & 1) ? v : u;
	}
	else
		for(auto x: vec)
			ans[(x >> 1) + 1] = (x & 1);
}
inline void Work2(int u)
{
	int op = bool(nxt[1][u]);
	while(d[u])
	{
		int v = nxt[op][u];
		vis[op][u] = true;
		d[u]--, d[v]--;
		op = !op, u = v;
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	memset(ans, -1, sizeof(ans));
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		col[i] = w = 2 - w;
		addedge(u, v, w);
		addedge(v, u, w);
		deg[w][u]++, deg[w][v]++;
	}
	for(int j = 0; j <= 1; j++)
		for(int i = 1; i <= n; i++)
			cur[j][i] = head[j][i];
	int tot = 0;
	for(int i = 1; i <= n; i++)
		tot += (deg[1][i] & 1);
	for(int j = 0; j <= 1; j++)
		for(int i = 1; i <= n; i++)
			if(deg[j][i] & 1)
				Work(i, j);
	for(int j = 0; j <= 1; j++)
		for(int i = 1; i <= n; i++)
			if(deg[j][i])
				Work(i, j);
	for(int i = 1; i <= n; i++)
		if(d[i] == 1)
			Work2(i);
	for(int i = 1; i <= n; i++)
		if(d[i])
			Work2(i);
	for(int i = 1; i <= m; i++)
		if(ans[i] == -1)
			ans[i] = vis[col[i]][bnd[i]];
	printf("%d\n", tot);
	for(int i = 1; i <= m; i++)
		putchar(ans[i] + '1');
	putchar('\n');
	return 0;
}