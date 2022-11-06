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
    while (ch > '9'||ch < '0')
    {
        if (ch == '-') nega = -1;
        ch = getchar();
    }
    while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
    return sum * nega;
}
const int mod = 998244353, N = 2e5 + 9;
vector<int> G[N];
int dp[N][3], n;
int tmp[3];
inline void dfs(int u)
{
	if(G[u].size() == 0) dp[u][2] = 1;
	else dp[u][0] = 1;
	for (auto v : G[u])
	{
		dfs(v);
		tmp[0] = dp[u][0], tmp[1] = dp[u][1], tmp[2] = dp[u][2];
		dp[u][0] = tmp[0] * (dp[v][0] + dp[v][2]) % mod;
		dp[u][1] = (tmp[1] * (dp[v][0] + dp[v][2]) % mod + tmp[0] * (dp[v][1] + dp[v][2]) % mod) % mod;
		dp[u][2] = (tmp[2] * (dp[v][0] + dp[v][1] + 2 * dp[v][2]) % mod + tmp[1] * (dp[v][1] + dp[v][2]) % mod) % mod;
	}
}
signed main()
{
	n = read();
	for (int i = 2; i <= n; i++)
	{
		int x = read();
		G[x].push_back(i);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][2]) % mod << endl;
	return 0;
}
/*
5
1 1 1 1
*/