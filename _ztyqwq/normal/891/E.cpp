#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
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
int a[5010];
int fac[5010], ifac[5010];
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for(int i = n; i >= 1; i--)
		ifac[i - 1] = ifac[i] * i % mod;
}
int p[5010];
signed main()
{
	int n, k, prod = 1;
	scanf("%lld %lld", &n, &k);
	InitFac(n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), prod = prod * a[i] % mod;
	p[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j >= 1; j--)
			p[j] = (p[j] * a[i] - p[j - 1] + mod) % mod;
		p[0] = p[0] * a[i] % mod;
	}
	int ans = 0, fc = 1, nk = 1, invn = inv(n);
	for(int i = 0; i <= n; i++)
	{
		ans = (ans + nk * fc % mod * p[i]) % mod;
		fc = fc * (k - i) % mod;
		nk = nk * invn % mod;
	}
	printf("%lld\n", (prod - ans + mod) % mod);
	return 0;
}