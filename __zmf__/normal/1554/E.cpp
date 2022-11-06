/*
	
	
	
	
	
	
 
	
	
	
										Naicissus
*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if(ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
		sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9, mod = 998244353;
int dp[N], n, T, ans[N];
// 0 fa 1 fa
vector<int> G[N];
inline void dfs(int u, int fa, int lim)
{
	int siz = G[u].size();
	int cnt = 0;
	bool flag = 0;
	for (int i = 0; i < siz; i++)
		if(G[u][i] != fa)
		{
			int v = G[u][i];
			dfs(v, u, lim);
			if(dp[v] == 0) cnt++;
			else if(dp[v] == -1) flag = 1;
		}
	if(flag)
	{
		dp[u] = -1;
		return ;
	}
	if(cnt % lim == 0) dp[u] = 0;
	else if((cnt + 1) % lim == 0) dp[u] = 1;
	else dp[u] = -1;
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		for (int i = 1; i <= n; i++) G[i].clear(), ans[i] = 0;
		for (int i = 1; i < n; i++)
		{
			int u = read(), v = read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i * i <= (n - 1); i++)
			if((n - 1) % i == 0)
			{
				for (int j = 1; j <= n; j++) dp[j] = -1;
				dfs (1, -1, (n - 1) / i);
				if(dp[1] == 0) ans[(n - 1) / i] = 1;
				if (i == 1) continue;
				for (int j = 1; j <= n; j++) dp[j] = -1;
				dfs (1, -1, i);
				if(dp[1] == 0) ans[i] = 1;
			}
		ans[1] = 1;
		for (int i = 1; i < n; i++) ans[1] = ans[1] * 2 % mod;
		for (int i = n; i >= 2; i--)
			if (ans[i])
			{
				ans[1] = (ans[1] - 1 + mod) % mod;
				for (int j = 1; j * j <= i; j++)
					if (i % j == 0 && j != 1)
					{
						ans[j] = 0;
						ans[i / j] = 0;
					}
			}
		for (int i = 1; i <= n; i++) printf("%lld ", ans[i] % mod);
		puts("");
	}
	return 0;
}