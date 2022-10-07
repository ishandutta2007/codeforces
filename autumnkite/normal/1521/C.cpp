#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	auto query = [&](int op, int i, int j, int x) {
		std::cout << "? " << op << " " << i + 1 << " " << j + 1 << " " << x + 1 << std::endl;
		int res;
		std::cin >> res;
		return res - 1;
	};
	for (int i = 0; i + 1 < n; i += 2) {
		int mx = query(1, i, i + 1, n - 2);
		if (mx == n - 2) {
			mx = std::max(mx, query(1, i + 1, i, n - 2));
		}
		int mn = query(2, i, i + 1, 0);
		if (mn == 1) {
			mn = std::min(mn, query(2, i + 1, i, 0));
		}
		if (query(1, i, i + 1, mn) == mn) {
			p[i] = mx, p[i + 1] = mn;
		} else {
			p[i] = mn, p[i + 1] = mx;
		}
	}
	if (n & 1) {
		std::vector<bool> vis(n);
		for (int i = 0; i < n - 1; ++i) {
			vis[p[i]] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				p.back() = i;
			}
		}
	}
	std::cout << "! ";
	for (int i = 0; i < n; ++i) {
		std::cout << p[i] + 1 << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}