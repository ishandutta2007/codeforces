#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n, k;
int dp[N][2]; //0 = Parent not taken, 1 = Parent taken
vector<pair<int, int> > g[N];

void dfs(int u, int par)
{
	dp[u][0] = 0, dp[u][1] = 0;
	int sum = 0;
	vector<int> v;
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		dfs(it.first, u);
		sum += dp[it.first][0];
		int gain = dp[it.first][1] + it.second - dp[it.first][0];
		if(gain > 0)
			v.push_back(gain);
	}
	sort(v.rbegin(), v.rend());
	int sz = min(k - 1, (int)v.size());
	for(int i = 0; i < sz; i++)
		sum += v[i];
	dp[u][1] = sum;
	dp[u][0] = sum;
	if(sz < v.size())
		dp[u][0] += v[sz];
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		dfs(1, 0);
		cout << dp[1][0] << endl;
	}
	return 0;
}