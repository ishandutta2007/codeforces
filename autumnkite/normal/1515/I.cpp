#include <bits/stdc++.h>

const int LG = 52;

int enlarge_to_pow2(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

struct Node {
	long long sw[LG], sv[LG], mn[LG];

	Node() {}

	Node(long long a, long long w, long long v) {
		for (int i = 0; i < LG; ++i) {
			if (w < (1ll << i)) {
				sw[i] = a * w, sv[i] = a * v;
			} else {
				sw[i] = sv[i] = 0;
			}
			if (a && w >= (1ll << i)) {
				mn[i] = w;
			} else {
				mn[i] = 1ll << LG;
			}
		}
	}
};

Node operator+(const Node &a, const Node &b) {
	Node res;
	for (int i = 0; i < LG; ++i) {
		res.sw[i] = a.sw[i] + b.sw[i];
		res.sv[i] = a.sv[i] + b.sv[i];
		res.mn[i] = std::min(a.mn[i], a.sw[i] + b.mn[i]);
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<long long> a, w, v;
	std::vector<Node> val;

	void build(int u, int l, int r) {
		if (l + 1 == r) {
			val[u] = Node(a[l], w[l], v[l]);
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid, r);
		val[u] = val[u << 1] + val[u << 1 | 1];
	}

	void modify(int u, int l, int r, int x) {
		if (l + 1 == r) {
			val[u] = Node(a[x], w[x], v[x]);
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x);
		} else {
			modify(u << 1 | 1, mid, r, x);
		}
		val[u] = val[u << 1] + val[u << 1 | 1];
	}

	std::pair<long long, long long> query(int u, int l, int r, long long c, int k) {
		if (c == 0) {
			return std::make_pair(0ll, 0ll);
		}
		while (k > 0 && (1ll << k) > c) {
			--k;
		}
		if (l + 1 == r) {
			long long t = std::min(c / w[l], a[l]);
			return std::make_pair(t * w[l], t * v[l]);
		}
		int mid = (l + r + 1) >> 1;
		std::pair<long long, long long> left(0, 0);
		if (val[u << 1].mn[k] <= c || c < val[u << 1].sw[k]) {
			left = query(u << 1, l, mid, c, k);
		} else {
			left = std::make_pair(val[u << 1].sw[k], val[u << 1].sv[k]);
		}
		std::pair<long long, long long> right(query(u << 1 | 1, mid, r, c - left.first, k));
		return std::make_pair(left.first + right.first, left.second + right.second);
	}

public:
	SegmentTree(std::vector<long long> _a, std::vector<long long> _w, std::vector<long long> _v)
	  : n(_a.size()), a(_a), w(_w), v(_v), val(enlarge_to_pow2(n) << 1) {
		build(1, 0, n);
	}

	void modify(int x, long long c) {
		a[x] += c;
		modify(1, 0, n, x);
	}

	long long query(long long c) {
		return query(1, 0, n, c, LG - 1).second;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<std::tuple<int, int, int, int>> vec;
	for (int i = 0; i < n; ++i) {
		int a, w, v;
		std::cin >> a >> w >> v;
		vec.emplace_back(-v, w, a, i);
	}
	std::sort(vec.begin(), vec.end());

	std::vector<long long> a(n), w(n), v(n);
	std::vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		a[i] = std::get<2>(vec[i]);
		w[i] = std::get<1>(vec[i]);
		v[i] = -std::get<0>(vec[i]);
		pos[std::get<3>(vec[i])] = i;
	}
	SegmentTree T(a, w, v);
	while (q--) {
		int op;
		long long c;
		std::cin >> op >> c;
		if (op <= 2) {
			int x;
			std::cin >> x;
			--x;
			x = pos[x];
			if (op == 1) {
				T.modify(x, c);
			} else {
				T.modify(x, -c);
			}
		} else {
			c = std::min(c, (1ll << LG) - 1);
			std::cout << T.query(c) << "\n";
		}
	}
}