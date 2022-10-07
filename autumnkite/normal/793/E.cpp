#include <bits/stdc++.h>

class bitset {
	int n;
	std::vector<unsigned long long> a;

public:
	bitset(int _n) : n(_n), a(((n - 1) >> 6) + 1) {}

	void set(int x) {
		a[x >> 6] |= 1ull << (x & 63);
	}

	bool get(int x) {
		if (x < 0 || x >= n) {
			return 0;
		} else {
			return a[x >> 6] >> (x & 63) & 1;
		}
	}

	bitset operator<<(int k) const {
		bitset res(n);
		int p = k >> 6, b = k & 63;
		if (b == 0) {
			for (int i = p; i < (int)res.a.size(); ++i) {
				res.a[i] = a[i - p];
			}
		} else {
			if (p < (int)res.a.size()) {
				res.a[p] = a[0] << k;
			}
			for (int i = p + 1; i < (int)res.a.size(); ++i) {
				res.a[i] = (a[i - p] << b) | (a[i - p - 1] >> (64 - b));
			}
		}
		res.a.back() &= (1ull << (n & 63)) - 1;
		return res;
	}

	void operator|=(const bitset &rhs) {
		for (int i = 0; i < (int)a.size(); ++i) {
			a[i] |= rhs.a[i];
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int s[2], t[2];
	for (int k = 0; k < 2; ++k) {
		std::cin >> s[k] >> t[k];
		--s[k], --t[k];
	}
	std::vector<int> fa(n), sz(n, 1);
	fa[0] = -1;
	for (int i = 1; i < n; ++i) {
		std::cin >> fa[i];
		--fa[i];
		sz[fa[i]] = 0;
	}
	for (int i = n - 1; i > 0; --i) {
		sz[fa[i]] += sz[i];
	}
	int m = sz[0];
	if (m & 1) {
		std::cout << "NO\n";
		return 0;
	}
	m = m / 2 - 1;

	std::vector<int> type(n, -1);
	for (int k = 0; k < 2; ++k) {
		for (int i = s[k]; i != 0; i = fa[i]) {
			if (type[i] != -1) {
				std::cout << "NO\n";
				return 0;
			}
			type[i] = k;
		}
		for (int i = t[k]; i != 0; i = fa[i]) {
			if (type[i] != -1) {
				std::cout << "NO\n";
				return 0;
			}
			type[i] = k;
		}
	}

	std::vector<int> cnt[2] = {std::vector<int>(n), std::vector<int>(n)};
	for (int i = 1; i < n; ++i) {
		if (fa[i] == 0 && type[i] == -1) {
			++cnt[0][sz[i]];
			++cnt[1][sz[i]];
		}
	}
	for (int i = 1; i < n; ++i) {
		if (fa[i] != 0 && type[i] == -1) {
			int k = type[fa[i]];
			if (k != -1) {
				++cnt[k][sz[i]];
			}
		}
	}
	bitset f[2] = {m + 1, m + 1};
	for (int k = 0; k < 2; ++k) {
		f[k].set(0);
		for (int i = 1; i < n; ++i) {
			int x = cnt[k][i];
			if (x) {
				for (int j = 0; (1 << j) <= x; ++j) {
					f[k] |= f[k] << (i * (1 << j));
					x -= 1 << j;
				}
				f[k] |= f[k] << (i * x);
			}
		}
	}
	auto get_sz = [&](int u) {
		while (fa[u] != 0) {
			u = fa[u];
		}
		return sz[u];
	};
	if (f[0].get(m - get_sz(s[1])) && f[1].get(m - get_sz(t[0]))) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}