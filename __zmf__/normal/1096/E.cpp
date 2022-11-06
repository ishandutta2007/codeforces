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
const int N = 1e5 + 9, mod = 998244353;
int n, m, a[N], jc[N], inv[N], invp[N], p, s, r;
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
	jc[0] = 1; invp[0] = 0;
	for (int i = 1; i <= N - 9; i++) jc[i] = jc[i - 1] * i % mod, invp[i] = Pow(i, mod - 2);
	inv[N - 9] = Pow(jc[N - 9], mod - 2);
	for (int i = N - 10; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	return ;
}
inline int C(int x, int y)
{
	if(x < y) return 0;
	return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
inline int P(int x, int y)
{
	return C(x + y - 1, x - 1);
}
inline int f(int x, int y, int r)
{
	if(!x && !y) return 1;
	int res = 0, nega = 1;
	if(x & 1) nega = -1;
	for (int i = 0; i <= x; i++)
	{
		if(y - (r + 1) * (x - i) >= 0)
			res = (res + C(x, i) * P(x, y - (r + 1) * (x - i)) % mod * nega + mod) % mod;
		nega *= -1;
	}
	return res;
}
int ans;
signed main()
{
	p = read(), s = read(), r = read();
  	init();
  	for (int x = r; x <= s; x++)
  		for (int y = 0; (y + 1) * x <= s && y < p; y++)
  		{
  			//cout << x << " " << y << endl;
  			ans = (ans + C(p - 1, y) * f(p - y - 1, s - x * (y + 1), x - 1) % mod * invp[y + 1] % mod) % mod;
  		}
  	ans = ans * Pow(C(s - r + p - 1, p - 1), mod - 2) % mod;
	cout << ans << endl;
	return 0;
}