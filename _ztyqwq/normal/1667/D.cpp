#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[400010];
int ecnt = 0, head[200010];
bool vis[400010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	vis[ecnt] = false;
	head[from] = ecnt++;
}
int d[200010];
vector< pair<int, int> > ans;
inline void dfs(int u, int fa)
{
	vector< pair<int, int> > vec[2];
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa || vis[i])
			continue;
		dfs(v, u);
		vec[d[v]].push_back({v, i});
	}
	while(!vec[d[u]].empty())
	{
		auto p = vec[d[u]].back();
		int v = p.first, i = p.second;
		while(vis[i])
		{
			vec[d[u]].pop_back();
			p = vec[d[u]].back(), v = p.first, i = p.second;
		}
		vec[d[u]].pop_back();
		d[u] ^= 1, d[v] ^= 1;
		vis[i] = vis[i ^ 1] = true;
		ans.push_back({u, v});
		dfs(v, u);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		ecnt = 0;
		for(int i = 1; i <= n; i++)
			head[i] = -1, d[i] = 0;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v), addedge(v, u);
			d[u] ^= 1, d[v] ^= 1;
		}
		ans.clear();
		dfs(1, 1);
		if(ans.size() == n - 1)
		{
			printf("YES\n");
			for(auto p: ans)
				printf("%d %d\n", p.first, p.second);
		}
		else
			printf("NO\n");
	}
	return 0;
}