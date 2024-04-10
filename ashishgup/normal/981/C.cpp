#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, node;
int deg[N], subtree[N];
vector<int> g[N];
vector<int> leaves;

void dfs(int k, int par)
{
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
	if(k!=node && g[k].size()>=3)
	{
		cout<<"No";
		exit(0);
	}
	if(subtree[k]==1)   
		leaves.push_back(k);
}

int32_t main()
{
	IOS;
	cin>>n;
	int maxdeg=0;
	node=1;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
		if(deg[u]>maxdeg)
		{
			maxdeg=deg[u];
			node=u;
		}
		if(deg[v]>maxdeg)
		{
			maxdeg=deg[v];
			node=v;
		}
	}
	dfs(node, node);
	cout<<"Yes"<<endl;
	cout<<leaves.size()<<endl;
	for(auto it:leaves)
		cout<<node<<" "<<it<<endl;
	return 0;
}