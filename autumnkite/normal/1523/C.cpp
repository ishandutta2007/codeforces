#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> sta;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 1) {
			while (!sta.empty() && sta.back() + 1 != a[i]) {
				sta.pop_back();
			}
			++sta.back();
		} else {
			sta.push_back(a[i]);
		}
		for (int j = 0; j < (int)sta.size(); ++j) {
			std::cout << sta[j];
			if (j + 1 < (int)sta.size()) {
				std::cout << ".";
			}
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