#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<bool> col(6 * n);
	for (int i = 0; i < 3 * n; ++i) {
		int x;
		std::cin >> x;
		--x;
		col[x] = true;
	}

	std::vector<int> sta;
	std::vector<std::vector<int>> tmp(6 * n);
	std::vector<std::tuple<int, int, int>> tp;
	std::vector<bool> bel;
	std::vector<std::vector<int>> E(2 * n);
	for (int i = 0; i < 6 * n; ++i) {
		sta.push_back(i);
		if ((int)sta.size() >= 3) {
			auto c = std::prev(sta.end()), b = std::prev(c), a = std::prev(b);
			if (col[*a] == col[*b] && col[*b] == col[*c]) {
				int u = tp.size();
				tp.emplace_back(*a, *b, *c);
				bel.push_back(col[*a]);
				if (a != sta.begin()) {
					tmp[*std::prev(a)].push_back(u);
				}
				E[u].insert(E[u].end(), tmp[*a].begin(), tmp[*a].end());
				E[u].insert(E[u].end(), tmp[*b].begin(), tmp[*b].end());
				sta.pop_back(), sta.pop_back(), sta.pop_back();
			}
		}
	}

	std::vector<int> fa(2 * n, -1), deg(2 * n, 0);
	for (int u = 0; u < 2 * n; ++u) {
		for (int v : E[u]) {
			fa[v] = u;
		}
		deg[u] = E[u].size();
	}

	int cnt = 0;
	for (int u = 0; u < 2 * n; ++u) {
		if (fa[u] == -1 && !bel[u]) {
			++cnt;
		}
	}

	int p = -1;
	std::array<std::queue<int>, 2> Q;
	for (int u = 0; u < 2 * n; ++u) {
		if (!deg[u]) {
			Q[bel[u]].push(u);
		}
	}
	std::vector<std::tuple<int, int, int>> ans;
	int c = 0;
	for (int i = 0; i < 2 * n - 1; ++i) {
		c ^= 1;
		while (1) {
			int u = Q[c].front();
			Q[c].pop();
			if (fa[u] == -1 && !bel[u]) {
				if (cnt == 1) {
					p = u;
					continue;
				}
				--cnt;
			}
			ans.emplace_back(tp[u]);
			if (fa[u] != -1) {
				--deg[fa[u]];
				if (!deg[fa[u]]) {
					Q[bel[fa[u]]].push(fa[u]);
				}
			}
			break;
		}
	}
	if (p == -1) {
		c ^= 1;
		p = Q[c].front();
	}
	ans.emplace_back(tp[p]);
	for (auto [x, y, z] : ans) {
		std::cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
	}
}