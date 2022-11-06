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
const int N = 3609, mod = 998244353;
int visa[N], visb[N], k, n, m, jc[N], inv[N];
int a[N], b[N], cnta, cntb, ans, now, vb[N], sumb, va[N], suma;
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
	if(x < y) return 0;
	return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
inline int G()
{
	int res = 0;
	for (int i = 0; i <= suma / 2; i++)
		for (int j = 0; j + i * 2 <= suma; j++)
		{
			if(i + j * 2 > sumb) continue;
			now = 1;
			now = now * va[i] * C(suma - i * 2, j) % mod;
			now = now * vb[j] % mod * C(sumb - j * 2, i) % mod;
			now = now * jc[i] % mod * jc[j] % mod;
			res = (res + now) % mod;
		}
	return res;
}
signed main()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= k; i++)
	{
		int a1 = read(), b1 = read(), a2 = read(), b2 = read();
		visa[a1] = 1, visb[b1] = 1, visa[a2] = 1, visb[b2] = 1;
	}
	jc[0] = 1;
	for (int i = 1; i <= max(n, m); i++) jc[i] = jc[i - 1] * i % mod;
	inv[max(n, m)] = Pow(jc[max(n, m)], mod - 2);
	for (int i = max(n, m) - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod; 
	ans = 1; now = 0;
	for (int i = 1; i <= n; i++)
	{
		if(!visa[i]) now++;
		else if(now) a[++cnta] = now, suma += now, now = 0;  
	}
	if(now) a[++cnta] = now, suma += now, now = 0;
	for (int i = 1; i <= m; i++)
	{
		if(!visb[i]) now++;
		else if(now) b[++cntb] = now, sumb += now, now = 0;
	}
	if(now) b[++cntb] = now, sumb += now, now = 0;
	va[0] = 1;
	for (int i = 1; i <= cnta; i++)
		for (int j = suma; j >= 0; j--)
			for (int k = 1; k <= j && k <= a[i] / 2; k++)
				va[j] = (va[j] + va[j - k] * C(a[i] - k, k) % mod) % mod;
	vb[0] = 1;
	for (int i = 1; i <= cntb; i++)
		for (int j = sumb; j >= 0; j--)
			for (int k = 1; k <= j && k <= b[i] / 2; k++)
				vb[j] = (vb[j] + vb[j - k] * C(b[i] - k, k) % mod) % mod;
	cout << G() << endl;
	return 0;
}