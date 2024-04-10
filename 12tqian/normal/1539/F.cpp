#include <bits/stdc++.h>

using namespace std;

template <class T> struct LazySeg {
	vector<T> mx, mn, lazy;
	int sz, n;

	void init(int sz_) {
		n = sz_ - 1;
		sz = 1;
		while (sz < sz_) {
			sz *= 2;
		}
		mx.assign(2 * sz, 0);
		mn.assign(2 * sz, 0);
		lazy.assign(2 * sz, 0);
	}

	void push(int ind, int L, int R) {
		mx[ind] += lazy[ind];
		mn[ind] += lazy[ind];
		if (L != R) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	void pull(int ind) {
		mn[ind] = min(mn[2 * ind], mn[2 * ind + 1]);
		mx[ind] = max(mx[2 * ind], mx[2 * ind + 1]);
	}

	void build() {
		for (int i = sz - 1; i >= 1; i--) {
			pull(i);
		}
	}

	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) {
			R += sz;
		}
		push(ind, L, R);
		if (hi < L || R < lo) {
			return;
		}
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind, L, R);
			return;
		}
		int M = (L + R) / 2;
		upd(lo, hi, inc, 2 * ind, L, M);
		upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}

	T qmin(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) {
			R += sz;
		}
		push(ind, L, R);
		if (lo > R || L > hi) {
			return numeric_limits<T>::max();
		} else if (lo <= L && R <= hi) {
			return mn[ind];
		} else {	
			int M = (L + R) / 2;
			return min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 * ind + 1, M + 1, R));
		}
	}

	T qmax(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) {
			R += sz;
		}
		push(ind, L, R);
		if (lo > R || L > hi) {
			return numeric_limits<T>::min();
		} else if (lo <= L && R <= hi) {
			return mx[ind]; 
		} else {
			int M = (L + R) / 2; 
			return max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
		}
	}

	T query(int idx) {
		return qmax(idx, n) - qmin(0, idx - 1);
	}
};

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> loc(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		loc[a[i]].push_back(i);
	}
	vector<int> ans(n + 1);
	LazySeg<int> seg;
	seg.init(n + 1);
	for (int i = 1; i <= n; ++i) {
		seg.upd(i, i, i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int x : loc[i]) {
			int v = seg.query(x) - 2;
			v = (v + 2) / 2 * 2;
			ans[x] = max(ans[x], v);
		}
		for (int x : loc[i]) {
			seg.upd(x, n, -2);
		}
	}
	seg.init(n + 1);
	for (int i = 1; i <= n; ++i) {
		seg.upd(i, i, i);
	}
	for (int i = n; i >= 1; --i) {
		for (int x : loc[i]) {
			int v = seg.query(x) - 2;
			if (v % 2) {
				++v;
			}
			ans[x] = max(ans[x], v);
		}
		for (int x : loc[i]) {
			seg.upd(x, n, -2);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] / 2 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}