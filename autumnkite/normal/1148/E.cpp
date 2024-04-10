#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		id[i] = i;
	}
	std::sort(id.begin(), id.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	std::sort(a.begin(), a.end());
	std::vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	std::sort(b.begin(), b.end());

	std::vector<std::tuple<int, int, int>> ans;
	std::vector<int> sta;
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) {
			sta.push_back(i);
		} else {
			while (a[i] > b[i] && !sta.empty()) {
				int tmp = std::min(b[sta.back()] - a[sta.back()], a[i] - b[i]);
				ans.emplace_back(sta.back(), i, tmp);
				a[sta.back()] += tmp, a[i] -= tmp;
				if (a[sta.back()] == b[sta.back()]) {
					sta.pop_back();
				}
			}
			if (a[i] > b[i]) {
				std::cout << "NO\n";
				return 0;
			}
		}
	}
	if (!sta.empty()) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	std::cout << ans.size() << "\n";
	for (auto [x, y, d] : ans) {
		std::cout << id[x] + 1 << " " << id[y] + 1 << " " << d << "\n";
	}
}