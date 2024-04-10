#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500005;
const int MOD = 998244353;

int n, k, jc[N], ny[N];

int C(int n, int m)
{
	if (n < m) return 0;
	else return (LL)jc[n] * ny[m] % MOD * ny[n - m] % MOD;
}

int main()
{
	scanf("%d%d", &n, &k);
	jc[0] = jc[1] = ny[0] = ny[1] = 1;
	for (int i = 2; i <= n; i++) jc[i] = (LL)jc[i - 1] * i %MOD, ny[i] = (LL)(MOD - MOD / i) * ny[MOD % i] % MOD;
	for (int i = 2; i <= n; i++) ny[i] = (LL)ny[i - 1] * ny[i] % MOD;
	int ans = 0;
	for (int i = 1; i <= n; i++) (ans += C(n / i - 1, k - 1)) %= MOD;
	printf("%d\n", ans);
	return 0;
}