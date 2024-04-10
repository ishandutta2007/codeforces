#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

template<typename T> vector<int> suffix_array(const T &s, int n, int alpha) {
	vector<int> a(n);
	if (~alpha) {
		vector<int> bucket(alpha);
		for (int i = 0; i < n; ++i) {
			++bucket[s[i]];
		}
		int sum = 0;
		for (int i = 0; i < alpha; ++i) {
			int add = bucket[i];
			bucket[i] = sum;
			sum += add;
		}
		for (int i = 0; i < n; ++i) {
			a[bucket[s[i]]++] = i;
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			a[i] = i;
		}
		sort(a.begin(), a.end(), [&](const int &x, const int &y) {
			return s[x] < s[y];
		});
	}
	vector<int> sorted_by_second(n);
	vector<int> ptr_group(n);
	vector<int> new_group(n);
	vector<int> group(n);
	group[a[0]] = 0;
	for (int i = 1; i < n; ++i) {
		group[a[i]] = group[a[i - 1]] + (s[a[i]] != s[a[i - 1]]);
	}
	int step = 1;
	while (group[a[n - 1]] < n - 1) {
		int ptr = 0;
		for (int i = n - step; i < n; ++i) {
			sorted_by_second[ptr++] = i;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] >= step) {
				sorted_by_second[ptr++] = a[i] - step;
			}
		}
		for (int i = n - 1; ~i; --i) {
			ptr_group[group[a[i]]] = i;
		}
		for (int i = 0; i < n; ++i) {
			int x = sorted_by_second[i];
			a[ptr_group[group[x]]++] = x;
		}
		new_group[a[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (group[a[i]] != group[a[i - 1]]) {
				new_group[a[i]] = new_group[a[i - 1]] + 1;
			}
			else {
				int prev = a[i - 1] + step >= n ? -1 : group[a[i - 1] + step];
				int now = a[i] + step >= n ? -1 : group[a[i] + step];
				new_group[a[i]] = new_group[a[i - 1]] + (prev != now);
			}
		}
		group = new_group;
		step <<= 1;
	}
	return a;
}

template<typename T> vector<int> build_lcp(const T &s, int n, const vector<int> &sa) {
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		pos[sa[i]] = i;
	}
	vector<int> lcp(n - 1);
	for (int i = 0, k = 0; i < n; ++i) {
		k = max(k - 1, 0);
		if (pos[i] == n - 1) {
			k = 0;
		}
		else {
			int j = sa[pos[i] + 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
				++k;
			}
			lcp[pos[i]] = k;
		}
	}
	return lcp;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n, q;
	cin >> n >> q;
	vector<string> e(n);
	string s;
	vi sizes(n);
	for (int i = 0; i < n; i++) {
		cin >> e[i];
		s += e[i] + '#';
		sizes[i] = (i ? sizes[i - 1] : 0) + sz(e[i]) + 1;
	}
	vi sa = suffix_array(s, sz(s), 200);
	vi insa(sz(sa));
	for (int i = 0; i < sz(sa); i++) {
		insa[sa[i]] = i;
	}
	vi lc = build_lcp(s, sz(s), sa);
	vi sid(sz(sa));
	for (int i = 0; i < sz(sa); i++) {
		int lf = 0, rg = n - 1;
		while (lf < rg) {
			int md = (lf + rg) >> 1;
			if (sa[i] + 1 <= sizes[md]) {
				rg = md;
			}
			else {
				lf = md + 1;
			}
		}
		sid[i] = (sa[i] + 1 == sizes[lf] ? -1 : lf);
	}
	vi lg(sz(lc) + 1, 0);
	for (int i = 2; i < sz(lc) + 1; i++) {
		lg[i] = 1 + lg[i >> 1];
	}
	vector<vi> st(sz(lc), vi(lg[sz(lc)] + 1));
	for (int i = 0; i < sz(lc); i++) {
		st[i][0] = lc[i];
	}
	for (int j = 1; j < lg[sz(lc)] + 1; j++) {
		for (int i = 0; i + (1 << j) - 1 < sz(lc); i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	auto get = [&st, &lg](int l, int r) {
		int u = lg[r - l + 1];
		return min(st[l][u], st[r - (1 << u) + 1][u]);
	};
	struct query {
		int l, r, id, k;
	};
	vector<vector<query>> qv(sz(sa));
	for (int i = 0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		--l; --r; --k;
		int suf = (k ? sizes[k - 1] : 0);
		int pos = insa[suf];
		int L;
		{
			int lf = 0, rg = pos;
			while (lf < rg) {
				int md = (lf + rg) >> 1;
				if (get(md, pos - 1) >= sz(e[k])) {
					rg = md;
				}
				else {
					lf = md + 1;
				}
			}
			L = lf;
		}
		int R;
		{
			int lf = pos, rg = sz(sa) - 1;
			while (lf < rg) {
				int md = (lf + rg + 1) >> 1;
				if (get(pos, md - 1) >= sz(e[k])) {
					lf = md;
				}
				else {
					rg = md - 1;
				}
			}
			R = lf;
		}
		qv[R].pb({ l, r, i, 1 });
		if (L > 0) {
			qv[L - 1].pb({ l, r, i, -1 });
		}
	}
	vi ans(q, 0);
	struct Fenwick {
		int n;
		vi t;
		Fenwick(int n) : n(n), t(n, 0) {}
		void upd(int v, int x) {
			for (int i = v; i < n; i |= i + 1) {
				t[i] += x;
			}
		}
		int get(int v) {
			int ret = 0;
			for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
				ret += t[i];
			}
			return ret;
		}
		int get(int l, int r) {
			return get(r) - get(l - 1);
		}
	};
	Fenwick t(n);
	for (int i = 0; i < sz(sa); i++) {
		if (sid[i] != -1) {
			t.upd(sid[i], 1);
		}
		for (auto q : qv[i]) {
			ans[q.id] += q.k * t.get(q.l, q.r);
		}
	}
	for (int x : ans) {
		cout << x << '\n';
	}
}