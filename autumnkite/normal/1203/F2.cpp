#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> a, b;
	for (int i = 0; i < n; ++i) {
		int x, d;
		std::cin >> x >> d;
		if (d >= 0) {
			a.emplace_back(x, d);
		} else {
			b.emplace_back(x, -d);
		}
	}

	std::sort(a.begin(), a.end());
	int sum = 0;
	for (auto [x, d] : a) {
		if (m >= x) {
			m += d;
			++sum;
		}
	}

	std::sort(b.begin(), b.end(), [&](std::pair<int, int> x, std::pair<int, int> y) {
		return x.first - x.second > y.first - y.second;
	});
	std::vector<int> f(m + 1);
	f[m] = sum;
	int ans = sum;
	for (int i = 0; i < (int)b.size(); ++i) {
		std::vector<int> g(f);
		for (int j = std::max(b[i].first, b[i].second); j <= m; ++j) {
			g[j - b[i].second] = std::max(g[j - b[i].second], f[j] + 1);
		}
		f.swap(g);
		ans = std::max(ans, *std::max_element(f.begin(), f.end()));
	}
	std::cout << ans << "\n";
}