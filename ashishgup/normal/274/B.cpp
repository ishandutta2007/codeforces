#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], add[N], subtract[N];
vector<int> g[N];

void dfs(int k, int par)
{
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		add[k]=max(add[k], add[it]);
		subtract[k]=max(subtract[k], subtract[it]);
	}
	a[k]-=add[k];
	a[k]+=subtract[k];
	add[k]+=max(0LL, a[k]);
	subtract[k]+=max(0LL, -1*a[k]);
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
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1, 1);
	cout<<add[1]+subtract[1];
	return 0;
}