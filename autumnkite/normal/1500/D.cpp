#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> col(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> col[i * n + j];
			--col[i * n + j];
		}
	}

	auto dis = [&](int v, int x, int y) {
		return std::max(v / n - x, v % n - y);
	};

	std::vector<bool> vis(n * n);

	auto merge = [&](int x, int y, std::vector<int> a, std::vector<int> b) {
		std::vector<int> res;
		int i = 0, j = 0;
		while ((i < (int)a.size() || j < (int)b.size()) && (int)res.size() <= q) {
			if (j == (int)b.size() || (i < (int)a.size() && dis(a[i], x, y) < dis(b[j], x, y))) {
				if (!vis[col[a[i]]]) {
					res.push_back(a[i]);
					vis[col[a[i]]] = true;
				}
				++i;
			} else {
				if (!vis[col[b[j]]]) {
					res.push_back(b[j]);
					vis[col[b[j]]] = true;
				}
				++j;
			}
		}
		for (int v : res) {
			vis[col[v]] = false;
		}
		return res;
	};

	std::vector<std::vector<int>> a(n), r(n + 1);
	std::vector<int> ans(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		std::vector<std::vector<int>> b(n + 1);
		for (int j = n - 1; j >= 0; --j) {
			a[j] = merge(i, j, a[j], std::vector<int>(1, i * n + j));
			b[j] = merge(i, j, b[j + 1], std::vector<int>(1, i * n + j));
		}
		for (int j = 0; j < n; ++j) {
			r[j] = merge(i, j, r[j + 1], merge(i, j, a[j], b[j]));
			if ((int)r[j].size() > q) {
				++ans[std::min(std::min(n - i, n - j), dis(r[j].back(), i, j))];
			} else {
				++ans[std::min(n - i, n - j)];
			}
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		ans[i] += ans[i + 1];
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i] << "\n";
	}
}