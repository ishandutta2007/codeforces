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
const int N = 509;
struct point
{
	int a, b, k;
	bool operator < (const point &x) const
	{
		return b > x.b;
	}
}p[N];
int n;
int dp[N][N], ans;
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i].a = read(), p[i].b = read(), p[i].k = read();
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + max(0ll, p[i].a - p[i].k * p[i].b);
		for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i - 1][j] + max(0ll, p[i].a - p[i].k * p[i].b), dp[i - 1][j - 1] + p[i].a - p[i].b * (j - 1));
	}
	for (int i = 0; i <= n; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}