#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m;
int col[N], f[N], subtree[N], big[N], ans[N], bit[N];
vector<int> g[N];
vector<pair<int, int> > queries[N];

void update(int idx, int val)
{
	while(idx<N)
	{
		bit[idx]+=val;
		idx+=(idx&(-idx));
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}

int rsum(int L, int R)
{
	return pref(R) - pref(L-1);
}

void getsz(int v, int p)
{
	subtree[v]=1;
	for(auto u:g[v])
	{
		if(u==p)
			continue;
		getsz(u, v);
		subtree[v]+=subtree[u];
	}
}

void add(int v, int p, int x) 
{
	if(f[col[v]]>=1)
		update(f[col[v]], -1);
	f[col[v]]+=x;
	if(f[col[v]]>=1)
		update(f[col[v]], +1);
	for(auto u:g[v])
	{
		if(u!=p && !big[u])
			add(u, v, x);
	}
}

void computeans(int v)
{
	for(auto it:queries[v])
	{
		ans[it.second]=rsum(it.first, n);
	}
}

void dfs(int v, int p, int keep)
{
	int mx = -1, bigChild = -1;
	for(auto u:g[v])
	{
		if(u!=p && subtree[u]>mx)
			mx=subtree[u], bigChild=u;
	}
	for(auto u:g[v])
	{
		if(u!=p && u!=bigChild)
			dfs(u, v, 0); //Run DFS on small childs and clear them
	}
	if(bigChild!=-1)
	{
		dfs(bigChild, v, 1);
		big[bigChild]=1;
	}
	add(v, p, 1); 
	//Now we have the information of subtree of v
	computeans(v);
	if(bigChild!=-1)
		big[bigChild]=0;
	if(keep==0)
		add(v, p, -1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		int u, k;
		cin>>u>>k;
		queries[u].push_back({k, i});
	}
	getsz(1, 0);
	dfs(1, 0, 0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}