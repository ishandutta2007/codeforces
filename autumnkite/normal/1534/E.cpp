#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> E(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = std::max(i + k - n, 0); j <= std::min(i, k); ++j) {
			E[i + k - 2 * j].push_back(i);
		}
	}

	std::vector<int> dis(n + 1, n + 1), pre(n + 1);
	std::vector<int> Q;
	dis[0] = 0;
	Q.push_back(0);
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			if (dis[v] == n + 1) {
				dis[v] = dis[u] + 1;
				Q.push_back(v);
				pre[v] = u;
			}
		}
	}

	if (dis[n] == n + 1) {
		std::cout << -1 << std::endl;
		return 0;
	}

	std::vector<std::vector<int>> ans;
	std::vector<int> p1, p2;
	for (int i = 0; i < n; ++i) {
		p1.push_back(i);
	}
	while (!p1.empty()) {
		int t = (p1.size() - pre[p1.size()] + k) / 2;
		std::vector<int> tmp;
		for (int i = 0; i < t; ++i) {
			tmp.push_back(p1.back());
			p1.pop_back();
		}
		for (int i = 0; i < k - t; ++i) {
			tmp.push_back(p2.back());
			p2.pop_back();
		}
		for (int i = 0; i < t; ++i) {
			p2.push_back(tmp[i]);
		}
		for (int i = t; i < k; ++i) {
			p1.push_back(tmp[i]);
		}
		ans.push_back(tmp);
	}
	int sum = 0;
	for (int i = 0; i < (int)ans.size(); ++i) {
		std::cout << "? ";
		for (int x : ans[i]) {
			std::cout << x + 1 << " ";
		}
		std::cout << std::endl;
		int res;
		std::cin >> res;
		sum ^= res;
	}
	std::cout << "! " << sum << std::endl;
}