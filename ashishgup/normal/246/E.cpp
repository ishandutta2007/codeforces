#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, m;
int h[N], subtree[N], big[N], ans[N];
string name[N];
map<string, int> store[N];
vector<int> g[N];
vector<pair<int, int> > queries[N];

void getsz(int v, int p)
{
	subtree[v]=1;
	for(auto u:g[v])
	{
		if(u==p)
			continue;
		h[u]=h[v]+1;
		getsz(u, v);
		subtree[v]+=subtree[u];
	}
}

void add(int v, int p, int x) 
{
	store[h[v]][name[v]]+=x;
	if(store[h[v]][name[v]]==0)
		store[h[v]].erase(name[v]);
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
		ans[it.second]=store[it.first+h[v]].size();
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u=i, v;
		cin>>name[i]>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int u, k;
		cin>>u>>k;
		queries[u].push_back({k, i});
	}
	h[0]=0;
	getsz(0, 0);
	dfs(0, 0, 0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}