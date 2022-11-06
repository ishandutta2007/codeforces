/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e6 + 9, mod = 1e9 + 7;
int n, m, now, dp[N], ans;
signed main()
{
	n = read(), m = read();
	dp[0] = 1, now = 0; ans = 1;
	for (int i = 1; i <= n; i++)
	{ 
		dp[i] = dp[i - 1] * (m * 2) % mod;
		dp[i] = (dp[i] - now + mod) % mod;
		now = (now * (m - 1) + dp[i - 1] * m % mod) % mod;
	//	cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
	return 0;
}