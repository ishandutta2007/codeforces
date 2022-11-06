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

template<class T, class U> struct LazyST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;
	vector<U> lazy;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	LazyST(const int n, istream &in) : LazyST(n) { // O(n)
		for (int i = 0; i < n; ++i)
			in >> st[i + stOffset];
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = U(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = U();
	}

	T query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return T(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	T query(const int i, const int j) {
 		auto res = (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
		return res;
	}

	void update(const int i, const int j, const U &u, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < i || j < lo)
				return;
			int mid = (lo + hi) >> 1;
			update(i, j, u, si << 1, lo, mid);
			update(i, j, u, si << 1 | 1, mid + 1, hi);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const int j, const U u) {
		if (i <= j)
			update(i, j, u, 1, 0, stHi);
	}

	// remove and return all non-zero values in a range, assuming all values >= 0
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
			st[si] = T(st[si << 1], st[si << 1 | 1]);
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

	const T * const retreive() {
		updateAllLazy();
		return &st[stOffset];
	}

	vector<T> retreiveVector() {
		updateAllLazy();
		return vector<T>(&st[stOffset], &st[stOffset + n]);
	}
};

struct StVal { // define
	long long v = 0;
	StVal() {}
	StVal(const long long v) : v(v) {}
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
	operator long long() const {
		return v;
	}
};

struct StUpdate { // define
	long long v = 0;
	StUpdate() {}
	StUpdate(const long long v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		v = u1 + u2;
	}
	operator long long() const {
		return v;
	}
	void apply(StVal &v, const int lo, const int hi) {
		v.v += this->v * (hi - lo + 1);	
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	LazyST<StVal, StUpdate> st(n + 1);

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int s, f;
	cin >> s >> f;

	for (int i = 0; i < n; ++i) {
		st.update(s - i, f - 1 - i, a[i]);
		st.update(s - i + n, f - 1 - i + n, a[i]);
	}

	int ans;
	long long best = -1;
	for (int i = 1; i <= n; ++i) {
		auto v = st.query(i, i);
		if (v > best) {
			best = v;
			ans = i;
		}
	}
	cout << ans;	
	return 0;
}