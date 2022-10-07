#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	bool ok[2] = {true, true};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != '.') {
				ok[(a[i][j] == 'R') ^ (i & 1) ^ (j & 1)] = false;
			}
		}
	}
	for (int k = 0; k < 2; ++k) {
		if (ok[k]) {
			std::cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					std::cout << ((i & 1) ^ (j & 1) ^ k ? 'W' : 'R');
				}
				std::cout << "\n";
			}
			return;
		}
	}
	std::cout << "NO\n";
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