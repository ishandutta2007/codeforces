#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;
const int MOD=1e9+7;

int d, n;
int a[N];
vector<int> g[N];

int dfs(int k, int par, int idx)
{
	if(a[k]>a[idx] || a[k]<a[idx]-d || a[k]==a[idx] && k<idx)
		return 0;
	int ways=1;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		ways*=(1+dfs(it, k, idx));
		ways%=MOD;
	}
	return ways;
}

int32_t main()
{
	IOS;
	cin>>d>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=dfs(i, i, i);
	ans%=MOD;
	cout<<ans;
	return 0;
}