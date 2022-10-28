#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;
const int M = 3e5 + 5;
 
int n, m, node=1, maxdist;
int tim=0, grp=1;
int u[N], v[N], z[N], comp[N], mark[N];
bool vis[N], vis2[N], isBridge[M];
int tin[N], tout[N], minAncestor[N];
queue<int> Q[N];
vector<pair<int, int> > g[N];
vector<pair<int, int> > tree[N];
int store[N];
int src, dest;

void dfs(int k, int par)
{
	vis[k]=1;
	tin[k]=++tim;
	minAncestor[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{	
			minAncestor[k]=min(minAncestor[k], tin[it.first]);
			continue;
		}
		dfs(it.first, k);
		minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
		if(minAncestor[it.first]>tin[k])
			isBridge[it.second]=1;
	}
	tout[k]=tim;
}
 
void dfs2(int k)
{
	int comp=grp;
	Q[comp].push(k);
	vis2[k] = 1;
	while(!Q[comp].empty())
	{
		int u=Q[comp].front();
		Q[comp].pop();
		store[u] = comp;
		for(auto it:g[u])
		{
			int v=it.first;
			int edgeidx=it.second;
			if(vis2[v])
				continue;
			if(isBridge[edgeidx])
			{
				grp++;
				tree[comp].push_back({grp, z[edgeidx]});
				tree[grp].push_back({comp, z[edgeidx]});
				dfs2(v);
			}
			else
			{
				Q[comp].push(v);
				vis2[v]=1;
			}
		}
	}
}

bool vis3[N][2];

void dfs3(int u, int par, int x)
{	
	if(vis3[u][x])
		return;
	x |= mark[u];
	vis3[u][x] = 1;
	for(auto &it:tree[u])
	{
		if(it.first == par)
			continue;
		dfs3(it.first, u, x | (it.second));
	}
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> z[i];
		g[u[i]].push_back({v[i], i});
		g[v[i]].push_back({u[i], i});
	}
	dfs(1, 0);
	dfs2(1);
	for(int i = 1; i <= m; i++)
	{
		if(store[u[i]] == store[v[i]] && z[i])
			mark[store[u[i]]] = 1;
	}
	cin >> src >> dest;
	dfs3(store[src], store[src], mark[store[src]]);
	if(vis3[store[dest]][1])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}