#include <bits/stdc++.h>

std::vector<int> EXKMP(const std::string &a) {
	int n = a.size();
	std::vector<int> z(n);
	z[0] = n;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		z[i] = std::max(std::min(z[i - l], r - i), 0);
		while (i + z[i] < n && a[i + z[i]] == a[z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i, r = i + z[i];
		}
	}
	return z;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	int m = 0;
	std::vector<std::vector<int>> id(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		id[i].resize(a[i].size() + 1);
		for (int j = 0; j <= (int)a[i].size(); ++j) {
			id[i][j] = m++;
		}
	}
	
	std::vector<std::vector<std::vector<int>>> z(n, std::vector<std::vector<int>>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			auto tmp = EXKMP(a[i] + '#' + a[j]);
			z[i][j] = std::vector<int>(tmp.begin() + a[i].size() + 1, tmp.end());
			z[i][j].push_back(0);
		}
	}

	auto check = [&](int l, int r) {
		std::vector<int> deg(m);
		std::vector<std::vector<int>> G(m);
		for (int i = l; i < r; ++i) {
			for (int j = l; j < r; ++j) {
				for (int k = 0; k <= (int)a[j].size(); ++k) {
					int len = z[i][j][k];
					if (len == (int)a[i].size()) {
						if (len == (int)a[j].size()) {
							continue;
						}
						G[id[j][k]].push_back(id[j][k + len]);
						++deg[id[j][k + len]];
					} else if (k + len == (int)a[j].size()) {
						G[id[j][k]].push_back(id[i][len]);
						++deg[id[i][len]];
					}
				}
			}
		}
		std::vector<int> Q;
		int cnt = 0;
		for (int i = l; i < r; ++i) {
			for (int u : id[i]) {
				++cnt;
				if (!deg[u]) {
					Q.push_back(u);
				}
			}
		}
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int v : G[u]) {
				--deg[v];
				if (!deg[v]) {
					Q.push_back(v);
				}
			}
		}
		return (int)Q.size() == cnt;
	};

	int ans = 0;
	for (int l = n - 1, r = n; l >= 0; --l) {
		while (r > l && !check(l, r)) {
			--r;
		}
		ans += r - l;
	}
	std::cout << ans << "\n";
}