#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	int mn = 1e9;
	for (int i = 1; i < n; ++i) {
		mn = std::min(mn, a[i] - a[i - 1]);
	}
	if (a[n - 1] - a[0] == mn) {
		for (int j = 0; j < n; ++j) {
			std::cout << a[j] << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] - a[i - 1] == mn) {
			for (int j = i; j < n; ++j) {
				std::cout << a[j] << " ";
			}
			for (int j = 0; j < i; ++j) {
				std::cout << a[j] << " ";
			}
			std::cout << "\n";
			return;
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