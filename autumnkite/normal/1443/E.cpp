#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	const int L = std::min(n, 15);
	std::vector<long long> fac(L);
	fac[0] = 1;
	for (int i = 1; i < L; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	auto calc = [&](long long x, int l, int r) {
		std::vector<int> a(L);
		for (int i = L - 1; i >= 0; --i) {
			a[i] = x / fac[i];
			x %= fac[i];
		}
		std::reverse(a.begin(), a.end());
		std::vector<bool> vis(L);
		std::vector<int> p(L);
		for (int i = 0; i < L; ++i) {
			int t = 0;
			p[i] = 0;
			while (vis[p[i]] || t < a[i]) {
				t += !vis[p[i]];
				++p[i];
			}
			vis[p[i]] = true;
		}
		int res = 0;
		for (int i = l; i < r; ++i) {
			res += p[i];
		}
		return res;
	};

	long long sum = 0;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r;
			std::cin >> l >> r;
			--l;
			if (r <= n - L) {
				std::cout << 1ll * (l + r + 1) * (r - l) / 2 << "\n";
			} else if (l <= n - L) {
				std::cout << 1ll * (l + n - L + 1) * (n - L - l) / 2 + 
				             1ll * (n - L + 1) * (r - n + L) + calc(sum, 0, r - n + L) << "\n";
			} else {
				std::cout << 1ll * (n - L + 1) * (r - l) + calc(sum, l - n + L, r - n + L) << "\n";
			}
		} else {
			int x;
			std::cin >> x;
			sum += x;
		}
	}
}