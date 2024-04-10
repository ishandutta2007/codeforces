#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum += a[i];
	}
	if (sum == m) {
		std::cout << "NO\n";
		return;
	}
	std::sort(a.begin(), a.end());
	int mx = a.back();
	int now = 0;
	for (int i = 0; i < n - 1; ++i) {
		now += a[i];
		if (now == m) {
			a.pop_back();
			a.insert(a.begin() + i, mx);
			break;
		}
	}
	std::cout << "YES\n";
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