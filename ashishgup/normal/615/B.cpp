#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0;
int dp[N], deg[N];
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		deg[u]++, deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto &it:g[i])
		{
			if(it<i)
				continue;
			dp[it]=max(dp[it], dp[i]+1);
		}
		ans=max(ans, dp[i]*deg[i]);
	}
	cout<<ans;
	return 0;
}