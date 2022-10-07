#include <bits/stdc++.h>

const int P = 998244353;

typedef unsigned long long state;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	if (n == 1) {
		std::cout << "ACCEPTED\n";
		return 0;
	}
	std::vector<state> a(m);
	for (int i = 0; i < m; ++i) {
		int k;
		std::cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			std::cin >> x;
			--x;
			a[i] |= 1ull << x;
		}
	}

	auto dfs = [&](auto &self, int k, state mask, state now) {
		if (k == m) {
			if (mask != (1ull << n) - 1) {
				return false;
			}
			return now == 0 || now + (now & -now) == (1ull << n);
		}
		state A = (a[k] | mask) ^ mask, B = a[k] ^ A;
		int cA = __builtin_popcountll(A);
		int cB = __builtin_popcountll(B);
		int d = __builtin_popcountll(now & B);
		now &= mask ^ B;
		state S = a[k];
		for (int i = 0; i < cB - d; ++i) {
			S ^= S & -S;
		}
		for (int i = 0; i <= cA; ++i) {
			if (!self(self, k + 1, mask | a[k], now | S)) {
				return false;
			}
			if (i < cA) {
				S ^= S & -S;
			}
		}
		return true;
	};

	if (dfs(dfs, 0, 0, 0)) {
		std::cout << "ACCEPTED\n";
	} else {
		std::cout << "REJECTED\n";
	}
}