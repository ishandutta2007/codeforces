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
const int N = 89, INF = 1e18;
int dp[N][N], T, n, to[N][N], k;
struct point
{
	int a, b, id;
}p[N];
int ans[N], cnt, pp[N], cntp;
inline bool cmp(point xxx, point yyy)
{
	return xxx.b < yyy.b;
}
inline void solve()
{
	n = read(); k = read();
	for (int i = 1; i <= n; i++) p[i].a = read(), p[i].b = read(), p[i].id = i;
	sort(p + 1, p + n + 1, cmp);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j] = -INF;	
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= k; j++)
		{
			if(dp[i - 1][j] + (k - 1) * p[i].b >= dp[i][j]) dp[i][j] = dp[i - 1][j] + (k - 1) * p[i].b, to[i][j] = 0;
			if(j != 0 && dp[i - 1][j - 1] + p[i].a + (j - 1) * p[i].b >= dp[i][j]) dp[i][j] = dp[i - 1][j - 1] + p[i].a + (j - 1) * p[i].b, to[i][j] = 1;
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
	printf("%lld\n", k + (n - k) * 2);
	//cout << dp[n][k] << endl;
	int nowx = n, nowy = k; cnt = 0; cntp = 0;
	while(nowx) 
	{
		if(to[nowx][nowy] == 1) ans[++cnt] = p[nowx].id, nowy--;
		else pp[++cntp] = p[nowx].id;
		nowx--;
	}
	for (int i = cnt; i >= 2; i--) printf("%lld ", ans[i]);
	for (int i = 1; i <= cntp; i++) printf("%lld -%lld ", pp[i], pp[i]);
	printf("%lld\n", ans[1]);
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}