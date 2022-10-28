#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=2e5+5;

int n, node, stdist=0;
int a[N];
vector<int> g[N];

void dfs(int k, int par, int dist)
{
	if(dist>stdist)
	{
		node=k;
		stdist=dist;
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, dist+(a[k]^a[it]));
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	node=1;
	dfs(node, node, 0);
	dfs(node, node, 0);
	cout<<(stdist+1)/2;
	return 0;
}

//Logic is to merge from the center of the compressed tree.
//Neat implementation without using DSU to merge same colored components