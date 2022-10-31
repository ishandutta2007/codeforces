#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 998244353;
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
const int g = 3, ig = inv(g);
int r[270000];
inline void getr(int lim, int n)
{
	for(int i = 0; i < lim; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (n - 1));
}
inline void NTT(int *a, int n, int op)
{
	for(int i = 0; i < n; i++)
		if(i < r[i])
			swap(a[i], a[r[i]]);
	for(int i = 1; i < n; i <<= 1)
	{
		int wn = fastpow(op == 1 ? g : ig, (mod - 1) / (i << 1));
		for(int j = 0; j < n; j += (i << 1))
		{
			int w = 1;
			for(int k = 0; k < i; k++, w = w * wn % mod)
			{
				int x = a[j + k], y = w * a[j + k + i] % mod;
				a[j + k] = (x + y) % mod;
				a[j + k + i] = (x - y + mod) % mod;                                                                                  
			}
		}
	}
	if(op == -1)
	{
		int il = inv(n);
		for(int i = 0; i < n; i++)
			a[i] = a[i] * il % mod;
	}
}
void Inv(int *a, int *b, int n, int cnt)
{
	static int tmp[270000];
	if(n == 1)
	{
		b[0] = inv(a[0]), b[1] = 0;
		return;
	}
	Inv(a, b, n >> 1, cnt - 1);
	// G = G (2 - FG)
	int lim = n << 1;
	for(int i = 0; i < n; i++)
		tmp[i] = a[i];
	for(int i = n; i < lim; i++)
		tmp[i] = b[i] = 0;
	getr(lim, cnt + 1);
	NTT(tmp, lim, 1);
	NTT(b, lim, 1);
	for(int i = 0; i < lim; i++)
		b[i] = b[i] * (2 - tmp[i] * b[i] % mod + mod) % mod;
	NTT(b, lim, -1);
	for(int i = n; i < lim; i++)
		b[i] = 0;
}
void Sqrt(int *a, int *b, int n, int cnt)
{
	static int f[270000], g[270000];
	if(n == 1)
	{
		b[0] = inv(a[0]);
		return;
	}
	Sqrt(a, b, n >> 1, cnt - 1);
	// (F + H^2) / 2H
	int lim = n << 1;
	Inv(b, g, n, cnt);
	getr(lim, cnt + 1);
	NTT(g, lim, 1);
	for(int i = 0; i < n; i++)
		f[i] = a[i];
	for(int i = n; i < lim; i++)
		f[i] = 0;
	NTT(f, lim, 1);
	NTT(b, lim, 1);
	int inv2 = inv(2);
	for(int i = 0; i < lim; i++)
		b[i] = (f[i] + b[i] * b[i]) % mod * inv2 % mod * g[i] % mod;
	NTT(b, lim, -1);
	for(int i = n; i < lim; i++)
		b[i] = 0;
}
int a[270000], b[270000];
signed main()
{
	int n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int c;
		scanf("%lld", &c);
		a[c]++;
	}
	// Ans = (1 - \sqrt(1 - 4C)) / 2C
	// = 2 / (1 + \sqrt(1 - 4C))
	int lim = 1, cnt = 0;
	m++;
	while(lim < m)
		lim <<= 1, cnt++;
	for(int i = 0; i < m; i++)
		a[i] = (mod - (a[i] << 2) % mod) % mod;
	a[0] = (a[0] + 1) % mod;
	Sqrt(a, b, lim, cnt);
	b[0] = (b[0] + 1) % mod;
	Inv(b, a, lim, cnt);
	for(int i = 0; i < m; i++)
		a[i] = (a[i] << 1) % mod;
	for(int i = 1; i < m; i++)
		printf("%lld\n", a[i]);
	return 0;
}