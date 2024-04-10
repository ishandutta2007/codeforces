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
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


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
		for (int i = 0; i < n; ++i) {
			int x;
			in >> x;
			st[i + stOffset] = T(x);
		}
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
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
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

struct StVal {
	ll contrib[10];
	StVal() {
		memset(contrib, 0, sizeof contrib);
	}
	StVal(int x) {
		memset(contrib, 0, sizeof contrib);
		int p10 = 1;
		for (int i = 0; x; ++i, x /= 10, p10 *= 10)
			contrib[x % 10] += p10;
	}
	StVal(const StVal &v1, const StVal &v2) {
		for (int i = 0; i < 10; ++i)
			contrib[i] = v1.contrib[i] + v2.contrib[i];
	}
};

struct StUpdate {
	char mp[10];
	StUpdate() {
		for (int i = 0; i <= 9; ++i)
			mp[i] = i;
	}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		for (int i = 0; i <= 9; ++i)
			mp[i] = u2.mp[u1.mp[i]];
	}
	void apply(StVal &v, const int lo, const int hi) {
		ll * newC = new ll[10];
		fill(newC, newC + 10, 0);
		for (int i = 0; i < 10; ++i)
			newC[mp[i]] += v.contrib[i];
		for (int i = 0; i < 10; ++i)
			v.contrib[i] = newC[i];
		delete[] newC;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	LazyST<StVal, StUpdate> st(n, cin);

	for (int i = 0; i < q; ++i) {
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		if (type == 1) {
			int x, y;
			cin >> x >> y;
			StUpdate u;
			u.mp[x] = y;
			st.update(l, r, u);
		}
		else {
			assert(type == 2);
			StVal v = st.query(l, r);
			ll res = 0;
			for (int d = 1; d <= 9; ++d)
				res += d * v.contrib[d];
			cout << res << '\n';
		}
	}
	return 0;
}