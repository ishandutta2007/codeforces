#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, W, H;
	std::cin >> n >> W >> H;
	std::vector<int> x(n);
	std::map<int, std::pair<std::vector<int>, std::vector<int>>> mp;
	for (int i = 0; i < n; ++i) {
		int op, t;
		std::cin >> op >> x[i] >> t;
		if (op == 1) {
			mp[x[i] - t].first.push_back(i);
		} else {
			mp[x[i] - t].second.push_back(i);
		}
	}

	std::vector<std::pair<int, int>> ans(n);
	for (const auto &tmp : mp) {
		auto a = tmp.second.first, b = tmp.second.second;
		std::sort(a.begin(), a.end(), [&](int i, int j) {
			return x[i] < x[j];
		});
		std::sort(b.begin(), b.end(), [&](int i, int j) {
			return x[i] > x[j];
		});
		int n = a.size(), m = b.size();
		std::vector<std::pair<int, int>> p(n + m), q(n + m);
		for (int i = 0; i < n; ++i) {
			p[i] = q[m + i] = std::make_pair(a[i], 0);
		}
		for (int i = 0; i < m; ++i) {
			p[n + i] = q[i] = std::make_pair(b[i], 1);
		}
		for (int i = 0; i < n + m; ++i) {
			if (p[i].second == 0) {
				ans[q[i].first] = std::make_pair(x[p[i].first], H);
			} else {
				ans[q[i].first] = std::make_pair(W, x[p[i].first]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		std::cout << ans[i].first << " " << ans[i].second << "\n";
	}
}