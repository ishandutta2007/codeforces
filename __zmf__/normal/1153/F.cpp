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
const int N = 5009, mod = 998244353;
int n, k, l, v[N], jc[N], inv[N], ans, fac[N];
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
inline int C(int x, int y)
{
	return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main()
{
	n = read(), k = read(), l = read();
	jc[0] = 1;
	for (int i = 1; i <= 2 * n; i++) jc[i] = jc[i - 1] * i % mod;
	inv[2 * n] = Pow(jc[2 * n], mod - 2);
	for (int i = 2 * n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	for (int i = 0; i <= n; i++) v[i] = jc[2 * i] * Pow(Pow(2, i), mod - 2) % mod;
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * (2 * i - 1) % mod;
	for (int i = 1; i <= n * 2 - 1; i++)
		for (int j = k; j <= i && j <= n * 2 - i; j++)
			if((i - j) % 2 == 0)
			{
				ans = (ans + C(i, j) * jc[n * 2 - i] % mod * inv[n * 2 - i - j] % mod * fac[(i - j) / 2] % mod * fac[(n * 2 - i - j) / 2] % mod) % mod;
			}
	ans = ans * Pow(fac[n], mod - 2) % mod;
	ans = ans * l % mod; ans = ans * Pow(2 * n + 1, mod - 2) % mod;
	cout << ans % mod << endl;
	return 0;
}
/*
5
1 1 1 1
*/