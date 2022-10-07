#include <bits/stdc++.h>

const int P = 1000000007;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> minp(n + 1, n);
	for (int i = 2; i <= n; ++i) {
		if (minp[i] == n) {
			for (int j = i; j <= n; j += i) {
				minp[j] = std::min(minp[j], i);
			}
		}
	}

	std::vector<int> fac(n + 1), inv(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
	auto C = [&](int n, int m) -> int {
		if (m < 0 || m > n) {
			return 0;
		}
		return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
	};

	int s = 1;
	while ((1 << s) <= n) {
		++s;
	}
	--s;

	std::vector<int> cnt(s + 1), cnt1(s + 1);
	for (int i = 1; i <= n; ++i) {
		int x = i;
		int c = 0;
		bool ex = false;
		while (x != 1) {
			if (minp[x] == 2) {
				++c;
			} else if (minp[x] == 3) {
				ex = true;
			}
			x /= minp[x];
		}
		++cnt[c];
		if (ex) {
			++cnt1[c + 1];
		}
	}

	int len = 0;
	int now = 1;
	for (int i = 0; i <= s; ++i) {
		if (cnt[i]) {
			len += cnt[i];
			now = 1ll * now * fac[cnt[i]] % P * C(len - 1, cnt[i] - 1) % P;
		}
	}
	int ans = now;
	if (cnt1[s]) {
		for (int k = s; k > 0; --k) {
			int len = 0;
			int now = 1;
			cnt[k - 1] += cnt[k];
			cnt[k - 1] -= cnt1[k];
			cnt[k] = 0;
			for (int i = 0; i < k; ++i) {
				if (cnt[i]) {
					len += cnt[i];
					now = 1ll * now * fac[cnt[i]] % P * C(len - 1, cnt[i] - 1) % P;
				}
			}
			for (int i = k; i <= s; ++i) {
				if (cnt1[i]) {
					len += cnt1[i];
					now = 1ll * now * fac[cnt1[i]] % P * C(len - 1, cnt1[i] - 1) % P;
				}
			}
			ans = (ans + now) % P;
		}
	}
	std::cout << ans << "\n";
}