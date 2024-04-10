#include <bits/stdc++.h>

using namespace std;

template <class T> struct LazySeg {
	std::vector<T> sum, lazy;
	int sz;

	void init(vector<T> v) {
		sz = 1;
		int sz_ = (int)v.size();
		while (sz < sz_) sz *= 2;
		sum.assign(2 * sz, 0);
		lazy.assign(2 * sz, 0);
		for (int i = 0; i < sz_; ++i) {
			sum[i + sz] = v[i];
		}
		for (int i = sz - 1; i >= 1; --i) {
			pull(i);
		}
	}

	void push(int ind, int L, int R) {
		if (lazy[ind] == 0) {
			return;
		}
		sum[ind] += lazy[ind];
		if (L != R) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	void pull(int ind) {
		sum[ind] = max(sum[2 * ind], sum[2 * ind + 1]);
	}

	void build() {
		for (int i = sz - 1; i >= 1; i--) {
			pull(i);
		}
	}

	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return;
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

	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return max(qsum(lo, hi, 2 * ind, L, M), qsum(lo, hi, 2 * ind + 1, M + 1, R));
	}

	int greater(int x, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (L == R) {
			if (sum[ind] > x) {
				return L;
			} else {
				return sz;
			}
		}
		int M = (L + R) / 2;
		push(2 * ind, L, M);
		if (sum[2 * ind] > x) {
			return greater(x, 2 * ind, L, M);
		} else {
			return greater(x, 2 * ind + 1, M + 1, R);
		}
	}
};

struct Data {
	LazySeg<int> seg;
	int cur = 0;
	int sz = 0;

	void init(vector<int>& v) { 
		seg.init(v);
		sz = (int)v.size();
	}

	void update(int x) {
		int idx = seg.greater(x);
		seg.upd(0, idx - 1, 1);
	}

	int query() {
		if (cur >= sz) {
			return -1;
		} else {
			return seg.qsum(cur, cur);
		}
	}

	void pop() {
		++cur;
	}
};

void solve_case(int tc = 0) {
	const long long INF = 1e18;
	const int A = 26;
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - 'a';
		b[i] = t[i] - 'a';
	}
	vector<int> c = a;
	sort(c.begin(), c.end());
	long long ans = INF;
	if (c > b) {
		ans = -1;
	} else {
		vector<vector<int>> locs(A);
		vector<Data> store(A);
		for (int i = 0; i < n; ++i) {
			locs[a[i]].push_back(i);
		}
		for (int i = 0; i < A; ++i) {
			store[i].init(locs[i]);
		}
		long long cur = 0;
		for (int i = 0; i < n; ++i) {
			if (i) {
				int x = store[b[i - 1]].query();
				if (x == -1) {
					break;
				}
				cur += abs(x - (i - 1));
				for (int j = 0; j < A; ++j) {
					if (j == b[i - 1]) {
						store[j].pop();
					} else {
						store[j].update(x);
					}
				}
			}
			long long res = cur;
			long long add = INF;
			for (int j = 0; j < b[i]; ++j) {
				int x = store[j].query();
				if (x != -1) {
					add = min(add, (long long)abs(x - i));
				}
			}
			res += add;
			ans = min(ans, res);
		}
	}
	if (ans >= INF) {
		ans = -1;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.in", "r", stdin);
#endif
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}