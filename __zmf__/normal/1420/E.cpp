/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 89;
int a[N], pep, m, pos[N], lim, INF, n;
int dp[N][N * N][N], ans[N * N]; // i, j, k -> i  1, j , k  1 
inline int Abs(int x)
{
	return x > 0 ? x : -x;
}
signed main()
{
//	cout << Abs(5) << " " << Abs(-5) << endl;
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		a[i] = read(), pep += (a[i] ^ 1);
		if(a[i]) pos[++m] = i; 
	} 
	memset(dp, 0x3f, sizeof(dp)); INF = dp[0][0][0]; memset(ans, 0x3f, sizeof(ans));
	lim = n * (n - 1) / 2; dp[0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= lim; j++)
			for (int k = 0; k < m; k++)
				if(dp[i][j][k] != INF)
					for (int t = i + 1; t <= n; t++) 
					{
						int v = j + (t - i - 1) * (t - i - 2) / 2; 
						dp[t][v][k + 1] = min(dp[t][v][k + 1], dp[i][j][k] + Abs(t - pos[k + 1]));
					}
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= lim; j++) 
			if(dp[i][j][m] != INF)
			{
				int v = j + (n - i) * (n - i - 1) / 2;
				ans[dp[i][j][m]] = min(ans[dp[i][j][m]], v);
			//	cout << i << " " << j << " " << v << " " << dp[i][j][m] << endl;
			}
	for (int i = 1; i <= lim; i++) ans[i] = min(ans[i], ans[i - 1]);
	for (int i = 0; i <= lim; i++) printf("%lld ", pep * (pep - 1) / 2 - ans[i]);
	return 0;
}