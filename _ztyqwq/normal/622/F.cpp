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
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int fac[1000010], ifac[1000010];
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for(int i = n; i >= 1; i--)
		ifac[i - 1] = ifac[i] * i % mod;
}
inline int p1(int x)
{
	return (x & 1) ? mod - 1 : 1;
}
int b[1000010];
signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);
	InitFac(k + 1);
	b[0] = 0;
	for(int i = 1; i <= k + 1; i++)
		b[i] = (b[i - 1] + fastpow(i, k)) % mod;
	if(n <= k + 1)
	{ 
		printf("%lld\n", b[n]);
		return 0;
	}
	int prod = 1;
	for(int i = 0; i <= k + 1; i++)
		prod = prod * (n - i) % mod;
	int ans = 0;
	for(int i = 0; i <= k + 1; i++)
		ans = (ans + prod * inv(n - i) % mod * ifac[i] % mod * ifac[k + 1 - i] % mod * p1(k + 1 - i) % mod * b[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}