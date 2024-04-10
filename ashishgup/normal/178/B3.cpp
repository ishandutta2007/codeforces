#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int M=1e5+5;
const int LG=19;

int n, m;
int tim=0, grp=1;
int u[N], v[N], storecomp[N], level[N];
bool vis[N], vis2[N], isBridge[M];
int tin[N], tout[N], minAncestor[N];
queue<int> Q[N];
vector<pair<int, int> > g[N];
vector<int> tree[N], vertices[N]; //Tree stores Bridge Tree, vertices stores the nodes in each component 
int parent[LG][N];

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
	vis2[k]=1;
	while(!Q[comp].empty())
	{
		int u=Q[comp].front();
		Q[comp].pop();
		vertices[comp].push_back(u);
		storecomp[u]=comp;
		for(auto it:g[u])
		{
			int v=it.first;
			int edgeidx=it.second;
			if(vis2[v])
				continue;
			if(isBridge[edgeidx])
			{
				grp++;
				tree[comp].push_back(grp);
				tree[grp].push_back(comp);
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

void dfs3(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:tree[k])
	{
		if(it==par)
			continue;
		dfs3(it, k, lvl+1);
	}
	tout[k]=tim;
}

void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		g[u[i]].push_back({v[i], i});
		g[v[i]].push_back({u[i], i});
	}
	dfs(1, 0);
	dfs2(1);
	tim=0;
	dfs3(1, 1, 1);
	precompute();
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int u, v;
		cin>>u>>v;
		cout<<dist(storecomp[u], storecomp[v])<<endl;
	}
	return 0;
}