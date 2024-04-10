#include <bits/stdc++.h>

using namespace std;

struct Node {
	int l, r, size;
	long long left, right, total;
	bool full;
	
	Node(int x) : l(x), r(x), size(1), left(1), right(1), full(true), total(1) {}
	Node() : l(0), r(0), left(0), size(0), right(0), full(false), total(0) {}

	friend Node operator+(Node x, Node y) {
		Node res;
		res.l = x.l;
		res.r = y.r;
		res.full = false;
		res.size = x.size + y.size;
		res.left = x.left;
		res.right = y.right;
		res.total = x.total + y.total;
		if (x.r <= y.l) {
			if (x.full) {
				res.left += y.left;
			}
			if (y.full) {
				res.right += x.right;
			}
			res.total += x.right * y.left;
			res.full = x.full && y.full;
		}
		return res;
	}
};

struct SegmentTree {
	const Node ID = Node();

	int n;
	vector<Node> seg;

	Node comb(Node x, Node y) {
		if (x.size == 0) {
			return y;
		} else if (y.size == 0) {
			return x;
		} else {
			return x + y;
		}
	}

	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) {
		seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
	}

	void upd(int p, Node val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	Node query(int l, int r) {
		Node ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	SegmentTree seg;
	seg.init(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		seg.upd(i, Node(x));
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			--x;
			seg.upd(x, Node(y));
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			long long ans = seg.query(l, r).total;
			cout << ans << '\n';
		}
	}
	return 0;
}