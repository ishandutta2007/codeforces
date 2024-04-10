#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[400010];
int ecnt = 0, head[200010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int fa[200010];
int hi[200010], badnum[200010], son[200010];
void dfs(int u)
{
	hi[u] = badnum[u] = son[u] = 0;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa[u])
			continue;
		fa[v] = u;
		son[u]++;
		dfs(v);
		if(hi[v] >= 1)
			badnum[u]++;
		hi[u] = max(hi[u], hi[v]);
	}
	hi[u] += bool(son[u]);
}
queue<int> q;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			head[i] = -1;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		fa[1] = 0;
		dfs(1);
		for(int i = 1; i <= n; i++)
			if(hi[i] == 1 && i != 1)
				q.push(i);
		int ans = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			int cnt = 0;
			for(int i = head[u]; i != -1; i = e[i].nxt)
			{
				int v = e[i].to;
				if(v != fa[u] && hi[v] >= 0)
					hi[v] = -1, cnt++;
			}
			hi[u] = -1;
			ans += cnt - 1;
			int f = fa[u];
			son[f]--, badnum[f]--;
			if(son[f] == 0 && f != 1)
			{
				badnum[fa[f]]--;
				if(badnum[fa[f]] == 0 && fa[f] != 1)
					q.push(fa[f]);
			}
			else if(badnum[f] == 0 && f != 1)
				q.push(f);
		}
		int tot = 0;
		for(int i = 2; i <= n; i++)
			if(hi[i] >= 0)
				tot++;
		printf("%d\n", ans + max(tot, 1));
	}
	return 0;
}