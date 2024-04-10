#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> S(3);
	std::vector<std::string> a(n);
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != '.') {
				S[(i + j) % 3].emplace_back(i, j);
				++tot;
			}
		}
	}
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			if (x != y) {
				int cnt = 0;
				for (auto [i, j] : S[x]) {
					cnt += a[i][j] == 'X';
				}
				for (auto [i, j] : S[y]) {
					cnt += a[i][j] == 'O';
				}
				if (cnt <= tot / 3) {
					for (auto [i, j] : S[x]) {
						a[i][j] = 'O';
					}
					for (auto [i, j] : S[y]) {
						a[i][j] = 'X';
					}
					for (int i = 0; i < n; ++i) {
						std::cout << a[i] << "\n";
					}
					return;
				}
			}
		}
	}
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