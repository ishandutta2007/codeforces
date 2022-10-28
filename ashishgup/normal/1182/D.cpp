#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int farthest = 0, leafDist = -1;
int deg[N], degree[N], store[N], store2[N];
set<int> level[N];
vector<int> g[N];

void dfs(int u, int par, int lvl)
{
	level[lvl].insert(degree[u]);
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, lvl + 1);
	}
}

void dfs2(int u, int par, int dist)
{
	if(dist > leafDist)
	{
		leafDist = dist;
		farthest = u;
	}
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs2(it, u, dist + 1);
	}
}

void dfs3(int u, int par, int lvl)
{
	store[u] = lvl;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs3(it, u, lvl + 1);
	}
}

void dfs4(int u, int par, int lvl)
{
	store2[u] = lvl;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs4(it, u, lvl + 1);
	}
}

bool check(int u)
{
	for(int i = 1; i <= n; i++)
		level[i].clear();
	dfs(u, u, 1);
	for(int i = 1; i <= n; i++)
		if(level[i].size() > 1)
			return 0;
	cout << u;
	exit(0);
}

bool nonLeaf()
{
	for(int i = 1; i <= n; i++)
		deg[i] = degree[i];
	set<int> s;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 1)
			s.insert(i);
	}
	while(s.size() > 1)
	{
		if(deg[*s.begin()] == 0)
			break;
		vector<int> toInsert;
		for(auto&it:s)
		{
			for(auto &j:g[it])
			{
				deg[j]--;
				if(deg[j] == 1)
					toInsert.push_back(j);
			}
		}
		s.clear();
		for(auto &it:toInsert)
			s.insert(it);

	}
	if(!s.size())
		return 0;
	check(*s.begin());
}

set<int> distances;
map<int, vector<int> > v;

void dfs5(int u, int par, int lvl)
{
	int isLeaf = 1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		isLeaf = 0;
		dfs5(it, u, lvl + 1);
	}
	if(isLeaf)
	{
		v[lvl].push_back(u);
		distances.insert(lvl);
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		degree[u]++, degree[v]++;
	}
	nonLeaf();
	int node = 1;
	for(int i = 1; i <= n; i++)
	{
		if(degree[i] == 1)
		{
			check(i);
			node = i;
			break;
		}
	}
	dfs2(node, node, 0);
	check(farthest);
	if(leafDist % 2)
	{
		cout << "-1";
		exit(0);
	}		
	dfs3(node, node, 0);
	dfs4(farthest, farthest, 0);
	node = 1;
	for(int i = 1; i <= n; i++)
	{
		if(store[i] == leafDist / 2 && store2[i] == leafDist / 2)
			node = i;
	}
	dfs5(node, node, 0);
	if(distances.size() > 2)
	{
		cout << "-1";
		exit(0);
	}
	for(auto &it:v)
	{
		if(it.second.size() == 1)
		{
			check(it.second[0]);
		}
	}
	cout << "-1";
	return 0;
}