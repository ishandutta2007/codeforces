#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> v(a);
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	for (int &x : a) {
		x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
	}

	std::vector<std::vector<int>> pos(v.size());
	for (int i = 0; i < n; ++i) {
		pos[a[i]].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i + 1 < (int)v.size(); ++i) {
		for (int j = 0; j < (int)pos[i].size(); ++j) {
			ans = std::max(ans, (int)(pos[i + 1].end() - std::upper_bound(pos[i + 1].begin(), pos[i + 1].end(), pos[i][j])) + j + 1);
		}
	}
	for (int l = 0, r = 0; l < (int)v.size(); l = r) {
		r = l + 1;
		int cnt = pos[l].size();
		while (r < (int)v.size() && pos[r].front() > pos[r - 1].back()) {
			cnt += pos[r].size();
			++r;
		}
		if (l > 0) {
			cnt += std::lower_bound(pos[l - 1].begin(), pos[l - 1].end(), pos[l].front()) - pos[l - 1].begin();
		}
		if (r < (int)v.size()) {
			cnt += pos[r].end() - std::upper_bound(pos[r].begin(), pos[r].end(), pos[r - 1].back());
		}
		ans = std::max(ans, cnt);
	}
	std::cout << n - ans << "\n";
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