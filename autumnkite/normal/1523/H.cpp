#include <bits/stdc++.h>

int get_log(int n) {
	int res = 1;
	while ((1 << res) < n) {
		++res;
	}
	return res;
}

class sparse_table {
	int n, LG;
	std::vector<int> Log;
	std::vector<int> val;
	std::vector<std::vector<int>> st;

	int max(int x, int y) {
		return val[x] < val[y] ? y : x;
	}

public:
	sparse_table(std::vector<int> a) : n(a.size()), LG(get_log(n + 1)), Log(n + 1),
	                                   val(a), st(LG, std::vector<int>(n)) {
		Log[1] = 0;
		for (int i = 2; i <= n; ++i) {
			Log[i] = Log[i >> 1] + 1;
		}
		for (int i = 0; i < n; ++i) {
			st[0][i] = i;
		}
		for (int i = 1; i < LG; ++i) {
			for (int j = 0; j + (1 << i) <= n; ++j) {
				st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	int range_max(int l, int r) {
		int t = Log[r - l];
		return max(st[t][l], st[t][r - (1 << t)]);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	for (int i = 0; i < n; ++i) {
		a[i] += i + 1;
	}
	sparse_table st(a);

	const int LG = get_log(n), LIM = 30;
	std::vector<std::vector<std::vector<int>>> f(LG, 
	  std::vector<std::vector<int>>(n, std::vector<int>(LIM + 1)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= LIM; ++j) {
			f[0][i][j] = st.range_max(i, std::min(n, a[i] + j));
		}
	}
	for (int i = 1; i < LG; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k <= LIM; ++k) {
				f[i][j][k] = j;
				for (int t = 0; t <= k; ++t) {
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][f[i - 1][j][t]][k - t]);
				}
			}
		}
	}

	while (q--) {
		int l, r, k;
		std::cin >> l >> r >> k;
		--l, --r;
		if (l == r) {
			std::cout << 0 << "\n";
			continue;
		}
		std::vector<int> g(k + 1, l);
		auto check = [&](const std::vector<int> &h) {
			for (int j = 0; j <= k; ++j) {
				if (a[h[j]] + k - j > r) {
					return false;
				}
			}
			return true;
		};
		int ans = 0;
		for (int i = LG - 1; i >= 0; --i) {
			std::vector<int> h(g);
			for (int j = 0; j <= k; ++j) {
				for (int t = 0; t <= j; ++t) {
					h[j] = std::max(h[j], f[i][g[t]][j - t]);
				}
			}
			if (check(h)) {
				g.swap(h);
				ans += 1 << i;
			}
		}
		ans += check(g);
		++ans;
		std::cout << ans << "\n";
	}
}