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
const int N = 2009, mod = 1e9 + 7;
int dp[N][N], inv = (mod + 1) / 2;
inline void solve()
{
	int n = read(), m = read(), k = read();
	printf("%lld\n", dp[n][m] * k % mod);
}
inline void init()
{
	int x = 2000;
	dp[1][1] = 1, dp[1][0] = 0;
	for (int i = 1; i <= x; i++) dp[i][0] = 0;
	for (int i = 1; i <= x; i++) dp[i][i] = i;
	for (int i = 2; i <= x; i++) 
		for (int j = 1; j < i; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) * inv % mod;
}
signed main()
{
	int T = read();
	init();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}