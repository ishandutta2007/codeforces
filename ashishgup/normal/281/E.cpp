#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n;
double ans=1;
vector<int> g[N];

void dfs(int k, int par, int lvl)
{
	if(k!=1)
		ans+=1.0l/lvl;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
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
	dfs(1, 1, 1);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}