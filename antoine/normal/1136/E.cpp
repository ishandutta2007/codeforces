#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class V, class U> struct SegTree {
	int n;
	vector<V> st;
	vector<U> lazy;
	vector<int> leaves;

	SegTree(const int n) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = U(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = U();
	}

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r)
			return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const U u) {
		if (l <= r)
			update(l, r, u, 1, 0, n - 1);
	}
	void update(const int l, const int r, const U &u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		} else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo)
				return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}
};

struct StVal { // define
	ll v = 0; // optional
	StVal() {
	}
	StVal(const ll v) :
			v(v) {
	} // optional
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
	operator ll() const {
		return v;
	} // optional
};

struct StUpdate { // define
	ll v = 0; // optional
	StUpdate() {
	}
	StUpdate(const ll v) :
			v(v) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		v = u1 + u2;
	}
	operator ll() const {
		return v;
	} // optional
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.v += this->v * (hi - lo + 1);
	}
};

typedef SegTree<StVal, StUpdate> MyST;

struct Range {
	int l, r;
	Range(const int l, const int r) :
			l(l), r(r) {
		assert(l <= r);
	}
	~Range() {
	}
	bool operator<(const Range &other) const {
		if (l != other.l)
			return l < other.l;
		return r < other.r;
	}
};

const int MxN = (int) 1e5 + 9;
ll b[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	set<Range> ranges;
	MyST st(n + 1);

	for (int i = 1; i <= n; ++i) {
		ranges.emplace(i, i);
		ll x;
		cin >> x;
		st.update(i, i, x);
	}

	for (int i = 1; i < n; ++i)
		cin >> b[i];

	int Q;
	cin >> Q;
	while (Q--) {
		char type;
		int i, x;
		cin >> type >> i >> x;
		if (type == '+') {
			// cerr << "iter " << endl;
			auto it = --ranges.lower_bound( { i + 1, i + 1 });
			assert(it->l <= i && i <= it->r);
			// cerr << "iter " << endl;
			if (it->l != i) {
				const Range range = *it;
				ranges.erase(it);
				ranges.emplace(range.l, i - 1);
				it = ranges.emplace(i, range.r).first;
			}
			// cerr << "update " << it->l << ' ' << it->r << ' ' << x << endl;
			st.update(it->l, it->r, x);
			for (;;) {
				auto a = [&](int i) {
					return st.query(i, i).v;
				};

				auto it2 = next(it);
				if (it2 == ranges.end())
					break;

				x = a(it->r) + b[it->r] - a(it2->l);
				if (x <= 0)
					break;
				st.update(it2->l, it2->r, x);
				assert(it->l <= it2->r);
				const Range range(it->l, it2->r);
				ranges.erase(it);
				ranges.erase(it2);
				it = ranges.insert(range).first;
			}
		} else {
			assert(type == 's');
			cout << st.query(i, x) << '\n';
		}
		for (int i = 1; i <= n; ++i) {
			auto a = [&](int i) {
				return st.query(i, i).v;
			};

			// cerr << a(i) << ' ';

		}
		// cerr << endl;
	}
	return 0;
}