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

	void init(int n) {
		this->n = n;
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
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
		//cerr << "st update " << i << ' ' << j << ' ' << u << '\n';
		if (i <= j)
			update(i, j, u, 1, 0, stHi);
	}
};

struct StVal {
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

struct StUpdate {
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

struct Range {
	int l, r, x;
	bool operator<(const Range &other) const {
		if (l != other.l) return l < other.l;
		return r < other.r;
	}
};

int n;
set<Range> ranges;
LazyST<StVal, StUpdate> st;

void update(const int l, const int r, const int x) {
	auto it = ranges.lower_bound({ l, -1, -1 });
	for (; it != ranges.end() && it->r <= r; it = ranges.erase(it))
		st.update(it->l, it->r, abs(x - it->x));
	if (it != ranges.end() && it->l <= r) {
		st.update(it->l, r, abs(x - it->x));
		ranges.insert({ r + 1, it->r, it->x });
		it = ranges.erase(it);
	}
	if (it != ranges.begin() && (--it)->r >= l) {
		st.update(l, min(r, it->r), abs(x - it->x));
		ranges.insert({ it->l, l - 1, it->x });
		if (it->r > r)
			ranges.insert({ r + 1, it->r, it->x });
		ranges.erase(it);
	}
	ranges.insert({ l, r, x });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int m;
	cin >> n >> m;

	st.init(n);
	for (int i = 0; i < n; ++i)
		ranges.insert({ i, i, i + 1 });

	for (int i = 0; i < m; ++i) {
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		if (type == 1) {
			int x;
			cin >> x;
			update(l, r, x);
		}
		else {
			assert(type == 2);
			cout << st.query(l, r) << '\n';
		}
	}
	return 0;
}