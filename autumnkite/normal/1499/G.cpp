#include <bits/stdc++.h>

const int P = 998244353;

class DSU {
	std::vector<int> pw;
	std::vector<int> fa, fw;
	std::vector<int> id;
	std::array<std::vector<int>, 2> s;
	int idx, ans;

	int find(int x) {
		if (fa[x] == x) {
			return x;
		} else {
			int t = find(fa[x]);
			fw[x] ^= fw[fa[x]];
			return fa[x] = t;
		}
	}

public:
	DSU(int n, int m) : pw(m), fa(m), fw(m), id(n, -1), idx(0), ans(0) {
		s[0].resize(m), s[1].resize(m);
		for (int i = 0; i < m; ++i) {
			fa[i] = i, fw[i] = 0;
			s[0][i] = s[1][i] = 0;
		}
		pw[0] = 1;
		for (int i = 1; i < m; ++i) {
			pw[i] = 2 * pw[i - 1] % P;
		}
	}

	void add_edge(int u, int v) {
		ans = (ans + pw[idx]) % P;
		s[0][idx] = pw[idx], s[1][idx] = 0;
		auto add = [&](int &x) {
			if (x == -1) {
				x = idx;
				return;
			}
			int t = find(x);
			int c = !fw[x];
			x = t;
			fa[x] = idx;
			fw[x] = c;
			s[0][idx] = (s[0][idx] + s[c][x]) % P;
			s[1][idx] = (s[1][idx] + s[!c][x]) % P;
			if (c) {
				ans = (ans + P - s[0][x]) % P;
				ans = (ans + s[c][x]) % P;
			}
			x = -1;
		};
		add(id[u]);
		add(id[v]);
		++idx;
	}

	int get_ans() {
		return ans;
	}

	bool isR(int x) {
		find(x);
		return !fw[x];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n1, n2, m;
	std::cin >> n1 >> n2 >> m;
	std::vector<std::pair<int, int>> E;
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		v += n1;
		E.emplace_back(u, v);
	}
	int q;
	std::cin >> q;
	DSU D(n1 + n2, m + q);
	for (auto [u, v] : E) {
		D.add_edge(u, v);
	}
	for (int i = 0; i < q; ++i) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			v += n1;
			D.add_edge(u, v);
			++m;
			std::cout << 2 * D.get_ans() % P << std::endl;
		} else {
			std::vector<int> R;
			for (int i = 0; i < m; ++i) {
				if (D.isR(i)) {
					R.push_back(i);
				}
			}
			std::cout << R.size() << " ";
			for (int x : R) {
				std::cout << x + 1 << " ";
			}
			std::cout << std::endl;
		}
	}
}