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
typedef pair<char, int> seg; 

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
int a, b, c, d;
string s;
int n;


void solve() {
	cin >> a >> b >> c >> d;
	cin >> s;
	n = s.size();
	int dif1 = a - b;
	int dif2 = 0;
	for (auto i : s)
		dif2 += (i == 'A') - (i == 'B');
	if (dif1 != dif2) {
		cout << "NO\n";
		return;
	}

	seg ss = {s[0], 1};
	vector<seg> v;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			ss.S++;
		} else {
			v.push_back(ss);
			ss = {s[i], 1};
		}
	}
	v.push_back(ss);

	int sa = 0;
	vector<pii> va;
	int sb = 0;
	vector<pii> vb;
	for (auto p : v) {
		if (p.F == 'A') {
			sa += p.S / 2;
			if (p.S & 1) 
				va.push_back({0, p.S / 2});
			else {
				if (p.S / 2 > 1) {
					va.push_back({1, p.S / 2 - 2});
				}
			}
		}
		if (p.F == 'B') {
			sb += p.S / 2;
			if (p.S & 1)
				vb.push_back({0, p.S / 2});
			else {
				if (p.S / 2 > 1) {
					vb.push_back({1, p.S / 2 - 2});
				}
			}
		}
	}
	if (viv)	
		cout << "\t start " << sa << ' ' << sb << endl;
	sort(va.begin(), va.end(), [](pii a, pii b){
		if (a.F != b.F)
			return a.F < b.F;
		return a.S > b.S;
	});
	sort(vb.begin(), vb.end(), [](pii a, pii b){
		if (a.F != b.F)
			return a.F < b.F;
		return a.S > b.S;
	});

	auto nice = [&](int sa, int sb) {
		if (sa >= c && sb >= d) {
			cout << "YES\n";
			return true;
		}
		return false;
	};
	if (nice(sa, sb))
		return;

	if (viv) {
		cout << "va = ";
		for (auto p : va)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
		cout << "vb = ";
		for (auto p : vb)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}

	if (sb < d) {
		for (auto p : va) {
			if (nice(sa, sb))
				return;
			if (p.F == 0) {
				for (int i = 0; i < p.S; i++) {
					sa--, sb++;
					if (nice(sa, sb))
						return;
				}
			} else {
				sa -= 2;
				sb += 1;
				if (nice(sa, sb))
					return;
				for (int i = 0; i < p.S; i++) {
					sa--, sb++;
					if (nice(sa, sb))
						return;
				}
			}
		}
	}
	if (sa < c) {
		for (auto p : vb) {
			if (nice(sa, sb))
				return;
			if (p.F == 0) {
				for (int i = 0; i < p.S; i++) {
					sb--, sa++;
					if (nice(sa, sb))
						return;
				}
			} else {
				sb -= 2;
				sa += 1;
				if (nice(sa, sb))
					return;
				for (int i = 0; i < p.S; i++) {
					sb--, sa++;
					if (nice(sa, sb))
						return;
				}
			}
		}
	}
	cout << "NO\n";
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