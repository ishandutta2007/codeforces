/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int n, m, ans;
vector<int> G[N];
int dp[N][2];
inline void dfs(int u, int f)
{
	dp[u][1] = 0, dp[u][0] = 0;
	for (auto v : G[u]) 	
		if(v != f)
		{
			dfs(v, u);
			ans = max(ans, dp[u][1] + dp[v][0] + 1);
			ans = max(ans, dp[u][0] + (int)G[u].size() - 2 + max(dp[v][0], dp[v][1]));
			dp[u][1] = max(dp[u][1], dp[v][0]);
			dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]));
		}
	dp[u][1]++;
	dp[u][0] += max(0ll, (int)G[u].size() - 2);
	ans = max(ans, dp[u][0]); ans = max(ans, dp[u][1]);
}
signed main()
{
	n = read();
	for (int i = 1; i < n; i++) 
	{
		int x = read(), y = read();
		G[x].push_back(y); G[y].push_back(x);
	}
	dfs(1, -1);
	cout << ans << endl;
	return 0;
}