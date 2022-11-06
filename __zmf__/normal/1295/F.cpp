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
const int N = 209, mod = 998244353;
int n, a[N], pp = 1;
int dp[N][N], inv[N];
struct node
{
	int l, r;
}p[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i].l = read(), p[i].r = read() + 1, a[i * 2 - 1] = p[i].l, a[i * 2] = p[i].r;	
	for (int i = 1; i <= n; i++) pp = pp * (p[i].r - p[i].l) % mod;
	sort(a + 1, a + 2 * n + 1);
	int tot = unique(a + 1, a + 2 * n + 1) - a - 1;
	for (int i = 1; i <= n; i++) 
		p[i].l = lower_bound(a + 1, a + tot + 1, p[i].l) - a, p[i].r = lower_bound(a + 1, a + tot + 1, p[i].r) - a;
	dp[0][tot] = 1; p[0].l = 0, p[0].r = 1e9;
	for (int i = 1; i <= n; i++) inv[i] = Pow(i, mod - 2);
	for (int i = 1; i <= n; i++)
	{
		for (int j = p[i].l; j < p[i].r; j++)
		{
			int res = 1, len = a[j + 1] - a[j];
			int nowl = 0, nowr = 1e9;
			for (int k = i - 1; k >= 0; k--)
			{
				res = res * (len + (i - k) - 1) % mod; res = res * inv[i - k] % mod;
				nowl = max(p[k + 1].l, nowl), nowr = min(p[k + 1].r, nowr);
				if(nowl > j) break;
				if(nowr <= j) break;
				for (int s = j + 1; s <= tot; s++) dp[i][j] = (dp[i][j] + dp[k][s] * res % mod) % mod;
			}
		}
	//	for (int j = p[i].l; j < p[i].r; j++) cout << i << " " << j << " " << dp[i][j] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= tot - 1; i++) ans = (ans + dp[n][i]) % mod;
	//cout << ans << endl;
	cout << ans * Pow(pp, mod - 2) % mod << endl;
	return 0;
}