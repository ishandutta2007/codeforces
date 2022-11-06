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
const int N = 2e5 + 9;
int n, m, q, ans;
int f, e;
map<int, int> mp;
inline int id(int x, int y) 
{
	return (x - 1) * m + y;
}
int dp[2][N];
signed main()
{
	int flag = 0;
	n = read(); m = read(); q = read();
	if(n > m) swap(n, m), flag = 1;
	for (int i = 1; i <= q; i++)
	{
		int x = read(), y = read();
		if(flag) swap(x, y);
		mp[id(x, y)] = 1;
	}
	dp[0][1] = 1;
	//dp[i][j] step = i, x = j
	for (int i = 2; i <= n; i++) dp[0][i] = -1e9;
	for (int i = 1; i; i++)
	{
		int lst = (i & 1) ^ 1, now = (i & 1);
		for (int j = 1; j <= n; j++) 
			if(dp[lst][j] != 0) dp[now][j] = max(dp[now][j], min(m, dp[lst][j] + j + mp[id(j, dp[lst][j])]));	 
		for (int j = 1; j <= n; j++)
		{
			int v = min(n, dp[lst][j] + j + mp[id(j, dp[lst][j])]);
			if(v < 1) continue;
			dp[now][v] = max(dp[now][v], dp[lst][j]);
		}
		/*for (int j = 1; j <= n; j++)
			if(i <= 10) cout << dp[now][j] << " ";
		if(i <= 10) puts(""); */
		if(dp[now][n] == m) 
		{
			cout << i << endl; return 0;
		}
	}
	return 0;
}