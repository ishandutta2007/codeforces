#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[600001];
int ecnt = 0, head[300001];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int dfn_cnt, dfn[300001], low[300001];
int scc_cnt, scc[300001], sz[300001];
bool ins[300001];
stack<int> stk;
void dfs(int u, int fa)
{
	dfn[u] = low[u] = ++dfn_cnt;
	stk.push(u);
	ins[u] = true;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		// if(v == fa)
		// 	continue;
		if(!dfn[v])
			dfs(v, u);
		if(ins[v])
			low[u] = min(low[u], low[v]);
	}
	if(low[u] == dfn[u])
	{
		int p = 0;
		++scc_cnt;
		while(p != u)
		{
			p = stk.top();
			ins[p] = false;
			stk.pop();
			scc[p] = scc_cnt;
			sz[scc_cnt]++;
		}
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
		for(int i = 1; i <= n; i++)
			head[i] = -1, dfn[i] = 0, sz[i] = 0;
		ecnt = 0;
		string s;
		cin >> s;
		for(int i = 1; i <= n; i++)
			if(s[i - 1] == '>')
				addedge(i, i % n + 1);
			else if(s[i - 1] == '<')
				addedge(i % n + 1, i);
			else
				addedge(i, i % n + 1), addedge(i % n + 1, i);
		dfn_cnt = scc_cnt = 0;
		for(int i = 1; i <= n; i++)
			if(!dfn[i])
				dfs(i, 0);
		int ans = 0;
		for(int i = 1; i <= scc_cnt; i++)
			if(sz[i] > 1)
				ans += sz[i];
		printf("%d\n", ans);
	}
	return 0;
}