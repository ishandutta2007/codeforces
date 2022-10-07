#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	auto solve = [&](std::vector<int> a, std::vector<int> b) {
		std::vector<std::pair<int, int>> v(n), vt(n);
		for (int i = 0; i < n; ++i) {
			v[i] = std::make_pair(a[i], b[i]);
			vt[i] = std::make_pair(b[i], a[i]);
		}
		std::sort(v.begin(), v.end());
		std::sort(vt.begin(), vt.end());
		int ans = 0;
		std::set<int> S;
		for (int i = 0, j = 0; i < n; ++i) {
			if (v[i].first >= v[i].second) {
				continue;
			}
			while (j < n && vt[j].first <= v[i].first) {
				S.insert(vt[j].second);
				++j;
			}
			auto it = S.lower_bound(v[i].second);
			if (it != S.end()) {
				ans = std::max(ans, v[i].second - v[i].first);
			}
			if (it != S.begin()) {
				--it;
				ans = std::max(ans, *it - v[i].first);
			}
		}
		return ans;
	};

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += abs(a[i] - b[i]);
	}
	std::cout << sum - 2 * std::max(solve(a, b), solve(b, a)) << "\n";
}