#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, k, c, fact[20], inv[20], ifact[20], cnt[1 << 16], a[1 << 16];
map<vector<int>, int> mp;
int main() {
	scanf("%d%d%d", &n, &k, &c);
	inv[1] = 1;
	for (int i = 2; i <= k; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= k; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = 1ll * ifact[i - 1] * inv[i] % mod;
	}
	int xx = 0;
	for (int _ = 0; _ < n; _++) {
		int x;
		scanf("%d", &x);
		xx ^= x;
		vector<int> vec(k);
		for (int i = 0; i < k; i++) vec[i] = x ^ (x - i - 1);
		mp[vec]++;
	}
	for (int mask = 0; mask < (1 << c); mask++) {
		vector<int> vc;
		for (const auto &it : mp) {
			int st = 0;
			for (int i = 0; i < k; i++) if (__builtin_parity(mask & it.first[i])) st |= (1 << i);
			if (!cnt[st]) vc.push_back(st);
			cnt[st] += it.second;
		}
		vector<int> res(k + 1, 0);
		res[0] = 1;
		for (const int &st : vc) {
			vector<int> f(k + 1), g(k + 1), l(k + 1);
			f[0] = 1;
			for (int i = 1; i <= k; i++) {
				f[i] = ((st >> (i - 1) & 1) ? mod - ifact[i] : ifact[i]);
			}
			for (int i = 1; i <= k; i++) {
				l[i] = 1ll * f[i] * i % mod;
				for (int j = 1; j < i; j++) l[i] = (l[i] + 1ll * (mod - l[j]) * f[i - j]) % mod;
			}
			g[0] = 1;
			for (int i = 1; i <= k; i++) {
				g[i] = 0;
				for (int j = 1; j <= i; j++) g[i] = (g[i] + 1ll * cnt[st] * l[j] % mod * g[i - j]) % mod;
				g[i] = 1ll * g[i] * inv[i] % mod;
			}
			for (int i = k; i >= 0; i--) {
				int cur = 0;
				for (int j = 0; j <= i; j++) cur = (cur + 1ll * res[j] * g[i - j]) % mod;
				res[i] = cur;
			}
			cnt[st] = 0;
		}
		a[mask] = res[k];
	}
	for (int i = 1; i < (1 << c); i *= 2) {
		for (int j = 0; j < (1 << c); j += i * 2) {
			for (int k = 0; k < i; k++) {
				int x = a[j + k], y = a[i + j + k];
				a[j + k] = (x + y) % mod;
				a[i + j + k] = (x - y + mod) % mod;
			}
		}
	}
	int t = 1ll * fact[k] * qp(1 << c, mod - 2) % mod * qp(n, mod - 1 - k) % mod;
	for (int i = 0; i < (1 << c); i++) a[i] = 1ll * a[i] * t % mod;
	for (int i = 0; i < (1 << c); i++) printf("%d ", a[i ^ xx]);
	return 0;
}