#include <bits/stdc++.h>

struct event {
	int x, l, r, v;
	
	event() {}
	event(int _x, int _l, int _r, int _v) : x(_x), l(_l), r(_r), v(_v) {}
	
	bool operator<(const event &rhs) const {
		return x < rhs.x;
	}
};

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	struct node {
		int mn, w;
		
		node operator+(const node &rhs) const {
			node res;
			res.mn = std::min(mn, rhs.mn);
			res.w = 0;
			if (res.mn == mn) {
				res.w ^= w;
			}
			if (res.mn == rhs.mn) {
				res.w ^= rhs.w;
			}
			return res;
		}
	};

	int n;
	std::vector<int> p;
	std::vector<node> a;
	std::vector<int> tag;
	
	void up(int u) {
		a[u] = a[u << 1] + a[u << 1 | 1];
		a[u].mn += tag[u];
	}

	void build(int u, int l, int r) {
		tag[u] = 0;
		if (l + 1 == r) {
			a[u].mn = 0, a[u].w = p[l] ^ p[r];
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid, r);
		up(u);
	}
	
	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			a[u].mn += v;
			tag[u] += v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (L < mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (mid < R) {
			modify(u << 1 | 1, mid, r, L, R, v);
		}
		up(u);
	}
	
public:
	segment_tree(const std::vector<int> &_p) : n((int)_p.size() - 1), p(_p), a(enlarge(n) << 1), tag(enlarge(n) << 1) {
		build(1, 0, n);
	}
	
	void modify(int l, int r, int v) {
		l = std::lower_bound(p.begin(), p.end(), l) - p.begin();
		r = std::lower_bound(p.begin(), p.end(), r) - p.begin();
		if (l < r) {
			modify(1, 0, n, l, r, v);
		}
	}
	
	int query() {
		return a[1].mn > 0 ? p[n] ^ p[0] : p[n] ^ p[0] ^ a[1].w;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m, lim;
	std::cin >> n >> m >> lim;
	std::vector<event> Q;
	std::vector<int> v;
	for (int i = 0; i < m; ++i) {
		int sx, sy, tx, ty;
		std::cin >> sx >> sy >> tx >> ty;
		--sx, --sy;
		Q.emplace_back(sx, sy, ty, 1);
		Q.emplace_back(tx, sy, ty, -1);
		v.push_back(sy);
		v.push_back(ty);
	}
	std::sort(Q.begin(), Q.end());
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	
	segment_tree T(v);
	int lst = 0;
	int ans = 0;
	for (auto p : Q) {
		ans ^= (p.x ^ lst) & (T.query());
		lst = p.x;
		T.modify(p.l, p.r, p.v);
	}
	
	int mask = 1;
	while (mask < lim) {
		mask = mask << 1 | 1;
	}
	std::cout << (ans & mask ? "Hamed" : "Malek") << "\n";
}