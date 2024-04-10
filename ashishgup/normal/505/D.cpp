#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
vector<int> undirG[N];

int grp = 0;
vector<int> g[N], newg[N], rg[N], todo;
int comp[N], indeg[N], sz[N];
bool vis[N];
set<int> gr[N];

void dfs(int u)
{
	vis[u] = 1;
	for(auto &it:g[u])
	{
		if(!vis[it])
			dfs(it);
	}
	todo.push_back(u);
}

void dfs2(int u, int val)
{
	comp[u] = val;
	sz[val]++;
	for(auto &it:rg[u])
	{
		if(comp[it] == -1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(int i = 1; i <= n; i++)
		comp[i] = -1;

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(todo.begin(), todo.end());

	for(auto &it:todo)
	{
		if(comp[it] == -1)
			dfs2(it, ++grp);
	}

	/*Uncomment if SCC Tree is reqd

	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			if(comp[i] != comp[it])
				gr[i].insert(it);

	*/
}

int vertices = 0, check = 0;

void dfs0(int u)
{
	if(vis[u])
		return;
	vis[u] = 1;
	check |= (sz[comp[u]] > 1);
	vertices++;
	for(auto &it:undirG[u])
		dfs0(it);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		sccAddEdge(u, v);
		undirG[u].push_back(v);
		undirG[v].push_back(u);
	}
	scc();
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
			continue;
		check = 0;
		vertices = 0;
		dfs0(i);
		if(check)
			ans += vertices;
		else
			ans += vertices - 1;
	}
	cout << ans;
	return 0;   
}