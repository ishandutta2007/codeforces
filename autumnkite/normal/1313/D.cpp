#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> v, L(n), R(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> L[i] >> R[i];
		--L[i];
		v.push_back(L[i]), v.push_back(R[i]);
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	std::vector<std::vector<int>> st(v.size()), ed(v.size());
	for (int i = 0; i < n; ++i) {
		L[i] = std::lower_bound(v.begin(), v.end(), L[i]) - v.begin();
		R[i] = std::lower_bound(v.begin(), v.end(), R[i]) - v.begin();
		st[L[i]].push_back(i);
		ed[R[i]].push_back(i);
	}

	std::vector<int> bit(1 << k);
	for (int i = 1; i < (1 << k); ++i) {
		bit[i] = bit[i >> 1] + (i & 1);
	}

	std::vector<int> f(1);
	std::vector<int> id;
	for (int i = 0; i + 1 < (int)v.size(); ++i) {
		for (int x : ed[i]) {
			int p = std::find(id.begin(), id.end(), x) - id.begin();
			std::vector<int> g(1 << (id.size() - 1));
			for (int S = 0; S < (1 << id.size()); ++S) {
				int T = (S >> (p + 1) << p) | (S & ((1 << p) - 1));
				g[T] = std::max(g[T], f[S]);
			}
			f.swap(g);
			id.erase(id.begin() + p);
		}
		for (int x : st[i]) {
			std::vector<int> g(1 << (id.size() + 1));
			for (int S = 0; S < (1 << id.size()); ++S) {
				for (int k = 0; k < 2; ++k) {
					int T = S | (k << id.size());
					g[T] = std::max(g[T], f[S]);
				}
			}
			f.swap(g);
			id.push_back(x);
		}
		for (int S = 0; S < (1 << id.size()); ++S) {
			f[S] += (bit[S] & 1) * (v[i + 1] - v[i]);
		}
	}
	std::cout << *std::max_element(f.begin(), f.end()) << "\n";
}