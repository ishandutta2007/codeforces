#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, val = 0;
int a[N], isSet[N];
int dp[N][2];
vector<int> g[N];

void dfs(int u, int par)
{
	int bit = isSet[u];
	dp[u][bit] = 1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u);
		val += dp[it][0] * dp[u][1] + dp[it][1] * dp[u][0];
		dp[u][bit] += dp[it][0];
		dp[u][!bit] += dp[it][1];
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < 20; i++)
	{
		val = 0;
		for(int j = 1; j <= n; j++)
		{
			dp[j][0] = dp[j][1] = 0;
			isSet[j] = (a[j] >> i) & 1;
		}
		dfs(1, 0);
		ans += (1LL << i) * val;
	}
	cout << ans;
	return 0;
}