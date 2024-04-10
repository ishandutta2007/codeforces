#include <bits/stdc++.h>

class binary_indexed_tree {
	int n, LG;
	std::vector<int> c;

public:
	binary_indexed_tree(int _n) : n(_n), LG(0), c(n + 1) {
		while ((1 << LG) <= n) {
			++LG;
		}
	}

	void add(int x, int v) {
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	int find(int v) {
		int x = 0;
		for (int i = LG - 1; i >= 0; --i) {
			if (x + (1 << i) <= n && c[x + (1 << i)] < v) {
				x += 1 << i;
				v -= c[x];
			}
		}
		return x;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	const int B = sqrt(1.0 * n / 2) + 1, C = (n - 1) / B + 1;
	std::vector<int> a(n);
	std::vector<int> bel(n);
	std::vector<int> L(C), R(C);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		a[i] = i - a[i];
		bel[i] = i / B;
	}
	for (int i = 0; i < C; ++i) {
		L[i] = i * B;
		R[i] = std::min(L[i] + B, n);
	}

	binary_indexed_tree T(n);
	for (int i = 1; i < n; ++i) {
		T.add(i, 1);
	}
	std::vector<std::vector<int>> pos(C);
	auto build = [&](int id) {
		pos[id].clear();
		for (int i = L[id]; i < R[id]; ++i) {
			int p = T.find(a[i]);
			pos[id].push_back(p);
			T.add(p, 1);
		}
		std::sort(pos[id].begin(), pos[id].end());
		for (int p : pos[id]) {
			T.add(p, -1);
		}
	};
	auto jump = [&](int id, int t) -> int {
		return std::upper_bound(pos[id].begin(), pos[id].end(), t) - pos[id].begin() + t;
	};

	for (int i = 0; i < C; ++i) {
		build(i);
	}
	int q;
	std::cin >> q;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x;
			std::cin >> x;
			--x;
			std::cin >> a[x];
			a[x] = x - a[x];
			build(bel[x]);
		} else {
			int x;
			std::cin >> x;
			--x;
			int t = a[x];
			for (int i = x + 1; i < R[bel[x]]; ++i) {
				if (a[i] <= t) {
					++t;
				}
			}
			for (int i = bel[x] + 1; i < C; ++i) {
				t = jump(i, t);
			}
			std::cout << t + 1 << "\n";
		}
	}
}