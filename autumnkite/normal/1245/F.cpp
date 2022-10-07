#include <bits/stdc++.h>

void solve() {
	int l, r;
	std::cin >> l >> r;
	std::vector<long long> f(16, 1);
	for (int i = 0; i < 30; ++i) {
		std::vector<long long> g(16);
		for (int S = 0; S < 16; ++S) {
			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2 - a; ++b) {
					if ((S & 1 && !a && l >> i & 1) || 
					    (S & 2 && a && ~r >> i & 1) ||
					    (S & 4 && !b && l >> i & 1) ||
					    (S & 8 && b && ~r >> i & 1)) {
						continue;
					}
					int T = S & ((a == (l >> i & 1)) |
					             (a == (r >> i & 1)) << 1 |
								 (b == (l >> i & 1)) << 2 |
								 (b == (r >> i & 1)) << 3);
					g[S] += f[T];
				}
			}
		}
		f.swap(g);
	}
	std::cout << f[15] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}