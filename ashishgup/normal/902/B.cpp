#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int c[N];
vector<int> g[N];

void dfs(int k, int col, int par)
{
	if(col!=c[k])
		ans++;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, c[k], k);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int u=i;
		int v;
		cin>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1, 0, 0);
	cout<<ans;
	return 0;
}