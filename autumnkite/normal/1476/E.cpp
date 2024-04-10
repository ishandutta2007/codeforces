#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;
	std::map<std::string, int> mp;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		mp[s] = i;
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < m; ++i) {
		std::string s;
		std::cin >> s;
		int x;
		std::cin >> x;
		--x;
		bool flag = false;
		for (int S = 0; S < (1 << k); ++S) {
			std::string t = s;
			for (int j = 0; j < k; ++j) {
				if (S >> j & 1) {
					t[j] = '_';
				}
			}
			if (mp.count(t)) {
				int y = mp[t];
				if (y == x) {
					flag = true;
				} else {
					E[x].push_back(mp[t]);
				}
			}
		}
		if (!flag) {
			E[x].push_back(x);
		}
	}

	std::vector<int> d(n);
	for (int u = 0; u < n; ++u) {
		for (int v : E[u]) {
			++d[v];
		}
	}
	std::vector<int> Q;
	for (int i = 0; i < n; ++i) {
		if (!d[i]) {
			Q.push_back(i);
		}
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			--d[v];
			if (!d[v]) {
				Q.push_back(v);
			}
		}
	}
	if ((int)Q.size() == n) {
		std::cout << "YES\n";
		for (int x : Q) {
			std::cout << x + 1 << " ";
		}
		std::cout << "\n";
	} else {
		std::cout << "NO\n";
	}
}