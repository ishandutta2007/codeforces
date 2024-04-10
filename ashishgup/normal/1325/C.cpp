#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int deg[N], ans[N];
vector<pair<int, int> > g[N];

int32_t main()
{
	IOS;
	memset(ans, -1, sizeof(ans));
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		deg[u]++;
		deg[v]++;
	}
	int val = 0;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 1)
		{
			for(auto &it:g[i])
			{
				if(ans[it.second] == -1)
					ans[it.second] = val++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(auto &it:g[i])
		{
			if(ans[it.second] == -1)
				ans[it.second] = val++;
		}
	}
	for(int i = 1; i <= n - 1; i++)
		cout << ans[i] << endl;
	return 0;
}