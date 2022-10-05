// #include <bits/stdc++.h>
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

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n;
vector<int> h;
vector<vector<int>> e;
vector<int> d;

vector<multiset<int, greater<int>>> vals;
vector<int> where;

void work(int v, bool root = true) {
	int need = h[v];
	d[v] = 0;

	vector<int> kids;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			work(u, false);
			kids.push_back(u);
		}
	}
	if (kids.size() == 0) {
		where[v] = v;
		vals[v].insert(h[v]);
		if (viv) {
			cout << "\tsee " << v << ": ";
			for (auto val : vals[where[v]])
				cout << val << ' ';
			cout << endl;
		}
		return;
	}

	for (auto &v : kids)
		v = where[v];

	int mx = -1;
	for (auto v : kids)
		mx = max(mx, (int)vals[v].size());

	int ch = -1;
	for (auto v : kids)
		if (vals[v].size() == mx)
			ch = v;

	sort(kids.begin(), kids.end(), [](int a, int b){
		return *vals[a].begin() > *vals[b].begin();
	});
	int ch0 = kids[0];
	auto z = vals[ch0].begin();
	if (need > (*z)) {
		vals[ch0].erase(z);
		vals[ch0].insert(need);
	}
	if (root) {
		if (kids.size() != 1) {
			int ch0 = kids[1];
			auto z = vals[ch0].begin();
			if (need > (*z)) {
				vals[ch0].erase(z);
				vals[ch0].insert(need);
			}
		} else {
			vals[kids[0]].insert(need);
		}
	}

	for (auto u : kids) {
		if (u != ch) {
			for (auto i : vals[u])
				vals[ch].insert(i);
		}
	}
	where[v] = ch;

	if (viv) {
		cout << "\tsee " << v << ": ";
		for (auto val : vals[where[v]])
			cout << val << ' ';
		cout << endl;
	}
}

void solve() {
	cin >> n;
	h.resize(n);
	for (auto &i : h)
		cin >> i;

	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int l = 0;
	for (int i = 0; i < n; i++)
		l += (e[i].size() == 1);
	int mx = 0;
	for (auto i : h)
		mx = max(mx, i);

	int root = 0;
	while (h[root] != mx)
		root++;


	d.resize(n, -1);
	vals.resize(n);
	where.resize(n, -1);
	work(root);

	ll res = 0;
	for (auto val : vals[where[root]])
		res += val;
	cout << res << '\n';

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}