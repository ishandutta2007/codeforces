#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	if ((n - 1) / 2 < k) {
		std::cout << -1 << "\n";
		return;
	}
	std::vector<int> a(n, -1);
	for (int i = 0; i < k; ++i) {
		a[2 * i + 1] = n - k + i;
	}
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			a[i] = idx++;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] + 1 << " ";
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