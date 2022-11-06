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
const int N = 2009, mod = 998244353;
int dp[N][N], v[N][N], n;
char s[N];
signed main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) 
	{
		dp[i][i] = 0; v[i][i - 1] = 1;
		v[i][i] = 1; 
		if(s[i] == '?') v[i][i] = 2;
	}
	for (int len = 2; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			if(s[j] == '?') v[i][j] = v[i][j - 1] * 2ll % mod;
			else v[i][j] = v[i][j - 1];
			if(s[i] != ')' && s[j] != '(') dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] + v[i + 1][j - 1]) % mod;
			if(s[j] != ')') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			if(s[i] != '(') dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
			if(s[i] != '(' && s[j] != ')') dp[i][j] = (dp[i][j] - dp[i + 1][j - 1] + mod) % mod;
		//	cout << i << " " << j << " " << dp[i][j] << " " << v[i + 1][j - 1] << endl;
		}
	cout << dp[1][n] << endl;
	return 0;
}