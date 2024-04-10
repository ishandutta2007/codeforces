#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<class V> struct SegTree {
	int n = 0;
	vector<V> st;
	vector<int> leaves;

	SegTree() {
	}
	;

	SegTree(const int n) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
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

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
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

	void update(const int i, const int _add) {
		int si = leaves[i];
		st[si].v += _add;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	int v = 0; // optional
	StVal() {
	}
	StVal(const int v) :
			v(v) {
	}
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
	operator int() const {
		return v;
	}
};

typedef SegTree<StVal> MyST;

int id[256];

int min(const set<int> &s) {
	return s.empty() ? (int) 1e6 : *s.begin();
}

int max(const set<int> &s) {
	return s.empty() ? 0 : *s.rbegin();
}

set<pair<int, int>> intersection(set<pair<int, int>> s1, set<pair<int, int>> s2) {
	set<pair<int, int>> res;
	auto it1 = s1.begin(), it2 = s2.begin();
	while (it1 != s1.end() && it2 != s2.end()) {
		if (it1->second < it2->first)
			++it1;
		else if (it2->second < it1->first)
			++it2;
		else {
			res.insert( { max(it1->first, it2->first), min(it1->second, it2->second) });
			if (it1->second < it2->second)
				++it1;
			else
				++it2;
		}
	}
	return res;
}

char a[(int) 2e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	id['R'] = 0;
	id['P'] = 2;
	id['S'] = 1;

	int n, q;
	cin >> n >> q;

	MyST st[3];
	for (auto &&x : st)
		x = MyST(n + 1);

	array<set<int>, 3> arr;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		arr[id[(int) a[i]]].insert(i);
		st[id[(int) a[i]]].update(i, 1);
	}

	for (;;) {

		int ans = 0;
		for (int rep = 0; rep < 3; ++rep) {
			set<pair<int, int>> ranges1;
			{
				const int bound = min(n + 1, min(min(arr[(rep + 1) % 3]), min(arr[(rep + 2) % 3])));
				if (1 < bound)
					ranges1.insert( { 1, bound - 1 });

				set<int> &S = arr[(rep + 1) % 3];
				const int x = min(S);
				if (x < n)
					ranges1.insert( { x + 1, n });
			}

			set<pair<int, int>> ranges2;
			{
				const int bound = max(max(arr[(rep + 1) % 3]), max(arr[(rep + 2) % 3]));
				if (bound < n)
					ranges2.insert( { bound + 1, n });

				set<int> &S = arr[(rep + 1) % 3];
				const int x = max(S);

				if (x > 1)
					ranges2.insert( { 1, x - 1 });
			}

			set<pair<int, int>> ranges = intersection(ranges1, ranges2);

			for (auto &&range : ranges)
				ans += st[rep].query(range.first, range.second);
		}

		cout << ans << '\n';

		if (q-- == 0)
			break;

		int p;
		char c;
		cin >> p >> c;

		arr[id[(int) a[p]]].erase(p);
		st[id[(int) a[p]]].update(p, -1);

		a[p] = c;

		arr[id[(int) a[p]]].insert(p);
		st[id[(int) a[p]]].update(p, 1);

	}
	return 0;
}