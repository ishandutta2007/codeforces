#include <bits/stdc++.h> 

using namespace std;

const int N = 2e6 + 10;
const int MOD = 1e9 + 7;

bitset <N> vis;
long long f[N], g[N];
int q, r, n, sp[N];

long long bigMod (long long a, int e) {
	if (e == -1) e = MOD - 2;
	long long r = 1LL;
	while (e) {
		if (e & 1) r = (r * a) % MOD;
		a = (a * a) % MOD;
		e >>= 1;
	}
	return r;
}

long long choose (int n, int k) {
	long long r = f[n];
	r = (r * g[k]) % MOD;
	r = (r * g[n - k]) % MOD;
	return r;
}

void sieve (void) {
	for (int i = 2; i * i < N/2; ++i) if (!vis[i]) {
		sp[i] = i;
		for (int j = i * i; j < N/2; j += i) if (!vis[j]) {
			vis[j] = 1, sp[j] = i;
		}
	}
	for (int i = 2; i < N/2; ++i) if (sp[i] == 0) sp[i] = i;
}

int main (int argc, char const *argv[]) {
	f[0] = 1LL, g[0] = 1LL;
	for (long long i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * i) % MOD;
		g[i] = (g[i - 1] * bigMod(i, -1)) % MOD;
	}
	sieve();
	scanf("%d", &q); while (q--) {
		scanf("%d %d", &r, &n);
		long long ans = 1LL;
		while (n > 1) {
			int p = sp[n], m = 0;
			while (n % p == 0) n /= p, ++m;
			long long mult = (choose(r + m, r) + choose(r + m - 1, r)) % MOD;
			ans *= mult, ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}