#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int subtree[N];
vector<int> g[N];

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
	if(subtree[k]%2==0&&k!=1)
	{
		ans++;
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
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n%2)
	{
		cout<<"-1";
		return 0;
	}
	dfs(1, 1);
	cout<<ans;
	return 0;
}