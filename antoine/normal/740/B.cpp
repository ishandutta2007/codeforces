
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

struct LazyST {
	struct Val { // define
		int v = 0;
		Val() {}
		Val(const int v) : v(v) {}
		Val(const Val &v1, const Val &v2) {
			v = v1 + v2;
		}
		operator int() const {
			return v;
		}
	};

	int n;
	int stOffset;
	int stHi;
	vector<Val> st;
	vector<Val> lazy;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	void build() { // O(n)
		for (int i = 0; i < n; ++i)
			cin >> st[i + stOffset].v;
		for (int si = stOffset - 1; si; --si)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}

	void addLazy(const Val &v, const int si) { // define
		lazy[si].v += v;
	}

	void updateLazy(const int si, const int lo, const int hi) { // define
		st[si].v += lazy[si] * (hi - lo + 1);
		if (lo != hi) {
			lazy[si << 1].v += lazy[si];
			lazy[si << 1 | 1].v += lazy[si];
		}
		lazy[si] = 0;
	}

	Val query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return Val(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	Val query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : Val();
	}

	void update(const int i, const int j, const Val &v, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j) {
			addLazy(v, si);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < i || j < lo)
				return;
			int mid = (lo + hi) >> 1;
			update(i, j, v, si << 1, lo, mid);
			update(i, j, v, si << 1 | 1, mid + 1, hi);
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const int j, const Val v) {
		if (i <= j)
			update(i, j, v, 1, 0, stHi);
	}

	// remove all non-zero values in a range
	void remAll(const int i, const int j, const int si, const int lo, const int hi, vector<int> &res) {
		updateLazy(si, lo, hi);
		if (!st[si] || hi < i || j < lo)
			return;
		if (lo == hi) {
			res.push_back(si - stOffset);
			st[si] = 0;
		}
		else {
			int mid = (lo + hi) >> 1;
			remAll(i, j, si << 1, lo, mid, res);
			remAll(i, j, si << 1 | 1, mid + 1, hi, res);
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
		}
	}

	vector<int> remAll(const int i, const int j) { // ^^
		vector<int> res;
		remAll(i, j, 1, 0, stHi, res);
		return res;
	}

	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			int mid = (lo + hi) >> 1;
			updateAllLazy(si >> 1, lo, mid);
			updateAllLazy(si >> 1 | 1, mid + 1, hi);
		}
	}

	void updateAllLazy() {
		updateAllLazy(1, 0, stHi);
	}

	const Val * const retreive() {
		updateAllLazy();
		return &st[stOffset];
	}

	vector<Val> retreiveVector() {
		updateAllLazy();
		return vector<Val>(&st[stOffset], &st[stOffset + n]);
	}

	void output() {
		updateAllLazy();
		for (int i = 0; i < n; ++i) {
			if (i)
				cout << ' ';
			cout << st[stOffset + i].v;
		}
		cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	LazyST st(n);
	st.build();
	int ans = 0;
	while (m-- > 0) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		ans += max(0, st.query(l, r).v);
	}
	cout << ans;
	return 0;
}