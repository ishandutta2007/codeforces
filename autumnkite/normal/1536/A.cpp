#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		flag &= a[i] >= 0;
	}
	if (!flag) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::cout << 101 << "\n";
		for (int i = 0; i <= 100; ++i) {
			std::cout << i << " ";
		}
		std::cout << "\n";
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