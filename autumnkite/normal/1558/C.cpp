#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}

	std::vector<int> ans;
	auto rev = [&](int x) {
		std::reverse(a.begin(), a.begin() + x);
		ans.push_back(x);
	};
	auto find = [&](int x) {
		return std::find(a.begin(), a.end(), x) - a.begin();
	};
	for (int i = n - 1; i >= 1; i -= 2) {
		int x = find(i);
		if (x & 1) {
			std::cout << -1 << "\n";
			return;
		}
		rev(x + 1);
		int y = find(i - 1);
		if (!(y & 1)) {
			std::cout << -1 << "\n";
			return;
		}
		rev(y);
		rev(y + 2);
		rev(3);
		rev(i + 1);
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) {
		std::cout << x << " ";
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