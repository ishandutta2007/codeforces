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
#include <stack>

using namespace std;

typedef long long ll;

template<class T> struct LazyST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		stHi = st.size() - 1 - stOffset;
	}


	T query(const int i, const int j, const int si, const int lo, const int hi) {
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
		return query(i, j, 1, 0, stHi);
	}

	void update(const int i, const T v) {
		int si = stOffset + i;
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	ll a[2];
	StVal() { a[0] = a[1] = numeric_limits<ll>::min(); }
	StVal(const StVal &v1, const StVal &v2) {
		a[0] = max(v1.a[0], v2.a[0]);
		a[1] = max(v1.a[1], v2.a[1]);
	}
};

int n;
ll diff[(int)1e5]; // a[0] - a[1], a[1] - a[2], a[2] - a[3], ..., a[n-3] - a[n-2], a[n-2] - a[n-1]
ll sum = 0;
LazyST<StVal> st((int)1e5);

void updateST(int i) {
	if (!i || i == n - 1)
		return;
	StVal v;
	ll cp1 = min(max(diff[i - 1], 0ll), max(-diff[i], 0ll));
	ll cp2 = max(max(diff[i - 1], 0ll), max(-diff[i], 0ll));
	v.a[0] = -2 * cp1;
	v.a[1] = -2 * (cp1 + cp2);
	st.update(i, v);
}

void updateDiff(int i, ll x) {
	sum -= abs(diff[i]);
	diff[i] += x;
	sum += abs(diff[i]);
	updateST(i);
	updateST(i + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(diff, 0, sizeof diff);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		static int curr, prev;
		cin >> curr;
		if (i)
			updateDiff(i - 1, prev - curr);
		prev = curr;
	}

	int q;
	cin >> q;
	while (q-- > 0) {
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		--l, --r;
		if (t == 1) {// query
			auto v = st.query(l, r).a;
			ll res = max(-2ll * x, max(v[0], 2*x + v[1]));
			if (!l)
				res = max(res, -abs(diff[0]) + abs(diff[0] + x));
			if (r == n - 1)
				res = max(res, -abs(diff[n - 2]) + abs(diff[n - 2] - x));
			cout << (sum + res) << '\n';
		}
		else { // update
			if (l)
				updateDiff(l - 1, -x);
			if (r + 1 < n)
				updateDiff(r, x);
		}
	}
	return 0;
}