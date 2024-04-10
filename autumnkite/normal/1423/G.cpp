#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

struct node {
	int c;
	long long s;
	
	node() : c(0), s(0) {}
	node(int _c, long long _s) : c(_c), s(_s) {}
	
	node operator+(const node &rhs) const {
		return node(c + rhs.c, s + rhs.s);
	}
};

class segment_tree {
	int n;
	std::vector<node> a;
	
	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u].c += v;
			a[u].s += 1ll * v * x;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	
	node query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return query(u << 1, l, mid, L, R) + query(u << 1 | 1, mid, r, L, R);
		}
	}
	
public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1) {}
	
	void add(int x, int v) {
		modify(1, 0, n, x, v);
	}
	
	node query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::map<int, int> a;
	std::map<int, std::set<std::pair<int, int>>> S;
	a[-1] = a[n] = -1;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	segment_tree Tl(n + 2), Tr(n + 2), Tn(n + 2);
	long long ans = 0;
	int cnt = 0;
	
	auto add = [&](int i, int j, int p, int v) {
		Tl.add(i - p, v);
		Tr.add(n - j, v);
		Tn.add(n - p, v);
		ans += 1ll * (j - p) * v;
	};

	auto insert = [&](std::set<std::pair<int, int>> &S, int l, int r) {
		auto it = S.lower_bound(std::make_pair(r + 1, 0));
		int lst = it == S.begin() ? -1 : std::prev(it)->second;
		if (it != S.end()) {
			add(it->first, it->second, lst, -1);
			add(it->first, it->second, r, 1);
		}
		add(l, r, lst, 1);
		S.emplace(l, r);
	};
	
	auto erase = [&](std::set<std::pair<int, int>> &S, int l, int r) {
		auto it = S.find(std::make_pair(l, r)), nx = std::next(it);
		int lst = it == S.begin() ? -1 : std::prev(it)->second;
		if (nx != S.end()) {
			add(nx->first, nx->second, r, -1);
			add(nx->first, nx->second, lst, 1);
		}
		add(l, r, lst, -1);
		S.erase(it);
	};
	
	for (int i = 0; i < n; ++i) {
		insert(S[a[i]], i, i);
	}

	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			--l, --r;
			auto it = a.lower_bound(l);
			int lst = std::prev(it)->first;
			int pl = lst, cl = it->second;
			while (it->first <= r) {
				erase(S[it->second], lst + 1, it->first);
				lst = it->first;
				it = a.erase(it);
			}
			int pr = it->first, cr = it->second;
			if (pr < n) {
				erase(S[cr], lst + 1, pr);
			}
			if (pl < l - 1) {
				insert(S[cl], pl + 1, l - 1);
				a[l - 1] = cl;
			}
			insert(S[x], l, r);
			a[r] = x;
			if (pr < n) {
				insert(S[cr], r + 1, pr);
			}
		} else {
			int k;
			std::cin >> k;
			node pl = Tl.query(0, k), sl = Tl.query(k, n + 2);
			node pr = Tr.query(0, k), sr = Tr.query(k, n + 2);
			node pn = Tn.query(0, k);
			std::cout << ans - 1ll * pl.c * k - sl.s + pr.s + 1ll * sr.c * k + 1ll * pn.c * k - pn.s << "\n";
		}
	}
}