#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, P;
	std::cin >> n >> P;
	std::vector<int> w(n + 1);
	w[0] = 1;
	for (int i = 1; i <= n; ++i) {
		w[i] = 1ll * w[i - 1] * (n - i + 1) % P;
	}

	std::vector<int> f(1, 1);
	int ans = 0;
	for (int k = 1; k <= n; ++k) {
		int s = 0, si = 0, now = 0, sum = 0;
		for (int i = 0; i < (int)f.size(); ++i) {
			sum = (sum + 1ll * f[i] * now) % P;
			now = (now + si) % P;
			now = (now + 1ll * (k - i % P + P) * s) % P;
			s = (s + f[i]) % P;
			si = (si + 1ll * f[i] * i) % P;
			if (i >= k) {
				s = (s + P - f[i - k]) % P;
				si = (si + 1ll * (P - f[i - k]) * (i - k)) % P;
			}
		}
		ans = (ans + 1ll * sum * w[n - k]) % P;
		f.resize(f.size() + k - 1);
		for (int i = 1; i < (int)f.size(); ++i) {
			f[i] = (f[i] + f[i - 1]) % P;
		}
		for (int i = (int)f.size() - 1; i >= k; --i) {
			f[i] = (f[i] + P - f[i - k]) % P;
		}
	}
	std::cout << ans << "\n";
}