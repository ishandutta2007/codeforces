#include <bits/stdc++.h>

class ACAM {
	static const int C = 26;

public:
	int cnt, rt;
	std::vector<std::vector<int>> trans;
	std::vector<int> id;
	std::vector<int> fail;

	int new_node() {
		int u = cnt++;
		trans.push_back(std::vector<int>(C, -1));
		id.push_back(-1);
		fail.push_back(0);
		return u;
	}

	ACAM() : cnt(0) {
		rt = new_node();
	}

	void insert(std::string s, int x) {
		int u = rt;
		for (int i = 0; i < (int)s.size(); ++i) {
			int v = trans[u][s[i] - 'a'];
			if (v == -1) {
				v = new_node();
				trans[u][s[i] - 'a'] = v;
			}
			u = v;
		}
		id[u] = x;
	}

	std::vector<std::vector<int>> E;
	int idx;
	std::vector<int> dfn, sz;

	void dfs(int u) {
		dfn[u] = idx++;
		sz[u] = 1;
		for (int v : E[u]) {
			dfs(v);
			sz[u] += sz[v];
		}
	}

	std::vector<int> up;

	void build() {
		E.clear();
		E.resize(cnt);
		up.resize(cnt);
		up[rt] = rt;
		std::vector<int> Q;
		for (int i = 0; i < C; ++i) {
			if (trans[rt][i] != -1) {
				Q.push_back(trans[rt][i]);
				fail[trans[rt][i]] = rt;
			} else {
				trans[rt][i] = rt;
			}
		}
		for (int k = 0; k < (int)Q.size(); ++k) {
			int u = Q[k];
			E[fail[u]].push_back(u);
			if (id[u] != -1) {
				up[u] = u;
			} else {
				up[u] = up[fail[u]];
			}
			for (int i = 0; i < C; ++i) {
				int v = trans[u][i];
				if (v == -1) {
					trans[u][i] = trans[fail[u]][i];
				} else {
					fail[v] = trans[fail[u]][i];
					Q.push_back(v);
				}
			}
		}
		idx = 0;
		dfn.resize(cnt), sz.resize(cnt);
		dfs(rt);
	}
};

struct BIT {
	int n;
	std::vector<int> c;

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}

public:
	BIT(int _n) : n(_n), c(n + 1) {}

	void add(int x, int v) {
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int l, int r) {
		return query(r) - query(l);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	ACAM T;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		T.insert(a[i], i);
	}
	T.build();
	BIT S(T.cnt);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int u = T.rt;
		std::vector<std::pair<int, int>> vec(a[i].size());
		for (int j = 0; j < (int)a[i].size(); ++j) {
			u = T.trans[u][a[i][j] - 'a'];
			S.add(T.dfn[u], 1);
			int v = T.up[T.id[u] == i ? T.fail[u] : u];
			if (T.id[v] != -1) {
				vec[j] = std::make_pair(j - (int)a[T.id[v]].size() + 1, v);
			} else {
				vec[j] = std::make_pair(-1, -1);
			}
		}
		std::map<int, int> mp;
		int mn = a[i].size();
		for (int j = (int)a[i].size() - 1; j >= 0; --j) {
			if (vec[j].first != -1 && mn > vec[j].first) {
				mn = vec[j].first;
				++mp[vec[j].second];
			}
		}
		for (auto p : mp) {
			int v = p.first;
			if (S.query(T.dfn[v], T.dfn[v] + T.sz[v]) == p.second) {
				++ans;
			}
		}
		u = T.rt;
		for (int j = 0; j < (int)a[i].size(); ++j) {
			u = T.trans[u][a[i][j] - 'a'];
			S.add(T.dfn[u], -1);
		}
	}
	std::cout << ans << "\n";
}