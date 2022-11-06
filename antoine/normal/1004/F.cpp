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

int X;

template<class V> struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= st.size()) st.resize(si + 1);
			int x;
			cin >> x;
			st[si] = V(x);
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}


	V query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V(); }
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r)
			return st[si];
		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, int x) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si] = V(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	int len = 0;
	ll ans;
	vector<pair<int, int>> vInc, vDec;

	StVal() {}

	StVal(const int x) {
		len = 1;
		ans = x >= X;
		vInc = vDec = { {0, x} };
	}

	StVal(const StVal &val1, const StVal &val2) {
		assert(val1.len && val2.len);
		len = val1.len + val2.len;
		ans = val1.ans + val2.ans;

		const vector<pair<int, int>> &v1 = val1.vDec;
		const vector<pair<int, int>> &v2 = val2.vInc;
		for (int i = 0, j = 0; i < v1.size(); ++i) {
			while (j < v2.size() && (v1[i].second | v2[j].second) < X) j++;
			if (j >= v2.size()) break;
			ans += (ll)(v1[i].first + 1LL - (i ? v1[i - 1].first + 1LL : 0LL)) * (val2.len - v2[j].first);
		}
		
		vInc = val1.vInc;
		for (auto &&x : val2.vInc) {
			const int x1 = x.first + val1.len;
			const int x2 = x.second | vInc.back().second;
			if (x2 != vInc.back().second)
				vInc.emplace_back(x1, x2);
		}

		vDec = val2.vDec;
		reverse(vDec.begin(), vDec.end());
		for (auto &&x : vDec)
			x.first = val2.len - 1 - x.first;
		for (auto it = val1.vDec.rbegin(); it != val1.vDec.rend(); ++it) {
			const int x1 = (val1.len - 1 - it->first) + val2.len;
			const int x2 = it->second | vDec.back().second;
			if (x2 != vDec.back().second)
				vDec.emplace_back(x1, x2);
		}
		reverse(vDec.begin(), vDec.end());
		for (auto &&x : vDec)
			x.first = len - 1 - x.first;
	}
};

typedef SegTree<StVal> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m >> X;
	MyST st(n);
	while (m--) {
		int type;
		cin >> type;
		assert(type == 1 || type == 2);
		if (type == 1) {
			int i, y;
			cin >> i >> y;
			--i;
			st.update(i, y);
		}
		else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << st.query(l, r).ans << '\n';
		}
	}
	return 0;
}