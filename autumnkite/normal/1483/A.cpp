#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(m);
	std::vector<int> c(n);
	for (int i = 0; i < m; ++i) {
		int k;
		std::cin >> k;
		a[i].resize(k);
		for (int &x : a[i]) {
			std::cin >> x;
			--x;
		}
		++c[a[i][0]];
	}
	
	int id = -1;
	for (int i = 0; i < n; ++i) {
		if (c[i] > (m + 1) / 2) {
			id = i;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (a[i][0] == id && (int)a[i].size() > 1 && c[id] > (m + 1) / 2) {
			std::swap(a[i][0], a[i][1]);
			--c[id];
		}
	}
	if (id == -1 || c[id] <= (m + 1) / 2) {
		std::cout << "YES\n";
		for (int i = 0; i < m; ++i) {
			std::cout << a[i][0] + 1 << " ";
		}
		std::cout << "\n";
	} else {
		std::cout << "NO\n";
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