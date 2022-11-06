#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Range {
	int l, r;
	bool operator<(const Range &other) const {
		return l < other.l;
	}
};

vector<Range> filter(const vector<Range> &ranges) {
	assert(is_sorted(ranges.begin(), ranges.end()));
	vector<Range> res;
	for (const Range &range : ranges) {
		while (!res.empty() && res.back().r >= range.r)
			res.pop_back();
		if (!res.empty() && res.back().l == range.l && res.back().r <= range.r)
			continue;
		res.push_back(range);
	}
	return res;
}

vector<Range> merge(const vector<Range> &v1, const vector<Range> &v2) {
	vector<Range> res;
	auto it1 = v1.begin(), it2 = v2.begin();
	while (it1 != v1.end() && it2 != v2.end()) {
		const int r = max(it1->r, it2->r);
		if (it1->l < it2->l) {
			res.push_back( { it1->l, r });
			++it1;
		} else {
			res.push_back( { it2->l, r });
			++it2;
		}
	}
	return res;
}

struct V {
	vector<Range> ranges;
	V() {
	}
	V(const vector<Range> &_ranges) {
		ranges = filter(_ranges);
	}
	V(const V &v1, const V &v2) {
		ranges = merge(v1.ranges, v2.ranges);
		ranges = filter(ranges);
	}
	bool query(const int l, const int r) const {
		auto it = lower_bound(ranges.begin(), ranges.end(), Range{l, -1});
		return it != ranges.end() && it->r <= r;
	}
};

struct SegTree {
	int n;
	vector<V> st;

	SegTree(const vector<vector<Range>> &sets) {
		n = (int) sets.size();
		init(1, 0, n - 1, sets);
	}

	void init(const int si, const int lo, const int hi,
			const vector<vector<Range>> &sets) {
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si] = V(sets[lo]);
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, sets);
			init(si << 1 | 1, mid + 1, hi, sets);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}

	bool query(const int l, const int r, const int ql, const int qr) {
		assert(l <= r && l < n && r >= 0);
		return query(l, r, ql, qr, 1, 0, n - 1);
	}
	bool query(const int l, const int r, const int ql, const int qr,
			const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r)
			return st[si].query(ql, qr);

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, ql, qr, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, ql, qr, si << 1 | 1, mid + 1, hi);
		return query(l, r, ql, qr, si << 1, lo, mid)
				&& query(l, r, ql, qr, si << 1 | 1, mid + 1, hi);
	}

};

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n, q, k;
	cin >> n >> q >> k;

	vector<vector<Range>> sets(n + 1);
	for (int i = 0; i < k; ++i) {
		int l, r, p;
		cin >> l >> r >> p;
		sets[p].push_back( { l, r });
	}

	for (vector<Range> &v : sets)
		sort(v.begin(), v.end());

	SegTree st(sets);

	while (q--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		const bool res = st.query(a, b, x, y);
		cout << (res ? "yes" : "no") << endl;
	}
	return 0;
}