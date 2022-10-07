#include <bits/stdc++.h>

const int P = 1000000007;

class basis {
	std::vector<int> a;

public:
	static const int LG = 5;

	basis() : a(LG) {}

	bool insert(int x) {
		for (int i = LG - 1; i >= 0; --i) {
			if (x >> i & 1) {
				if (a[i]) {
					x ^= a[i];
				} else {
					a[i] = x;
					for (int j = 0; j < i; ++j) {
						if (a[j] && a[i] >> j & 1) {
							a[i] ^= a[j];
						}
					}
					for (int j = LG - 1; j > i; --j) {
						if (a[j] >> i & 1) {
							a[j] ^= a[i];
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	bool operator<(const basis &rhs) const {
		return a < rhs.a;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		E[u].emplace_back(v, w);
		E[v].emplace_back(u, w);
	}

	int idx = 0;
	std::vector<int> dfn(n, -1);
	std::vector<int> dis(n);
	int cnt = 0;
	std::vector<int> bel(n);
	std::vector<std::vector<int>> val, val_rt;
	std::function<void(int, int)> dfs = [&](int u, int rt) {
		dfn[u] = idx++;
		bel[u] = rt;
		for (auto p : E[u]) {
			int v = p.first, w = p.second;
			if (dfn[v] == -1) {
				dis[v] = dis[u] ^ w;
				dfs(v, rt);
			} else if (dfn[u] < dfn[v]) {
				val[rt].push_back(dis[u] ^ dis[v] ^ w);
			}
		}
	};
	dfn[0] = idx++;
	dis[0] = 0;
	for (auto p : E[0]) {
		int v = p.first, w = p.second;
		if (dfn[v] == -1) {
			dis[v] = w;
			val.emplace_back();
			val_rt.emplace_back();
			dfs(v, cnt++);
		} else {
			val_rt[bel[v]].push_back(dis[v] ^ w);
		}
	}

	std::map<basis, int> id;
	std::function<void(std::vector<int>)> init = [&](std::vector<int> now) {
		if ((int)now.size() == basis::LG) {
			basis tmp;
			for (int x : now) {
				tmp.insert(x);
			}
			if (!id.count(tmp)) {
				int t = id.size();
				id[tmp] = t;
			}
			return;
		}
		for (int i = now.empty() ? 0 : now.back(); i < (1 << basis::LG); ++i) {
			now.push_back(i);
			init(now);
			now.pop_back();
		}
	};
	init(std::vector<int>());

	std::vector<std::vector<int>> trans(id.size(), std::vector<int>(1 << basis::LG, -1));
	for (const auto &p : id) {
		for (int i = 0; i < (1 << basis::LG); ++i) {
			basis B = p.first;
			if (B.insert(i)) {
				trans[p.second][i] = id[B];
			}
		}
	}

	std::vector<int> f(id.size());
	f[id[basis()]] = 1;
	for (int i = 0; i < cnt; ++i) {
		std::vector<int> g(f);
		for (int S = 0; S < (int)id.size(); ++S) {
			int T = S;
			for (int w : val[i]) {
				if (T != -1) {
					T = trans[T][w];
				}
			}
			if (T != -1) {
				g[T] = (g[T] + f[S]) % P;
				if (!val_rt[i].empty()) {
					g[T] = (g[T] + f[S]) % P;
					T = trans[T][val_rt[i][0]];
					if (T != -1) {
						g[T] = (g[T] + f[S]) % P;
					}
				}
			}
		}
		f.swap(g);
	}
	std::cout << std::accumulate(f.begin(), f.end(), 0ll) % P << "\n";
}