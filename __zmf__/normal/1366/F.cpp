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
const int N = 2009, INF = 1e18, mod = 1e9 + 7;
int n, m, t, ans;
int nxt[N * 2], to[N * 2], head[N], cnt, val[N * 2];
int dp[N][N];
struct point
{
	int u, v, w;
	int val;
}p[N];
inline bool cmp(point xxx, point yyy) {return xxx.w < yyy.w;}
signed main()
{ 
	n = read(), m = read(), t = read();
	for (int i = 1; i <= m; i++)
		p[i].u = read(), p[i].v = read(), p[i].w = read();
	for (int i = 2; i <= n; i++) dp[0][i] = -INF;
	for (int i = 1; i <= n; i++) 
	{
		int now = -INF;
		for (int j = 1; j <= n; j++) dp[i][j] = -INF;
		for (int j = 1; j <= m; j++) 
				dp[i][p[j].v] = max(dp[i][p[j].v], dp[i - 1][p[j].u] + p[j].w),
				dp[i][p[j].u] = max(dp[i][p[j].u], dp[i - 1][p[j].v] + p[j].w);
		for (int j = 1; j <= n; j++) now = max(now, dp[i][j]);
		if(i <= t) ans += now;
	}
	for (int i = 1; i <= m; i++) p[i].val = max(dp[n][p[i].u], dp[n][p[i].v]);
	sort(p + 1, p + m + 1, cmp); ans %= mod;
	//  
	for (int i = 1; i <= m; i++) 
	{
		int L = 1, R = t - n, flag = 0;
		for (int j = 1; j < i; j++) 
			if(p[i].w == p[j].w) flag |= (p[j].val > p[i].val);
			else L = max(L, (p[j].val - p[i].val + p[i].w - p[j].w - 1) / (p[i].w - p[j].w));
		p[i].val--;
		for (int j = i + 1; j <= m; j++) 
			if(p[i].w == p[j].w) flag |= (p[j].val > p[i].val);
			else R = min(R, (p[j].val - p[i].val) / (p[i].w - p[j].w));
		p[i].val++;
		if(R < L || flag) continue;
		//cout << p[i].u << " " << p[i].v << " " << p[i].w << " " << p[i].val << " " << L << " " << R << endl;
		ans = (ans + (R - L + 1) * p[i].val % mod) % mod; 
		ans = (ans + ((R - L + 1) * (L + R) / 2) % mod * p[i].w % mod);
	}
	cout << ans % mod << endl;
	return 0;	
}