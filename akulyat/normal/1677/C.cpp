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
vector<int> a, b, v;


void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	v.resize(n);

	for (auto &i : a)
		cin >> i, i--;
	for (auto &i : b)
		cin >> i, i--;
	for (int i = 0; i < n; i++)
		v[a[i]] = b[i];

	vector<bool> used(n, false);
	vector<int> l;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			int st = v[i];
			int len = 1;
			while (st != i) {
				used[st] = true;
				st = v[st];
				len++;
			}
			l.push_back(len);
		}
	}
	sort(l.rbegin(), l.rend());
	if (viv) {
		for (auto i : l)
			cout << i << ' ';
		cout << endl;
	}

	int ls = n / 2;
	int rs = n - ls;

	ll ans = 0;
	for (auto len : l) {
		int a = len / 2;
		int b = len - a;
		if (a != b && ls != rs) {
			if ((a > b) ^ (ls > rs)) {
				swap(a, b);
			} else {
			}
		}
		if (a < b)
			swap(a, b), swap(ls, rs);

		int tp = 0;
		int pl = 0;
		int pr = ls + rs - 1;


		vector<int> st;
		if (viv)
			cout << "\tstart " << a << ' ' << b << " with " << ls << ' ' << rs << endl;
		while (a > 0 || b > 0) {
			if (!tp) {
				a--;
				ls--;
				st.push_back(pl);
				pl++;
			} else {
				b--;
				rs--;
				st.push_back(pr);
				pr--;
			}
			tp ^= 1;
		}
		if (viv) {
			cout << "\tst = ";
			for (auto i : st)
				cout << i << ' ';
			cout << endl;
		}

		ll lans = 0;
		for (int i = 0; i < st.size(); i++)
			lans += abs(st[i] - st[(i + 1) % st.size()]);

		ans += lans;

		if (len & 1) {
			if (ls < rs)
				ls++;
			else
				rs++;
		}


	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}