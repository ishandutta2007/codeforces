#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

class SegmentTree {
	int n;

	struct Node {
		Node *ls, *rs;
		long long mn;
		long long tag;

		Node() : ls(NULL), rs(NULL), mn(INF), tag(0) {}
		Node(long long v) : ls(NULL), rs(NULL), mn(v), tag(0) {}

		void up() {
			mn = INF;
			if (ls != NULL) {
				mn = std::min(mn, ls->mn);
			}
			if (rs != NULL) {
				mn = std::min(mn, rs->mn);
			}
		}

		void add_tag(long long v) {
			mn += v;
			tag += v;
		}

		void down() {
			if (ls != NULL) {
				ls->add_tag(tag);
			}
			if (rs != NULL) {
				rs->add_tag(tag);
			}
			tag = 0;
		}
	};

	Node *rt;

	void modify(Node *&u, int l, int r, int x, long long v) {
		if (u == NULL) {
			u = new Node();
		}
		if (l + 1 == r) {
			u->mn = v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		u->down();
		if (x < mid) {
			modify(u->ls, l, mid, x, v);
		} else {
			modify(u->rs, mid, r, x, v);
		}
		u->up();
	}

	long long query(Node *u, int l, int r, int x) {
		if (u == NULL) {
			return INF;
		}
		if (l + 1 == r) {
			return u->mn;
		}
		int mid = (l + r + 1) >> 1;
		u->down();
		if (x < mid) {
			return query(u->ls, l, mid, x);
		} else {
			return query(u->rs, mid, r, x);
		}
	}

	Node *merge(Node *u, Node *v, int l, int r) {
		if (u == NULL) {
			return v;
		}
		if (v == NULL) {
			return u;
		}
		if (l + 1 == r) {
			u->mn = std::min(u->mn, v->mn);
			return u;
		}
		u->down(), v->down();
		int mid = (l + r + 1) >> 1;
		u->ls = merge(u->ls, v->ls, l, mid);
		u->rs = merge(u->rs, v->rs, mid, r);
		u->up();
		return u;
	}

public:
	SegmentTree(int _n) : n(_n), rt(NULL) {}

	void modify(int x, long long v) {
		modify(rt, 0, n, x, v);
	}

	long long query(int x) {
		return query(rt, 0, n, x);
	}

	long long minimum() {
		if (rt == NULL) {
			return INF;
		} else {
			return rt->mn;
		}
	}

	void add(long long v) {
		if (rt != NULL) {
			rt->add_tag(v);
		}
	}

	void merge(const SegmentTree &T) {
		assert(n == T.n);
		rt = merge(rt, T.rt, 0, n);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, s;
	std::cin >> n >> s;
	int cnt = 1;
	int now = 0;
	std::vector<std::pair<int, int>> val(1);
	std::vector<int> fa(1, -1);
	int mx = s;
	for (int i = 0; i < n; ++i) {
		std::string op;
		std::cin >> op;
		if (op == "set") {
			int x, v;
			std::cin >> x >> v;
			mx = std::max(mx, x);
			++cnt;
			val.emplace_back(x, v);
			fa.emplace_back(now);
		} else if (op == "if") {
			int x;
			std::cin >> x;
			mx = std::max(mx, x);
			int u = cnt++;
			val.emplace_back(x, -1);
			fa.emplace_back(now);
			now = u;
		} else {
			now = fa[now];
		}
	}
	std::vector<std::vector<int>> E(cnt);
	for (int i = 0; i < cnt; ++i) {
		if (fa[i] != -1) {
			E[fa[i]].emplace_back(i);
		}
	}

	std::vector<SegmentTree> f(cnt, SegmentTree(mx + 1));
	std::function<void(int, int, long long)> dfs = [&](int u, int w, long long c) {
		f[u].modify(w, c);
		for (int v : E[u]) {
			if (val[v].second != -1) {
				if (val[v].first == s) {
					f[u].add(val[v].second);
				} else {
					long long mn = f[u].minimum();
					f[u].add(val[v].second);
					f[u].modify(val[v].first, mn);
				}
			} else {
				dfs(v, val[v].first, f[u].query(val[v].first));
				f[u].modify(val[v].first, INF);
				f[u].merge(f[v]);
			}
		}
	};
	dfs(0, 0, 0);
	std::cout << f[0].minimum() << "\n";
}