#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
const int mod = 1000000007;
int n, fact[N], ifact[N], inv[N], f[N];
int main() {
	scanf("%d", &n);
	fact[0] = ifact[0] = fact[1] = ifact[1] = inv[1] = 1;
	for (int i = 2; i <= 3 * n + 3; i++) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = 1ll * ifact[i - 1] * inv[i] % mod;
	}
	for (int i = 1; i <= 3 * n + 3; i++) {
		f[i - 1] = 1ll * fact[3 * n + 3] * ifact[i] % mod * ifact[3 * n + 3 - i] % mod;
	}
	for (int i = 3 * n + 2; i >= 2; i--) {
		f[i - 1] = (f[i - 1] + 3ll * (mod - f[i])) % mod;
		f[i - 2] = (f[i - 2] + 3ll * (mod - f[i])) % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int x;
		scanf("%d", &x);
		x += 2;
		printf("%d\n", f[x]);
	}
	return 0;
}