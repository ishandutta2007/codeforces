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
const int N = 2e5 + 9, mod = 998244353, M = 2e5;
int n, m, s[N], t[N], c[N], ans, res, flag;
int jc[N], inv[N];
inline int lowbit(int x) {return x & (-x);}
inline void update(int x, int t) 
{
	while(x <= M) 
	{
		c[x] += t, x += lowbit(x);
	}
}
inline int query(int x) 
{
	int res = 0;
	while(x) res += c[x], x -= lowbit(x);
	return res;
}
inline int C(int x, int y) {return jc[x] * inv[y] % mod * inv[x - y] % mod;}
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
	n = read(), m = read(); ans = 0; res = 1;
	for (int i = 1; i <= n; i++) 
	{
		int x = read(); s[x]++; update(x, 1);
	}
	int rr = n; jc[0] = 1;
	for (int i = 1; i <= M; i++) jc[i] = jc[i - 1] * i % mod;
	inv[M] = Pow(jc[M], mod - 2);
	for (int i = M - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= M; i++) 
		if(s[i]) 
		{
			res = res * C(rr, s[i]) % mod; rr -= s[i];
		}
	for (int i = 1; i <= m; i++) t[i] = read();
	for (int i = 0; i <= min(n, m - 1); i++)
	{
		if(i == n) flag = 1;
		int x = query(t[i + 1] - 1), y = n - i;
	//	cout << x << " " << y << endl;
		ans = ans + (res * x % mod * Pow(y, mod - 2) % mod); ans %= mod;
	//	cout << x << " " << y << " " << ans << endl;
		if(!s[t[i + 1]]) break;
		else
		{
			res = res * s[t[i + 1]] % mod * Pow(y, mod - 2) % mod;
			update(t[i + 1], -1); s[t[i + 1]]--;
		}
	}
	if(n == m) flag = 0;
	ans = (ans + flag) % mod;
	cout << ans << endl;
	return 0;
}