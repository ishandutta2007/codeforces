#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int LG=19;

int n, q, nodes;
int level[N], parent[LG][N], subtree[N], parentcentroid[N], closestred[N];
set<int> g[N];

void dfs1(int k, int par, int lvl)
{
	parent[0][k]=par;
	level[k]=lvl;
	closestred[k]=1e6;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs1(it, k, lvl+1);
	}
}

void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
		}
	}
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
	{
		swap(u,v);
	}
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if(diff & (1<<i))
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

int distance(int u, int v)
{
	return level[u] + level[v] - 2*level[LCA(u, v)];
}

void dfs(int k, int par)
{
	nodes++;
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
}

int centroid(int k, int par)
{
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		if(subtree[it]>(nodes>>1))
		{
			return centroid(it, k);
		}
	}
	return k;
}

void decompose(int k, int par)
{
	nodes=0;
	dfs(k, k);
	int node=centroid(k, k);
	parentcentroid[node]=par;
	for(auto it:g[node])
	{
		g[it].erase(node);
		decompose(it, node);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	dfs1(1, 1, 1);
	precompute();
	decompose(1, 0);
	closestred[1]=0;
	for(int i=2;i<=n;i++)
	{
		closestred[i]=distance(i, 1);
	}
	for(int i=1;i<=q;i++)
	{
		int t,x;
		cin>>t>>x;
		if(t==1)
		{
			int cur=x;
			while(cur!=0)
			{
				closestred[cur]=min(closestred[cur], distance(x, cur));
				cur=parentcentroid[cur];
			}
		}
		else
		{
			int cur=x;
			int ans=INT_MAX;
			while(cur!=0)
			{
				ans=min(ans, closestred[cur] + distance(x, cur));
				cur=parentcentroid[cur];
			}
			cout<<ans<<endl;
		}
	}
}