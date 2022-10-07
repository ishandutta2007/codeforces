#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int mn = std::min_element(a.begin(), a.end()) - a.begin();
	std::cout << n - 1 << "\n";
	for (int i = mn - 1; i >= 0; --i) {
		std::cout << mn + 1 << " " << i + 1 << " " << a[mn] << " " << a[mn] + mn - i << "\n";
	}
	for (int i = mn + 1; i < n; ++i) {
		std::cout << mn + 1 << " " << i + 1 << " " << a[mn] << " " << a[mn] + i - mn << "\n";
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