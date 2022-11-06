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
const int N = 1e6 + 9, mod = 1e9 + 7;
int inv_2 = (mod + 1) / 2;
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
inline int C(int x, int y) {return jc[x] * inv[y] % mod * inv[x - y] % mod;}
inline void solve()
{
	int n = read(), m = read(), k = read();
	int ans = 0;
	for (int i = 0; i < m; i++) ans = (ans + (m - i) * C(n, i)) % mod; //cout << ans << endl;
	ans = ans * Pow(inv_2, n - 1) % mod;
	printf("%lld\n", ans * k % mod);
}
inline void init()
{
	int x = 1e6;
	jc[0] = 1;
	for (int i = 1; i <= x; i++) jc[i] = jc[i - 1] * i % mod;
	inv[x] = Pow(jc[x], mod - 2);
	for (int i = x - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
signed main()
{
	int T = read();
	init();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}