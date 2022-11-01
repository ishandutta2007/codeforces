#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3000005;
const int MOD = 1000000007;

int n, q, fac[N], inv[N], a[N], b[10], c[N], binv[10];

int ksm(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = (LL)ans * x % MOD;
		x = (LL)x * x % MOD; y >>= 1;
	}
	return ans;
}

int binom(int n, int m) {
	return (LL)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void divi() {
	int now = n * 3 + 3;
	for (int i = n * 3 + 3; i >= 0; i--) {
		if (now - i + 1 == 4) {
			c[now] = (LL)a[now] * binv[3] % MOD;
			for (int j = 0; j <= 3; j++)
				(a[now - j] += MOD - (LL)b[3 - j] * c[now] % MOD) %= MOD;
			while (now >= 0 && !a[now]) now--;
		}
	}
	for (int i = 0; i <= n * 3; i++)
		c[i] = c[i + 3];
}

int main() {
	scanf("%d%d", &n, &q);
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for (int i = 2; i <= n * 3 + 3; i++) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
	}
	for (int i = 2; i <= n * 3 + 3; i++)
		inv[i] = (LL)inv[i - 1] * inv[i] % MOD;
	for (int i = 0; i <= 3 * n + 3; i++)
		a[i] = binom(3 * n + 3, i);
	for (int i = 0; i <= 3; i++) {
		b[i] = binom(3, i);
		binv[i] = ksm(b[i], MOD -2 );
		(a[i] += MOD - b[i]) %= MOD;
	}
	b[0] = binv[0] = 0;
	divi();
	while (q--) {
		int x; scanf("%d", &x);
		printf("%d\n", c[x]);
	}
	return 0;
}