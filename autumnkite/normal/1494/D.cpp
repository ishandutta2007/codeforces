#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> a[i][j];
		}
	}

	int tot = n;
	std::vector<int> fa(n, -1);
	std::vector<int> val(n);

	std::function<int(std::vector<int>)> solve = [&](std::vector<int> id) {
		if ((int)id.size() == 1) {
			val[id[0]] = a[id[0]][id[0]];
			return id[0];
		}
		int mx = 0;
		for (int i = 0; i < (int)id.size(); ++i) {
			for (int j = i + 1; j < (int)id.size(); ++j) {
				mx = std::max(mx, a[id[i]][id[j]]);
			}
		}
		DSU D(id.size());
		for (int i = 0; i < (int)id.size(); ++i) {
			for (int j = i + 1; j < (int)id.size(); ++j) {
				if (a[id[i]][id[j]] < mx) {
					D.merge(i, j);
				}
			}
		}
		std::vector<std::vector<int>> p(id.size());
		for (int i = 0; i < (int)id.size(); ++i) {
			p[D.find(i)].push_back(id[i]);
		}
		int now = tot++;
		fa.push_back(-1);
		val.push_back(mx);
		for (int i = 0; i < (int)id.size(); ++i) {
			if (!p[i].empty()) {
				int v = solve(p[i]);
				fa[v] = now;
			}
		}
		return now;
	};

	std::vector<int> id;
	for (int i = 0; i < n; ++i) {
		id.push_back(i);
	}
	int rt = solve(id);

	std::cout << tot << "\n";
	for (int v : val) {
		std::cout << v << " ";
	}
	std::cout << "\n";
	std::cout << rt + 1 << "\n";
	for (int i = 0; i < tot; ++i) {
		if (i != rt) {
			std::cout << i + 1 << " " << fa[i] + 1 << "\n";
		}
	}
}