#include<bits/stdc++.h>

typedef long long LL;

const int N = 200005;
const int MOD = 998244353;

int n, k, ny[N], jc[N];

int ksm(int x, int y)
{
	int ans = 1;
	while (y)
	{
		if (y & 1) ans = (LL) ans * x %MOD;
		x = (LL) x * x %MOD; y >>= 1;
	}
	return ans;
}

int C(int n, int m)
{
	return (LL) jc[n] * ny[m] % MOD * ny[n - m] % MOD;
}

int main()
{
	scanf("%d%d", &n, &k);
	jc[0] = jc[1] = ny[0] = ny[1] = 1;
	for (int i = 2; i <= n; i++) jc[i] = (LL) jc[i - 1] * i % MOD, ny[i] = (LL) (MOD - MOD / i) * ny[MOD % i] % MOD;
	for (int i = 2; i <= n; i++) ny[i] = (LL) ny[i - 1] * ny[i] % MOD;
	if (!k)
	{
		printf("%d\n", jc[n]);
		return 0;
	}
	int ans = 0;
	for (int i = k; i <= n; i++)
		if ((i - k) & 1)(ans += MOD - (LL) C(n, i) * C(i, k) % MOD * ksm(n - i, n) % MOD) %= MOD;
		else (ans += (LL) C(n, i) * C(i, k) % MOD * ksm(n - i, n) % MOD) %= MOD;
	printf("%d\n", ans * 2 % MOD);
	return 0;
}