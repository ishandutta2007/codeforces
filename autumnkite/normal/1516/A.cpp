#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n - 1 && k > 0; ++i) {
		if (k < a[i]) {
			a[i] -= k;
			a.back() += k;
			k = 0;
		} else {
			k -= a[i];
			a.back() += a[i];
			a[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
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