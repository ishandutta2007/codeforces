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
int fac[100010], ifac[100010];
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for(int i = n; i >= 1; i--)
		ifac[i - 1] = ifac[i] * i % mod;
}
inline int C(int n, int m)
{
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);
	InitFac(n);
	k = min(n, k);
	int ans = 0;
	for(int i = 0; i <= k; i++)
		ans = (ans + C(n, i)) % mod;
	printf("%lld\n", ans);
	return 0;
}