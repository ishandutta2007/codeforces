#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;
const int LG=log2(N) + 2;

int n, v1=1, v2=2, mdist=1;
int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N];
vector<int> g[N];

void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
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
	return level[u] + level[v] - 2*level[LCA(u, v)];
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int v;
		cin>>v;
		int u=i;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 1);
	precompute();
	cout<<1<<" ";
	for(int i=3;i<=n;i++)
	{
		int d1=dist(v1, i);
		int d2=dist(i, v2);
		if(d1>mdist)
		{
			mdist=d1;
			v2=i;
		}
		if(d2>mdist)
		{
			mdist=d2;
			v1=i;
		}
		cout<<mdist<<" ";
	}
	return 0;
}