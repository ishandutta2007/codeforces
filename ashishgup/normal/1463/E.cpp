#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 3e5 + 5;

int n, k;
int p[N];
vector<int> g[N], g2[N], store[N];
int vis[N];

bool findLoop(int v) 
{
	if(vis[v] == 1)
		return 1;
	if(vis[v] == 2)
		return 0;
	vis[v] = 1;
	for(auto &it:g[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v] = 2;
	return 0;
}

bool checkLoop()
{
	fill(vis + 1, vis + n + 1, 0);
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i] && findLoop(i))
			return 1;
	}
	return 0;
}

int cur = 0;
int comp[N];

void dfs(int u)
{
	assert(vis[u] == 0);
	if(vis[u])
		return;
	vis[u] = 1;
	store[cur].push_back(u);
	comp[u] = cur;
	for(auto &it:g2[u])
		dfs(it);
}

set<int> ng[N];
vector<int> order; //Stores the Topological Order

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}

int out[N], in[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
		if(p[i] != 0)
			g[p[i]].push_back(i);
	}
	for(int i = 1; i <= k; i++)
	{
		int u, v;
		cin >> u >> v;
		in[v]++;
		g[u].push_back(v);
		g2[u].push_back(v);
	}
	if(checkLoop())
	{
		cout << 0;
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] || in[i])
			continue;
		cur++;
		dfs(i);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!p[i])
			continue;
		int comp1 = comp[p[i]];
		int comp2 = comp[i];
		if(comp1 != comp2)
			ng[comp1].insert(comp2);
	}
	for(int i = 1; i <= n; i++)
		g[i].clear();
	for(int i = 1; i <= n; i++)
	{
		for(auto &it:ng[i])
			g[i].push_back(it);
	}
	if(checkLoop())
	{
		cout << 0;
		return 0;
	}
	if(!toposort(cur))
	{
		cout << 0;
		return 0;
	}
	for(auto &it:order)
	{
		for(auto &v:store[it])
			cout << v << " ";
	}
	cout << endl;
	return 0;
}