#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int col[N], cnt[N], f[N], subtree[N], big[N], ans[N];
vector<int> g[N];
multiset<int> active;

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
	active.erase(cnt[col[v]]);
	f[cnt[col[v]]]-=col[v];
	cnt[col[v]]+=x;
	active.insert(cnt[col[v]]);
	f[cnt[col[v]]]+=col[v];
	for(auto u:g[v])
	{
		if(u!=p && !big[u])
			add(u, v, x);
	}
}

void computeans(int v)
{
	int maxf=*(--active.end());
	ans[v]=f[maxf];
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
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	getsz(1, 0);
	dfs(1, 0, 0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}