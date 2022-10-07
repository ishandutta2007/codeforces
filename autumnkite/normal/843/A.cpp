#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> v(a);
	std::sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}

	std::vector<bool> vis(n);
	std::vector<std::vector<int>> ans;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans.emplace_back();
			for (int j = i; !vis[j]; j = a[j]) {
				ans.back().push_back(j);
				vis[j] = true;
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (const auto &p : ans) {
		std::cout << p.size() << " ";
		for (int x : p) {
			std::cout << x + 1 << " ";
		}
		std::cout << "\n";
	}
}