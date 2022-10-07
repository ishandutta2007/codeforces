#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		--p[i];
	}

	std::vector<bool> vis(n);
	std::vector<std::vector<int>> cyc;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			cyc.emplace_back();
			for (int j = i; !vis[j]; j = p[j]) {
				vis[j] = true;
				cyc.back().push_back(j);
			}
		}
	}

	std::vector<std::pair<int, int>> ans;

	if ((int)cyc.size() == 1) {
		ans.emplace_back(cyc[0][0], cyc[0][1]);
		ans.emplace_back(cyc[0][1], cyc[0][2]);
		ans.emplace_back(cyc[0][0], cyc[0][2]);
		for (int i = 3; i < (int)cyc[0].size(); ++i) {
			ans.emplace_back(cyc[0][1], cyc[0][i]);
		}
		ans.emplace_back(cyc[0][0], cyc[0][1]);
	} else {
		if (cyc.size() & 1) {
			cyc.emplace_back();
			cyc.back().push_back(cyc[0][0]);
		}
		int t = 0;
		while (t + 1 < (int)cyc.size()) {
			ans.emplace_back(cyc[t].back(), cyc[t + 1].back());
			for (int i = 0; i + 1 < (int)cyc[t].size(); ++i) {
				ans.emplace_back(cyc[t + 1].back(), cyc[t][i]);
			}
			for (int i = 0; i + 1 < (int)cyc[t + 1].size(); ++i) {
				ans.emplace_back(cyc[t].back(), cyc[t + 1][i]);
			}
			ans.emplace_back(cyc[t].back(), cyc[t + 1].back());
			t += 2;
		}
	}

	std::cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		std::cout << x + 1 << " " << y + 1 << "\n";
	}
}