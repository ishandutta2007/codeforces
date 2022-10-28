#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, nodes;
int subtree[N];
char ans[N];
set<int> g[N];

void dfs(int k, int parent)
{
	nodes++;
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		dfs(it,k);
		subtree[k]+=subtree[it];
	}
}

int centroid(int k, int parent)
{
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		if(subtree[it]>(nodes>>1))
			return centroid(it,k);
	}
	return k;
}

void decompose(int k, char ch)
{
	nodes=0;
	dfs(k, k);
	int node=centroid(k, k);
	ans[node]=ch;
	for(auto it:g[node])
	{
		g[it].erase(node);
		decompose(it, ch+1);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	decompose(1,'A');
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}