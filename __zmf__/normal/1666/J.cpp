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
const int N = 209, INF = 1e17;
int n, c[N][N], v[N][N], sum[N][N];
int dp[N][N], fa[N], t[N][N];
inline void dfs(int l, int r, int f) 
{
	fa[t[l][r]] = f;
	if(l >= r) return ;
	dfs(l, t[l][r] - 1, t[l][r]);
	dfs(t[l][r] + 1, r, t[l][r]);
	return ;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			c[i][j] = read(), sum[i][j] = sum[i][j - 1] + c[i][j], dp[i][j] = INF;
	for (int i = 1; i <= n + 1; i++) dp[i][i] = 0, dp[i][i - 1] = 0, t[i][i] = i;
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
			for (int i = l; i <= r; i++) v[l][r] += (sum[i][n]), v[l][r] -= (sum[i][r] - sum[i][l - 1]);
	for (int len = 1; len < n; len++)
		for (int l = 1; l + len <= n; l++)
		{
			int r = l + len;
			for (int k = l; k <= r; k++)
				if(dp[l][k - 1] + dp[k + 1][r] + v[l][k - 1] + v[k + 1][r] < dp[l][r])
					dp[l][r] = dp[l][k - 1] + dp[k + 1][r] + v[l][k - 1] + v[k + 1][r], t[l][r] = k;
		}
	dfs(1, n, 0);
	for (int i = 1; i <= n; i++) cout << fa[i] << " "; 
	cout << endl;
	return 0;
}