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

const int MaxA = 1e6;
int dp[MaxA + 1] = { 0 };

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

	LazyST(const int n, istream &in) : LazyST(n) { // O(n)
		for (int i = 0; i < n; ++i)
			in >> st[i + stOffset];
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
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
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
	}

	void update(const int i, const int j, const int si, const int lo, const int hi) {
		if (hi < i || j < lo || !st[si].countG2)
			return;
		if (lo == hi)
			st[si] = T(dp[st[si].v]);
		else {
			int mid = (lo + hi) >> 1;
			update(i, j, si << 1, lo, mid);
			update(i, j, si << 1 | 1, mid + 1, hi);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const int j) {
		if (i <= j)
			update(i, j, 1, 0, stHi);
	}
};

struct StVal { // define
	long long v = 0;
	int countG2 = 0;
	StVal() {}
	StVal(const int v) : v(v) { countG2 = v > 2; }
	StVal(const StVal &v1, const StVal &v2) {
		v = v1.v + v2.v;
		countG2 = v1.countG2 + v2.countG2;
	}
	friend istream& operator >> (istream &in, StVal &v) {
		int x;
		cin >> x;
		v = StVal(x);
		return in;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= MaxA; ++i)
		for (int j = i; j <= MaxA; j += i)
			++dp[j];

	int n, m;
	cin >> n >> m;
	LazyST<StVal> st(n, cin);
	while (m-- > 0) {
		int t, l, r;
		cin >> t >> l >> r;
		--t, --l, --r;
		if (t)
			cout << st.query(l, r).v << '\n';
		else
			st.update(l, r);
	}
	return 0;
}