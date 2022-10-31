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
int a[500010];
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
signed main()
{
	int n, sum = 0, mx = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), sum += a[i], mx = max(mx, a[i]);
	InitFac(max(mx, n));
	sort(a + 1, a + n + 1, [] (int x, int y) { return x > y; });
	int cnt[2] = {0, 0}, pos = 1, tot = 0;
	int ansval = 0, anstot = 1;
	for(int i = mx; i >= 1; i--)
	{
		int& c = cnt[i & 1];
		while(a[pos] == i)
			pos++, c++;
		ansval = (ansval + (sum - tot - c) * c % mod * (i - 1)) % mod;
		tot += (c << 1);
		if(i > 1)
			anstot = anstot * (fac[c] * fac[c] % mod) % mod;
		else
			anstot = anstot * fac[c] % mod;
	}
	printf("%lld %lld\n", ansval, anstot);
	return 0;
}