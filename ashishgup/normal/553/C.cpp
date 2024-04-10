#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, m, connected=0;
int col[N], vis[N];
vector<pair<int, int> > g[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

void dfs(int k, int c)
{
	if(vis[k])
	{
		if(col[k]!=c)
		{
			cout<<"0";
			exit(0);
		}
		return;
	}
	vis[k]=1;
	col[k]=c;
	for(auto &it:g[k])
	{
		dfs(it.first, c^(1-it.second));
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v, t;
		cin>>u>>v>>t;
		g[u].push_back({v, t});
		g[v].push_back({u, t});
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i, 0);
			connected++;
		}
	}
	int ans=pow(2LL, connected-1, MOD);
	cout<<ans;
	return 0;
}