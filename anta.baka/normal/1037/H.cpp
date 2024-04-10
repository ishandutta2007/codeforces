#define CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

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
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <functional>
#include <complex>
#include <array>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

template<typename T> vi suffix_array(const T& s, int n, int alpha) {
	vi a(n);
	if (~alpha) {
		vi bucket(alpha);
		for (int i = 0; i < n; i++) {
			bucket[s[i]]++;
		}
		int sum = 0;
		for (int i = 0; i < alpha; i++) {
			int add = bucket[i];
			bucket[i] = sum;
			sum += add;
		}
		for (int i = 0; i < n; i++) {
			a[bucket[s[i]]++] = i;
		}
	}
	else {
		iota(all(a), 0);
		sort(all(a), [&](const int& x, const int& y) { return s[x] < s[y]; });
	}
	vi sbs(n), pg(n), ng(n), g(n);
	g[a[0]] = 0;
	for (int i = 1; i < n; i++) {
		g[a[i]] = g[a[i - 1]] + (s[a[i]] != s[a[i - 1]]);
	}
	int step = 1;
	while (g[a[n - 1]] < n - 1) {
		int ptr = 0;
		for (int i = n - step; i < n; i++) {
			sbs[ptr++] = i;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] >= step) {
				sbs[ptr++] = a[i] - step;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			pg[g[a[i]]] = i;
		}
		for (int i = 0; i < n; i++) {
			int x = sbs[i];
			a[pg[g[x]]++] = x;
		}
		ng[a[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (g[a[i]] != g[a[i - 1]]) {
				ng[a[i]] = ng[a[i - 1]] + 1;
			}
			else {
				int prev = a[i - 1] + step >= n ? -1 : g[a[i - 1] + step];
				int now = a[i] + step >= n ? -1 : g[a[i] + step];
				ng[a[i]] = ng[a[i - 1]] + (prev != now);
			}
		}
		g = ng;
		step <<= 1;
	}
	return a;
}

template<typename T> vi build_lcp(const T& s, int n, const vi& sa) {
	vi pos(n);
	for (int i = 0; i < n; i++) {
		pos[sa[i]] = i;
	}
	vi lcp(n - 1);
	for (int i = 0, k = 0; i < n; i++) {
		k = max(k - 1, 0);
		if (pos[i] == n - 1) {
			k = 0;
		}
		else {
			int j = sa[pos[i] + 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
				k++;
			}
			lcp[pos[i]] = k;
		}
	}
	return lcp;
}

struct Query {
	int l, r;
	string s;
};

const int N = 2e5;
const int LEN = 5e5;
const int LG = 20;
const int inf = 1e9 + 100;

string s;
int n;
Query qv[N];

int lg[LEN];
int sparse[LG][LEN];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> s;
	string mem = s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> qv[i].l >> qv[i].r >> qv[i].s;
		--qv[i].l; --qv[i].r;
		s += '#' + qv[i].s;
	}
	vi sa = suffix_array(s, sz(s), 200);
	vi lcp = build_lcp(s, sz(s), sa);
	for (int i = 2; i < LEN; i++) {
		lg[i] = 1 + lg[i >> 1];
	}
	for (int i = 0; i < sz(lcp); i++) {
		sparse[0][i] = lcp[i];
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 0; i + (1 << j) - 1 < sz(lcp); i++) {
			sparse[j][i] = min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
		}
	}
	function<int(int, int)> get_lcp = [&](int l, int r) {
		int h = lg[r - l + 1];
		return min(sparse[h][l], sparse[h][r - (1 << h) + 1]);
	};
	vi insa(sz(s));
	for (int i = 0; i < sz(s); i++) {
		insa[sa[i]] = i;
	}
	vi query_insa;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '#') {
			query_insa.pb(insa[i + 1]);
		}
	}
	s = mem;
	int m = sz(s);
	vector<vi> st(2 * m);
	for (int i = 0; i < m; i++) {
		st[i + m] = { insa[i] };
	}
	for (int i = m - 1; i; i--) {
		merge(all(st[i * 2]), all(st[i * 2 + 1]), back_inserter(st[i]));
	}
	for (int i = 0; i < n; i++) {
		const string& t = qv[i].s;
		int l = qv[i].l, r = qv[i].r;
		int t_insa = query_insa[i];
		int best_suf = inf;
		for (int j = r; r - j + 1 <= sz(t) && l <= j; j--) {
			if (insa[j] > t_insa && get_lcp(t_insa, insa[j] - 1) < r - j + 1) {
				best_suf = min(best_suf, insa[j]);
			}
		}
		if (l <= r - sz(t)) {
			r -= sz(t);
			for (l += m, r += m; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
				if (l & 1) {
					auto pos = upper_bound(all(st[l]), t_insa);
					if (pos != st[l].end()) {
						best_suf = min(best_suf, *pos);
					}
				}
				if (!(r & 1)) {
					auto pos = upper_bound(all(st[r]), t_insa);
					if (pos != st[r].end()) {
						best_suf = min(best_suf, *pos);
					}
				}
			}
		}
		if (best_suf == inf) {
			cout << -1 << '\n';
			continue;
		}
		int pos = sa[best_suf];
		for (int j = 0; ; j++) {
			cout << s[pos + j];
			if (j == sz(t) || s[pos + j] > t[j]) {
				break;
			}
		}
		cout << '\n';
	}
}