#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 1000000007;
int fact[N], ifact[N], inv[N];
int n, k;
inline int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1ll * fact[x] * ifact[y] % mod * ifact[x - y] % mod;
}
inline int W(int x, int y) {
	return C(x + y - 1, y - 1);
}
inline int calc(int x) {
	return 1ll * fact[n - x] * ifact[n] % mod;
}
int main() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = fact[0] = ifact[0] = 1; i < N; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = 1ll * ifact[i - 1] * inv[i] % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n && n - i - (i - 1) * (k - 1) >= 0; i++) {
			int t = W(n - i - (i - 1) * (k - 1), i + 1);
			ans = (ans + 1ll * t * (n - i) % mod * fact[i] % mod * (i + 1) % mod * calc(i + 1)) % mod;
			if (i > 1) {
				ans = (ans + 1ll * (mod - t) * fact[i] % mod * i % mod * calc(i)) % mod;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}