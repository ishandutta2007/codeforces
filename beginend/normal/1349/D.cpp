#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 300005;
const int MOD = 998244353;

int n;
LL a[N], f[N], sum[N], s;

LL ksm(LL x, LL y)
{
	x %= MOD;
	LL ans = 1;
	while (y)
	{
		if (y & 1) ans = ans * x %MOD;
		x = x * x % MOD; y >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), s += a[i];
	f[0] = n - 1;
	for (int i = 1; i < s; i++)
	{
		f[i] = f[i - 1] * i % MOD * ksm(s, MOD - 2) % MOD + 1;
		f[i] = s * (n - 1) % MOD * ksm(s - i, MOD - 2) % MOD * f[i] % MOD;
	}
	for (int i = s; i >= 0; i--) sum[i] = (sum[i + 1] + f[i]) % MOD;
	LL ans = 0;
	for (int i = 1; i <= n; i++) (ans += sum[a[i]]) %= MOD;
	(ans += MOD - sum[0] * (n - 1) % MOD) %= MOD;
	ans = ans * ksm(n, MOD - 2) % MOD;
	printf("%lld\n", ans);
	return 0;
}