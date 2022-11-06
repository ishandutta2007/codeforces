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
const int N = 3e5 + 9, mod = 998244353;
int n, ans, m;
struct point
{
	int l, r;
}a[N], p[N];
int sum[N][42], cnt[N], vis[N];
int jc[N], inv[N];
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
inline void init()
{
	jc[0] = 1; 
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	inv[n] = Pow(jc[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
//	for (int i = 1; i <= n; i++) cout << inv[i] << endl;
	return ;
}
inline int C(int x, int y)
{
	if(x < 0 || y < 0 || x < y) return 0;
	return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main()
{
	n = read(); m = read(); init(); //cout << jc[3] << endl;
	for (int i = 1; i <= n; i++) 
		a[i].l = read(), a[i].r = read(), cnt[a[i].l]++, cnt[a[i].r + 1]--;
//	for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
	for (int i = 2; i <= n; i++) cnt[i] += cnt[i - 1];
//	for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
	for (int i = 0; i < m; i++) p[i].l = read(), p[i].r = read();
	for (int c = 0; c <= m * 2; c++) 
	{
		for (int i = 1; i <= n; i++) sum[i][c] = C(cnt[i] - c, i - c);
		for (int i = 2; i <= n; i++) sum[i][c] = (sum[i][c] + sum[i - 1][c]) % mod;
	}
	for (int i = 0; i < (1 << m); i++)
	{
		int popcnt = 0, L = 1, R = n, pep = 0; 
		for (int j = 0; j < m; j++)
			if(i & (1 << j)) 
			{
				popcnt++;
				L = max(L, a[p[j].l].l), R = min(R, a[p[j].l].r);
				L = max(L, a[p[j].r].l), R = min(R, a[p[j].r].r);
				pep += (!vis[p[j].l]), pep += (!vis[p[j].r]); vis[p[j].l] = 1, vis[p[j].r] = 1;
			}
		for (int j = 0; j < m; j++)
			if(i & (1 << j)) 
				vis[p[j].l] = 0, vis[p[j].r] = 0;
		if(R < L) continue;
		if(popcnt & 1) ans = (ans - (sum[R][pep] - sum[L - 1][pep] + mod) % mod + mod) % mod;
		else ans = (ans + (sum[R][pep] - sum[L - 1][pep] + mod)) % mod; 
	//	cout << sum[R][pep] << " " << sum[L - 1][pep] << endl;
	}
	cout << ans << endl;
	return 0;
}