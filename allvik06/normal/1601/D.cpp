#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <array>
#include <cassert>
#include <random>
#include <ctime>
#include <map>
#include <set>


using namespace std;



const int inf = 1e9 + 1;

#define ll int
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back


struct Fenv {
	int n;
	vector<ll> t;


	inline void build(int _n) {
		n = _n;
		t.assign(n, 0);
	}


	inline void add(int i, ll x) {
		while (i < n) {
			t[i] += x;
			i = (i | (i + 1));
		}
	}


	inline ll get(int i) {
		ll res = 0;
		while (i >= 0) {
			res += t[i];
			i = (i & (i + 1)) - 1;
		}
		return res;
	}

	inline ll get(int l, int r) {
		if (l >= r) {
			return 0;
		}
		return get(r - 1) - get(l - 1);
	}
};


struct ask {
	int x;
	int i;
	bool dwn;

	ask(int i, int x, bool dwn) : i(i), x(x), dwn(dwn) {}
};


inline bool operator<(const ask& a1, const ask& a2) {
	if (a1.x != a2.x) {
		return a1.x < a2.x;
	}
	return (int)(a1.dwn) < (int)(a2.dwn);
}


int n, d;
int c;
const int maxn = 500000;
vector <int> p;
vector<int> s;
vector<ask> asks;
int cnt[maxn];
vector <int> up[2 * maxn];
int dwn_cnt[2 * maxn];
int dp[2 * maxn + 1];

inline int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, d;
	cin >> n >> d;
	p.reserve(n);
	s.reserve(n);
	ll res = 0;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int pi, si;
		cin >> pi >> si;
		if (pi < d) {

		}
		else if (si < d) {
			res += 1;
		}
		else {
			p.push_back(pi);
			s.push_back(si);
			mp[pi] = 0;
			mp[si] = 0;
		}
	}
	n = p.size();
	int c = 0;
	for (auto& f : mp) {
		f.second = c;
		++c;
	}
	for (int i = 0; i < n; ++i) {
		s[i] = mp[s[i]];
		p[i] = mp[p[i]];
	}
	asks.clear();
	asks.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (p[i] < s[i]) {
			asks.emplace_back(i, s[i], false);
		}
		if (p[i] > s[i]) {
			asks.emplace_back(i, p[i], true);
		}
	}
	sort(rall(asks));
	Fenv f;
	f.build(c);
	for (auto &as : asks) {
		if (as.dwn) {
			f.add(s[as.i], 1);
		}
		else {
			cnt[as.i] = f.get(p[as.i] + 1, s[as.i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (p[i] < s[i]) {
			up[p[i]].push_back(i);
		}
		else {
			dwn_cnt[s[i]] += 1;
		}
	}
	for (int i = c - 1; i >= 0; --i) {
		dp[i] = dp[i + 1] + dwn_cnt[i];
		for (auto j : up[i]) {
			dp[i] = max(dp[i], dp[s[j]] + dwn_cnt[i] + cnt[j] + 1);
		}
	}
	res += dp[0];
	cout << res << "\n";
	return 0;
}