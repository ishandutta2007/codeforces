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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1509, M = 1509;
int n, s, m, k, a[N], le[N], ri[N], to[N], b[N], l, r, ans, sum[N];
int dp[N][N];
inline bool check(int x)
{
	for (int i = 1; i <= n; i++)
		if(a[i] <= b[x]) sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
//	for (int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	memset(dp, 0, sizeof(dp));
	for (int j = 1; j <= s; j++)
	{
		for (int i = 1; i <= n; i++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
		for (int i = 1; i <= n; i++) 
			if(to[i]) dp[to[i]][j] = max(dp[to[i]][j], dp[i - 1][j - 1] + sum[to[i]] - sum[i - 1]);
		for (int i = 1; i <= n; i++) dp[i][j] = max(dp[i][j], dp[i - 1][j]); 
	}
	return dp[n][s] >= k;
}
signed main()
{
	n = read(), m = read(), s = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read(), b[i] = a[i];
	for (int i = 1; i <= m; i++) le[i] = read(), ri[i] = read();
	for (int i = 1; i <= m; i++)
		for (int j = le[i]; j <= ri[i]; j++) 
			to[j] = max(to[j], ri[i]);
	sort(b + 1, b + n + 1);
	ans = -1; l = 1, r = n;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(ans == -1) puts("-1");
	else cout << b[ans] << endl;
}