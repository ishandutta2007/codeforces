#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<int> mx;

	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			mx[u] = v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		mx[u] = std::max(mx[u << 1], mx[u << 1 | 1]);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return mx[u];
		}
		int mid = (l + r + 1) >> 1;
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::max(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	void build(int _n) {
		n = _n;
		mx.resize(enlarge(n) << 1, -1);
	}

	void modify(int x, int v) {
		modify(1, 0, n, x, v);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

class AC_Automaton {
	const int C = 26;

	int cnt, rt;
	std::vector<std::vector<int>> trans;
	std::vector<int> fail;
	std::vector<std::multiset<int>> S;
	std::vector<std::pair<int, int>> nd;

	int new_node() {
		trans.push_back(std::vector<int>(C, -1));
		fail.push_back(-1);
		S.emplace_back();
		return cnt++;
	}

	std::vector<std::vector<int>> E;
	std::vector<int> sz, son, top, dfn, id;

	void dfs1(int u) {
		sz[u] = 1;
		son[u] = -1;
		for (int v : E[u]) {
			dfs1(v);
			sz[u] += sz[v];
			if (son[u] == -1 || sz[v] > sz[son[u]]) {
				son[u] = v;
			}
		}
	}

	void dfs2(int u, int tp) {
		top[u] = tp;
		dfn[u] = id.size();
		id.push_back(u);
		if (son[u] != -1) {
			dfs2(son[u], tp);
		}
		for (int v : E[u]) {
			if (v != son[u]) {
				dfs2(v, v);
			}
		}
	}

	SegmentTree T;

	int query(int u) {
		int ans = -1;
		while (top[u] != rt) {
			ans = std::max(ans, T.query(dfn[top[u]], dfn[u] + 1));
			u = fail[top[u]];
		}
		ans = std::max(ans, T.query(dfn[rt], dfn[u] + 1));
		return ans;
	}

public:
	AC_Automaton() : cnt(0), rt(-1) {
		rt = new_node();
	}

	void insert(std::string s) {
		int u = rt;
		for (int i = 0; i < (int)s.size(); ++i) {
			int v = trans[u][s[i] - 'a'];
			if (v == -1) {
				v = new_node();
			}
			trans[u][s[i] - 'a'] = v;
			u = v;
		}
		S[u].insert(0);
		nd.emplace_back(u, 0);
	}

	void build() {
		std::vector<int> Q;
		fail[rt] = -1;
		for (int i = 0; i < C; ++i) {
			if (trans[rt][i] != -1) {
				Q.push_back(trans[rt][i]);
				fail[trans[rt][i]] = rt;
			} else {
				trans[rt][i] = rt;
			}
		}
		E.resize(cnt);
		for (int k = 0; k < (int)Q.size(); ++k) {
			int u = Q[k];
			E[fail[u]].push_back(u);
			for (int i = 0; i < C; ++i) {
				if (trans[u][i] != -1) {
					Q.push_back(trans[u][i]);
					fail[trans[u][i]] = trans[fail[u]][i];
				} else {
					trans[u][i] = trans[fail[u]][i];
				}
			}
		}

		sz.resize(cnt), son.resize(cnt, -1), top.resize(cnt), dfn.resize(cnt);
		dfs1(rt), dfs2(rt, rt);
		T.build(cnt);
		for (auto v : nd) {
			T.modify(dfn[v.first], v.second);
		}
	}

	void modify(int x, int v) {
		int u = nd[x].first;
		S[u].erase(S[u].find(nd[x].second));
		S[u].insert(v);
		nd[x].second = v;
		T.modify(dfn[u], *S[u].rbegin());
	}

	int query(std::string s) {
		int u = rt;
		int ans = -1;
		for (int i = 0; i < (int)s.size(); ++i) {
			u = trans[u][s[i] - 'a'];
			ans = std::max(ans, query(u));
		}
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	AC_Automaton T;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		T.insert(s);
	}
	T.build();
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x, v;
			std::cin >> x >> v;
			--x;
			T.modify(x, v);
		} else {
			std::string s;
			std::cin >> s;
			std::cout << T.query(s) << "\n";
		}
	}
}