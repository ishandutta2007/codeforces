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
int fac[200010], ifac[200010];
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
signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);
	InitFac(max(n, k));
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%lld", &x);
		sum = (sum + x) % mod;
	}
	if(n == 1)
	{
		printf("%lld\n", sum * (k == 1));
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < k; i++)
		ans = (ans + p1(k - 1 - i) * fastpow(i + 1, n - 2) % mod * (n + i) % mod * ifac[i] % mod * ifac[k - 1 - i]) % mod;
	printf("%lld\n", ans * sum % mod);
	return 0;
}