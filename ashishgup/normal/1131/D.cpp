#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2010;

struct DSU
{
	int connected;
	int par[N], sz[N];

	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

int n, m;
int val[N], vis[N], vis2[N];
char a[N][N];
vector<int> g[N];
DSU dsu;

bool findLoop(int v) 
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v]=2;
	return 0;
}

bool checkLoop()
{
	fill(vis+1, vis+n+1, 0);
	for(int i=1;i<=n+m;i++)
	{
		if(!vis[i] && findLoop(i))
			return 1;
	}
	return 0;
}

void dfs(int u)
{
	if(vis2[u])
		return;
	vis2[u]=1;
	for(auto &it:g[u])
		dfs(it);
	val[u]=1;
	for(auto &it:g[u])
		val[u]=max(val[u], val[it] + 1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	dsu.init(n+m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='=')
			{
				dsu.unite(i, j+n);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='>')
				g[dsu.getPar(i)].push_back(dsu.getPar(j+n));
			if(a[i][j]=='<')
				g[dsu.getPar(j+n)].push_back(dsu.getPar(i));
		}
	}
	if(checkLoop())
	{
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=n+m;i++)
		dfs(i);
	cout<<"Yes"<<endl;
	for(int i=1;i<=n+m;i++)
	{
		cout<<val[dsu.getPar(i)]<<" ";
		if(i==n)
			cout<<endl;
	}
	cout<<endl;
	return 0;
}