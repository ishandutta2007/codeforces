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

multiset<int> s;
vector<pii> ans;

void show() {
	if (!viv)
		return;
	cout << "\ts = ";
	for (auto i : s)
		cout << i << ' ';
	cout << endl;

}

void work(int a, int b, int mul = 1) {
	if (viv)
		cout << "work " << a << ' ' << b << ' ' << mul << endl;
	a *= mul;
	b *= mul;
	s.erase(s.find(a));
	s.erase(s.find(b));
	s.insert(a + b);
	s.insert(abs(a - b));
	ans.push_back({a, b});
}

void solver(int n, int mul) {
	if (viv) {
		cout << "solver(" << n << ' ' << mul << ")" << endl;
		show();
	}

	if (n == 0) {
		if (viv) 
			cout << "/solver(" << n << ' ' << mul << ")" << endl;
		return;
	}

	int p = 1;
	while (p < n)
		p <<= 1;
	if (p == n) {
		solver(n - 1, mul);
		return;
	}

	vector<int> a, b, c;
	for (int i = p / 2 + 1; i <= n; i++) {
		int j = p - i;
		work(i, j, mul);		
	}
	solver(p - n - 1, mul);
	solver(n - p / 2, mul * 2);

	if (viv) 
		cout << "/solver(" << n << ' ' << mul << ")" << endl;
}

void cleaner() {
	set<int> un_s;
	for (auto v : s)
		un_s.insert(v);
	int p = *un_s.rbegin();
	un_s.erase(p);

	int doub = -1;
	for (auto v : un_s)
		if (s.count(v) > 1)
			doub = v;
	assert(doub != -1);
	work(doub, doub);


	multiset<int> non_z;
	for (auto v : s) {
		if (v && p - v)
			non_z.insert(v);		
	}
	for (auto v : non_z) {
		while (v != p && v < mod) {
			work(0, v);
			work(v, v);
			v *= 2;
		}
	}

	int cnt_z = s.count(0);
	for (int i = 0; i < cnt_z; i++)
		work(0, p);	
}

void solve() {
	cin >> n;
	if (n == 2) {
		cout << "-1\n";
		return;
	}

	ans.clear();
	s.clear();
	for (int i = 0; i < n; i++)
		s.insert(i + 1);
	solver(n, 1);

	cleaner();

	cout << ans.size() << '\n';
	for (auto p : ans)
		cout << p.F << ' ' << p.S << '\n';

	show();
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