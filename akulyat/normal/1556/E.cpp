#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, q;
vector<ll> a, b, pa, pb;
bool viv = false;

struct Tree {
	int n, s;
	vector<ll> t;
	int tp = 0;

	ll V = inf;

	Tree () {}
	Tree (vector<ll> a, int tt = 0) {
		tp = tt;
		if (tp)
			V = -inf;

		n = a.size();
		s = 1;
		while (s < n)
			s <<= 1;
		t.resize(2 * s, V);
		for (int i = 0; i < n; i++) {
			t[s + i] = a[i];			
		}
		for (int i = s - 1; i > 0; i--)
			get_val(i);
	}

	void get_val(int pl) {
		if (pl >= s)
			return;
		if (!tp)
			t[pl] = min(t[2 * pl], t[2 * pl + 1]);
		else
			t[pl] = max(t[2 * pl], t[2 * pl + 1]);
	}

	ll get(int l, int r, int v, int tl, int tr) {
		// cout << "get(" << l << ' ' << r << ' ' << v << ' ' << tl << ' ' << tr << ") " << endl;

		if (r <= tl || tr <= l)
			return V;
		if (l <= tl && tr <= r) {
			return t[v];
		}
		int tm = (tl + tr) >> 1;
		ll val1 = get(l, r, 2 * v + 0, tl, tm);
		ll val2 = get(l, r, 2 * v + 1, tm, tr);
		if (!tp)
			return min(val1, val2);
		else
			return max(val1, val2);
	}

	ll get(int l, int r) {
		r++;
		return get(l, r, 1, 0, s);
	}

};

void prepare() {
	pa.push_back(0);
	for (auto i : a)
		pa.push_back(pa.back() + i);
}


void work(Tree &t_min, Tree &t_max) {
	int l, r;
	cin >> l >> r;
	l--;


	ll res = t_min.get(l, r);
	res -= pa[l];

	ll res2 = t_max.get(l, r);
	res2 -= pa[l];

	// cout << "GET " << res << ' ' << res2 << endl;
	if (res2 <= 0 && pa[r] == pa[l])
		cout << -res << '\n';
	else
		cout << "-1\n";
}

void solve() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(n);
	for (auto &i : b)
		cin >> i;
	for (int i = 0; i < n; i++)
		a[i] -= b[i];
	prepare();

	Tree t_min(pa, 0);
	Tree t_max(pa, 1);

	while (q--)
		work(t_min, t_max);

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	// #ifdef DEBUG
		// cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	// #endif
}