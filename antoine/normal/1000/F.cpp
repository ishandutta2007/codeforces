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

/*
3 1 2 3
1 1 3
*/
struct T {
	bool leaf = true;
	int l, r, x;
	int minL, rMinL;
	T() {}
	T(const int i) : l(i + 1), r(i) {}
	T(const int l, const int r, const int x) : l(l), r(r), x(x) {}
	T(const T &t1, const T &t2) {
		assert(t1.leaf == t2.leaf);
		leaf = false;
		if (t1.leaf) {
			rMinL = t2.l;
			minL = min(t1.l, t2.l);
		} else {
			rMinL = t2.minL;
			minL = min(t1.minL, t2.minL);
		}
	}
};

int f(int n) {
	int mask = 1;
	while (mask < n)
		mask <<= 1;
	return mask;
}

struct ST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;

	ST(int n) {
		this->n = n = f(n);
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		stHi = st.size() - 1 - stOffset;
		for (int i = 0; i < n; ++i)
			st[stOffset + i] = T(i);
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	int query(const int i, const int si, const int lo, const int hi) {
		if (lo == hi) {
			assert(st[si].leaf);
			return st[si].l <= i && i <= st[si].r ? st[si].x : 0;
		}
		assert(!st[si].leaf);
		int mid = (lo + hi) >> 1;
		if (i >= st[si].rMinL)
			return query(i, si << 1 | 1, mid + 1, hi);
		return query(i, si << 1, lo, mid);
	}

	int query(const int i) {
		return query(i, 1, 0, stHi);
	}

	void update(const int i, const T v) {
		int si = stOffset + i;
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	void reset(const int i) {
		return update(i, T(i));
	}
};


vector<int> getLast(const vector<int> &a, const int n) {
	vector<int> last(n, -1);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		auto it = mp.find(a[i]);
		if (it == mp.end())
			mp[a[i]] = i;
		else {
			last[i] = it->second;
			it->second = i;
		}
	}
	return last;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> last = getLast(a, n);

	vector<vector<pair<int, int>>> queries(n);
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		queries[r].push_back({ i, l });
	}

	vector<int> ans(q, -2);

	ST st(n);

	for (int i = 0; i < n; ++i) {
		if (last[i] >= 0)
			st.reset(last[i]);
		st.update(i, { last[i] + 1, i, a[i] });

		for (const pair<int, int> &x : queries[i])
			ans[x.first] = st.query(x.second);
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
	return 0;
}