#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		a[i] = x & ((1 << 15) - 1);
		b[i] = x >> 15;
	}

	std::map<std::vector<int>, int> S;
	for (int x = 0; x < (1 << 15); ++x) {
		std::vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			cnt[i] = __builtin_popcount(a[i] ^ x);
		}
		std::vector<int> tmp(n - 1);
		for (int i = 1; i < n; ++i) {
			tmp[i - 1] = cnt[i] - cnt[0];
		}
		S[tmp] = x;
	}
	for (int x = 0; x < (1 << 15); ++x) {
		std::vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			cnt[i] = __builtin_popcount(b[i] ^ x);
		}
		std::vector<int> tmp(n - 1);
		for (int i = 1; i < n; ++i) {
			tmp[i - 1] = cnt[0] - cnt[i];
		}
		if (S.count(tmp)) {
			std::cout << (x << 15 | S[tmp]) << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
}