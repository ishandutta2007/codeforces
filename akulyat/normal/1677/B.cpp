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
int n, m;
string s;
vector<int> v;


void solve() {
	cin >> n >> m;
	cin >> s;
	v.clear();
	for (auto i : s)
		v.push_back(i == '1');

	vector<int> p(1, 0);
	for (auto i : v)
		p.push_back(p.back() + i);

	auto seg = [&](int l, int r) {
		return p[r + 1] - p[l];
	};

	vector<int> first_row;
	vector<bool> done(m, false);
	int sum = 0;
	for (int i = 0; i < n * m; i++) {
		if (first_row.size() < m)
			first_row.push_back(((first_row.size() ? first_row.back() : 0) + v[i]) > 0);
		else {
			first_row.push_back(first_row[i - m] + (seg(i - m + 1, i) > 0));
		}
		if (v[i] && !done[i % m]) {
			done[i % m] = true;
			sum++;
		}
		cout << first_row.back() + sum << ' ';
		// cout << first_row.back() + sum << " : " << first_row.back() << ' ' << sum << endl;
	}
	cout << '\n';

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