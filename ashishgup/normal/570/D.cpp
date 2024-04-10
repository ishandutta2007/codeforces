#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e5+5;
const int M=26;

int n, m;
int col[N], h[N], subtree[N], big[N], ans[N];
int f[26][N];
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
	f[col[v]][h[v]]+=x;
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
		int odd=0;
		for(int i=0;i<26;i++)
			odd+=(f[i][it.first])%2;
		ans[it.second]=(odd<=1);
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
	for(int i=2;i<=n;i++)
	{
		int u=i, v;
		cin>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		col[i]=ch-'a';
	}
	for(int i=1;i<=m;i++)
	{
		int u, h;
		cin>>u>>h;
		queries[u].push_back({h, i});
	}
	h[1]=1;
	getsz(1, 0);
	dfs(1, 0, 0);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"Yes":"No")<<endl;
	return 0;
}