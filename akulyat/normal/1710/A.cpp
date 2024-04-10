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
int n, m, k;
vector<int> v;


void solve() {
	cin >> n >> m >> k;
	v.resize(k);
	for (auto &i : v)
		cin >> i;
	auto v2 = v;

	bool s1_3 = false;
	bool s2_3 = false;

	for (auto &i : v) {
		i /= n;
		if (i == 1)
			i = 0;
		if (i >= 3)
			s1_3 = true;
	}
	for (auto &i : v2) {
		i /= m;
		if (i == 1)
			i = 0;
		if (i >= 3)
			s2_3 = true;
	}

	ll s1 = 0;
	ll s2 = 0;
	for (auto &i : v)
		s1 += i;
	s1 -= m;
	for (auto &i : v2)
		s2 += i;
	s2 -= n;


	if (!s1_3 && (m & 1))
		s1 = -1;
	if (!s2_3 && (n & 1))
		s2 = -1;

	if (s1 >= 0 || s2 >= 0)
		cout << "Yes\n";
	else
		cout << "No\n";
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