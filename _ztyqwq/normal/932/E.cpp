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
int fac[5010], ifac[5010];
signed p[5010][5010];
int cnt[5010], a[5010];
signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);
	p[1][1] = 1;
	for(int i = 2; i <= k; i++)
		for(int j = 1; j <= i; j++)
			p[i][j] = (p[i - 1][j - 1] - (ll)p[i - 1][j] * (i - 1) % mod + mod) % mod;
	a[k] = 1;
	for(int i = k; i >= 1; i--)
	{
		cnt[i] = a[i] * inv(p[i][i]);
		for(int j = i; j >= 1; j--)
			a[j] = (a[j] - cnt[i] * p[i][j] % mod + mod) % mod;
	}
	int ans = 0;
	for(int i = 1, f = n; i <= min(n, k); i++, f = f * (n - i + 1) % mod)
		ans = (ans + fastpow(2, n - i) * f % mod * cnt[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}