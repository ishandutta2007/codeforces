#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
#define int ll
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod, n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int fac[300010], ifac[300010], fac2[300010], ip2[300010];
int inv2 = inv(2);
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for(int i = n; i >= 1; i--)
		ifac[i - 1] = ifac[i] * i % mod;
	fac2[0] = fac2[1] = 1;
	for(int i = 2; i <= n; i++)
		fac2[i] = fac2[i - 2] * i % mod;
	ip2[0] = 1;
	for(int i = 1; i <= n; i++)
		ip2[i] = ip2[i - 1] * inv2 % mod;
}
inline int C(int n, int m)
{
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
const int g = 3, ig = inv(g);
int r[1100000];
inline void getr(int n, int cnt)
{
	for(int i = 0; i < n; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
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
				int x = a[j + k], y = w * a[i + j + k] % mod;
				a[j + k] = (x + y) % mod;
				a[i + j + k] = (x - y + mod) % mod;
			}
		}
	}
	if(op == -1)
	{
		int in = inv(n);
		for(int i = 0; i < n; i++)
			a[i] = a[i] * in % mod;
	}
}
inline void mul(int *a, int *b, int *c, int n, int m)
{
	static int A[1100000], B[1100000];
	int lim = 1, cnt = 0;
	while(lim <= n + m)
		lim <<= 1, cnt++;
	getr(lim, cnt);
	for(int i = 0; i < n; i++)
		A[i] = a[i];
	for(int i = n; i < lim; i++)
		A[i] = 0;
	for(int i = 0; i < m; i++)
		B[i] = b[i];
	for(int i = m; i < lim; i++)
		B[i] = 0;
	NTT(A, lim, 1), NTT(B, lim, 1);
	for(int i = 0; i < lim; i++)
		c[i] = A[i] * B[i] % mod;
	NTT(c, lim, -1);
}
int a[1100000], b[1100000], c[1100000];
signed main()
{
	int t;
	scanf("%lld", &t);
	InitFac(300000);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		int ans = 0, m = n >> 1;
		for(int i = 0; i <= m; i += 2)
			a[i] = fac[n - i] * ifac[i >> 1] % mod;
		for(int i = 0; i <= m; i++)
			b[i] = ifac[i] * ip2[i] % mod;
		mul(a, b, c, m + 1, m + 1);
		for(int i = 0; i <= m; i++)
			ans = (ans + c[i] * ifac[n - 2 * i]) % mod;
		// for(int i = 0; i <= (n >> 1); i += 2) // 4
		// {
		// 	for(int j = 0; j <= (n - 2 * i) >> 1; j++) // 2
		// 	{
		// 		// int tot = C(n - 2 * i, 2 * i) * fac2[2 * max(i, 1ll) - 1] % mod * fastpow(2, i) % mod * C(n - 4 * i, 2 * j) % mod * fac2[2 * max(j, 1ll) - 1] % mod;
		// 		int tot = fac[n - i] * ifac[i >> 1] % mod * ifac[n - 2 * i - 2 * j] % mod * ifac[j] % mod * inv(fastpow(2, j)) % mod;
		// 		cout << "i = " << i << ", j = " << j << ", tot = " << tot << endl;
		// 		ans = (ans + tot) % mod;
		// 	}
		// }
		printf("%lld\n", ans);
	}
	return 0;
}