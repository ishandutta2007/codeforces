#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// https://codeforces.com/contest/1010/problem/E

const int Inf = (int) 1e6;

struct V {
	int first = -Inf, second = Inf;
	V() {
	}
	V(const V v1, const V v2) {
		first = max(v1.first, v2.first);
		second = min(v1.second, v2.second);
	}
};

bool compByFirst(const pair<pair<int, int>, V> &lhs,
		const pair<pair<int, int>, V> &rhs) {
	return lhs.first.first < rhs.first.first;
}

bool compBySecond(const pair<pair<int, int>, V> &lhs,
		const pair<pair<int, int>, V> &rhs) {
	return lhs.first.second < rhs.first.second;
}

struct SegTree1D {
	struct Node {
		int split;
		V v;
	};
	int n = 0;
	vector<Node> st;
	SegTree1D() {}

	typedef vector<pair<pair<int, int>, V>>::iterator ItType;

	SegTree1D(ItType first, ItType last) {
		n = last - first;
		assert(n > 0);
		assert(is_sorted(first, last, compBySecond));
		init(first, last, 1, 0, n - 1);
	}

	void init(ItType first, ItType last, const int si, const int lo,
			const int hi) {
		if (lo == hi) {
			assert(first + 1 == last);
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si].split = first->first.second;
			st[si].v = first->second;
		} else {
			const ItType midIt = first + (last - first) / 2;
			const int midIdx = lo + (hi + 1 - lo) / 2;
			init(first, midIt, si << 1, lo, midIdx - 1);
			init(midIt, last, si << 1 | 1, midIdx, hi);
			st[si].split = midIt->first.second;
			st[si].v = V(st[si << 1].v, st[si << 1 | 1].v);
		}
	}

	V query(const int ql, const int qr) {
		return query(ql, qr, 1, 0, n - 1, -Inf, Inf);
	}
	V query(const int ql, const int qr, const int si, const int lo,
			const int hi, const int vl, const int vr) {
		assert(vl <= vr && ql <= qr);
		if ((ql <= vl && vr <= qr)
				|| (lo == hi && ql <= st[si].split && st[si].split <= qr))
			return st[si].v;

		if (lo == hi || vr < ql || qr < vl)
			return V();

		const int midIdx = lo + (hi + 1 - lo) / 2;
		const V res1 = query(ql, qr, si << 1, lo, midIdx - 1, vl, st[si].split);
		const V res2 = query(ql, qr, si << 1 | 1, midIdx, hi, st[si].split, vr);
		return V(res1, res2);
	}
};

struct SegTree2D {
	struct Node {
		int split;
		SegTree1D st;
	};

	int n;
	vector<Node> st;

	typedef vector<pair<pair<int, int>, V>>::iterator ItType;

	SegTree2D(const map<pair<int, int>, V> &mp) {
		n = (int) mp.size();
		if (!n)
			return;
		vector<pair<pair<int, int>, V>> v(mp.begin(), mp.end());
		init(v.begin(), v.end(), 1, 0, n - 1);
	}

	void init(ItType first, ItType last, const int si, const int lo,
			const int hi) {
		assert(first < last);
		assert(is_sorted(first, last, compByFirst));
		assert((lo == hi) == (first + 1 == last));
		if (si >= (int) st.size())
			st.resize(si + 1);
		if (lo == hi) {
			st[si].split = first->first.first;
		} else {
			const ItType midIt = first + (last - first) / 2;
			const int midIdx = lo + (hi + 1 - lo) / 2;
			st[si].split = midIt->first.first;
			init(first, midIt, si << 1, lo, midIdx - 1);
			init(midIt, last, si << 1 | 1, midIdx, hi);
			inplace_merge(first, midIt, last, compBySecond);
		}
		st[si].st = SegTree1D(first, last);
	}

	V query(const int qlx, const int qrx, const int qly, const int qry) {
		if (!n)
			return V();
		return query(qlx, qrx, qly, qry, 1, 0, n - 1, -Inf, Inf);
	}

	V query(const int qlx, const int qrx, const int qly, const int qry,
			const int si, const int lo, const int hi, const int vl,
			const int vr) {

		assert(vl <= vr && qlx <= qrx && qly <= qry);

		if ((qlx <= vl && vr <= qrx)
				|| (lo == hi && qlx <= st[si].split && st[si].split <= qrx))
			return st[si].st.query(qly, qry);

		if (lo == hi || vr < qlx || qrx < vl)
			return V();

		const int midIdx = lo + (hi + 1 - lo) / 2;
		const V res1 = query(qlx, qrx, qly, qry, si << 1, lo, midIdx - 1, vl,
				st[si].split);
		const V res2 = query(qlx, qrx, qly, qry, si << 1 | 1, midIdx, hi,
				st[si].split, vr);
		return V(res1, res2);
	}
};

struct Range3D {
	int xl = Inf, xr = -Inf;
	int yl = Inf, yr = -Inf;
	int zl = Inf, zr = -Inf;

	void insert(const int x, const int y, const int z) {
		xl = min(xl, x);
		yl = min(yl, y);
		zl = min(zl, z);
		xr = max(xr, x);
		yr = max(yr, y);
		zr = max(zr, z);
	}

	bool contains(const int x, const int y, const int z) const {
		return xl <= x && x <= xr && yl <= y && y <= yr && zl <= z && z <= zr;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int xMax, yMax, zMax;
	int n, m, k;
	cin >> xMax >> yMax >> zMax >> n >> m >> k;

	Range3D whiteRange;

	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		whiteRange.insert(x, y, z);
	}

	map<pair<int, int>, V> mp;
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (whiteRange.contains(x, y, z)) {
			cout << "INCORRECT\n";
			return 0;
		}

		V &range = mp.insert( { { x, y }, V() }).first->second;
		if (z <= whiteRange.zr)
			range.first = max(range.first, z);
		if (z >= whiteRange.zl)
			range.second = min(range.second, z);
	}

	cout << "CORRECT\n";

	SegTree2D st(mp);

	for (int i = 0; i < k; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (whiteRange.contains(x, y, z)) {
			cout << "OPEN\n";
			continue;
		}
		Range3D range = whiteRange;
		range.insert(x, y, z);
		auto res = st.query(range.xl, range.xr, range.yl, range.yr);
		bool ok = false;
		for (const int z : { res.first, res.second })
			ok |= (range.zl <= z && z <= range.zr);
		cout << (ok ? "CLOSED" : "UNKNOWN") << '\n';
	}
	return 0;
}