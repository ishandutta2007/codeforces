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
const int N = 2e5 + 9, INF = 1e18;
int n, k;
int vis[N];
int dp[19][N][2][2];
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= k; i++) 
	{
		int x = read(); vis[x] = 1;
	}
	for (int i = 1; i <= n; i++) 	
		for (int j = 1; j <= (1 << n); j++)
			for (int k = 0; k < 2; k++)
				for (int s = 0; s < 2; s++)
					dp[i][j][k][s] = -INF;
	for (int i = 1; i <= (1 << n); i += 2) 
		dp[1][i][vis[i]][vis[i + 1]] = dp[1][i][vis[i + 1]][vis[i]] = (vis[i] | vis[i + 1]);
	for (int len = 2; len <= n; len++)
		for (int i = 1; i <= (1 << n); i += (1 << len))
		{
			int j = i + (1 << (len - 1));
			for (int w1 = 0; w1 < 2; w1++)
				for (int w2 = 0; w2 < 2; w2++)
					for (int l1 = 0; l1 < 2; l1++)
						for (int l2 = 0; l2 < 2; l2++)
						{
							int pp = (l1 | l2 | w2);
							dp[len][i][w1][pp] = max(dp[len][i][w1][pp], dp[len - 1][i][w1][l1] + dp[len - 1][j][w2][l2] + (w1 | w2) + (l1 | l2) + pp);
							pp = (l1 | l2 | w1);
							dp[len][i][w2][pp] = max(dp[len][i][w2][pp], dp[len - 1][i][w1][l1] + dp[len - 1][j][w2][l2] + (w1 | w2) + (l1 | l2) + pp);
						}
		}
	int ans = 0;
	for (int w = 0; w < 2; w++)
		for (int l = 0; l < 2; l++)
			ans = max(ans, dp[n][1][w][l] + (w | l));
	cout << ans << endl;
	return 0;
}