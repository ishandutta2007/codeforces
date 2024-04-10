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
const int N = 5e3 + 9;
int LCP[N][N], n, a, b, dp[N];
char s[N];
signed main()
{
	n = read(), a = read(), b = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(s[i] == s[j]) LCP[i][j] = LCP[i - 1][j - 1] + 1;
			else LCP[i][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + a;
		for (int j = 1; j < i; j++) 
			if(LCP[i][j] != 0) dp[i] = min(dp[i], dp[max(i - LCP[i][j], j)] + b);
	} 
	cout << dp[n] << endl;
	return 0;
}