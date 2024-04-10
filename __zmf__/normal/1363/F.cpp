/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
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
const int N = 2009, INF = 1e9;
int T, n, dp[N][N], ans, tot[N], cnt1[N][N], cnt2[N][N];
char s[N], t[N];
inline void solve()
{
	n = read();
	scanf("%s", s + 1), scanf("%s", t + 1);
	for (int i = 1; i <= n; i++)
	{	
		for (int j = 'a'; j <= 'z'; j++) 
			tot[i] = 0, cnt1[i][j] = cnt1[i - 1][j], cnt2[i][j] = cnt2[i - 1][j];
		cnt1[i][s[i]]++; cnt2[i][t[i]]++;
	}
	for (int i = 'a'; i <= 'z'; i++) tot[i] = 0;
	for (int i = 1; i <= n; i++) tot[s[i]]++;
	for (int i = 1; i <= n; i++) tot[t[i]]--;
	for (int i = 'a'; i <= 'z'; i++)
		if(tot[i] != 0)
		{
			puts("-1"); return ;
		}
	
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + 1;
			if(s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			if(cnt1[i][t[j]] < cnt2[j][t[j]]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	printf("%lld\n", dp[n][n]);
}
signed main()
{ 
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;	
}