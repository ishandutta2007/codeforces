#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

class BIT {
	int n;
	std::vector<int> c;

public:
	BIT(int _n) : n(_n), c(n + 1, INF) {}

	void chmin(int x, int v) {
		for (++x; x; x ^= x & -x) {
			c[x] = std::min(c[x], v);
		}
	}

	int query(int x) {
		int res = INF;
		for (++x; x <= n; x += x & -x) {
			res = std::min(res, c[x]);
		}
		return res;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	std::vector<std::vector<std::pair<int, int>>> Q(n);
	for (int i = 0; i < q; ++i) {
		int l, r;
		std::cin >> l >> r;
		--l, --r;
		Q[r].emplace_back(l, i);
	}
	std::vector<int> minp(mx + 1);
	for (int i = 1; i <= mx; ++i) {
		minp[i] = i;
	}
	for (int i = 2; i <= mx; ++i) {
		if (minp[i] == i) {
			for (int j = i + i; j <= mx; j += i) {
				minp[j] = std::min(minp[j], i);
			}
		}
	}
	std::vector<std::vector<int>> pos(mx + 1, std::vector<int>(8, -1));
	BIT T(n);
	std::vector<int> ans(q);
	for (int k = 0; k < n; ++k) {
		int x = a[k];
		std::vector<int> pf;
		while (x != 1) {
			if (pf.empty() || pf.back() != minp[x]) {
				pf.push_back(minp[x]);
			} else {
				pf.pop_back();
			}
			x /= minp[x];
		}
		std::vector<int> lst(15, -1);
		for (int S = 0; S < (1 << pf.size()); ++S) {
			int s = 1, c = 0;
			for (int i = 0; i < (int)pf.size(); ++i) {
				if (S >> i & 1) {
					s *= pf[i];
				} else {
					++c;
				}
			}
			for (int i = 0; i <= 7; ++i) {
				lst[c + i] = std::max(lst[c + i], pos[s][i]);
			}
			pos[s][c] = k;
		}
		for (int i = 0; i <= 14; ++i) {
			if (lst[i] != -1) {
				T.chmin(lst[i], i);
			}
		}
		for (auto p : Q[k]) {
			ans[p.second] = T.query(p.first);
		}
	}
	for (int x : ans) {
		std::cout << x << "\n";
	}
}