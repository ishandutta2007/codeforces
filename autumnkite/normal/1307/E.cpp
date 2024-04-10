#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> pos(n);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		pos[x].push_back(i);
	}
	std::vector<std::vector<std::pair<int, int>>> a(n);
	for (int i = 0; i < m; ++i) {
		int c, s;
		std::cin >> c >> s;
		--c;
		if (s <= (int)pos[c].size()) {
			a[c].emplace_back(pos[c][s - 1], pos[c][pos[c].size() - s]);
		}
	}
	for (int i = 0; i < n; ++i) {
		std::sort(a[i].begin(), a[i].end());
	}

	auto solve = [&](int l, int r) {
		int cnt = 0;
		int sum = 1;
		for (int i = 0; i < n; ++i) {
			if ((int)a[i].size() >= 2) {
				int t0 = 0, t1 = 0;
				for (auto [x, y] : a[i]) {
					t0 += x < l;
					t1 += y >= r;
				}
				int t = t0 * t1;
				for (auto [x, y] : a[i]) {
					t -= x < l && y >= r;
				}
				if (t) {
					cnt += 2;
					sum = 1ll * sum * t % P;
					continue;
				}
			}
			if ((int)a[i].size() >= 1) {
				int t = 0;
				for (auto [x, y] : a[i]) {
					t += x < l;
					t += y >= r;
				}
				if (t) {
					++cnt;
					sum = 1ll * sum * t % P;
					continue;
				}
			}
		}
		return std::make_pair(cnt, sum);
	};

	std::vector<std::pair<int, int>> s(n + 1);
	int mx = 0;
	for (int i = 0; i <= n; ++i) {
		s[i] = solve(i, i);
		mx = std::max(mx, s[i].first);
	}
	int sum = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i].first == mx) {
			sum = (sum + s[i].second) % P;
		}
	}
	for (int i = 0; i < n; ++i) {
		auto tmp = solve(i, i + 1);
		if (tmp.first == mx) {
			sum = (sum + P - tmp.second) % P;
		}
	}
	std::cout << mx << " " << sum << "\n";
}