#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			flag ^= a[i] > a[j];
		}
	}
	for (int i = 0; i < n && flag; ++i) {
		for (int j = i + 1; j < n && flag; ++j) {
			if (a[i].first == a[j].first) {
				std::swap(a[i], a[j]);
				flag = false;
			}
		}
	}
	if (flag) {
		std::cout << -1 << "\n";
		return;
	}

	std::vector<int> ans;
	auto shift = [&](int i) {
		ans.push_back(i);
		std::swap(a[i], a[i + 2]);
		std::swap(a[i + 1], a[i + 2]);
	};
	for (int i = 0; i < n - 2; ++i) {
		int j = std::min_element(a.begin() + i, a.end()) - a.begin();
		while (j - 2 >= i) {
			shift(j - 2);
			j -= 2;
		}
		if (j == i + 1) {
			shift(i);
			shift(i);
		}
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) {
		std::cout << x + 1 << " ";
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