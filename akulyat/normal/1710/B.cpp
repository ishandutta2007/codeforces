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
ll m;
vector<pll> v;


void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;

	vector<pii> act;
	int number = 0;
	for (auto p : v) {
		ll add_1_l = p.F - p.S;
		ll add_1_r = p.F + p.S;
		ll dec_2 = p.F;
		act.push_back({add_1_l, 1});
		act.push_back({dec_2, -2});
		act.push_back({add_1_r, 1});
		act.push_back({p.F, mod + number});
		number++;
	}	

	sort(act.begin(), act.end(), [](pii a, pii b){
		if (a.F != b.F)
			return a.F < b.F;
		if (abs(a.S - b.S) > 10 * ml) {
			return abs(a.S) > abs(b.S);
		}
		return a.S < b.S;
	});

	string ans(n, '1');

	ll value = 0;
	ll adder = 0;
	ll prev_x = -mod;
	ll star = mod;
	for (auto [x, action] : act) {
		value += abs(x - prev_x) * adder;
		if (value > m) {
			star = min(star, x - (value - m));
		}

		if (action >= mod) {
			int num = action - mod;
			// cout << "\tat " << x << " see " << value << " and star = " << star << ", " <<  v[num].F - star << endl;

			if (v[num].S < v[num].F - star)
				ans[num] = '0';
		} else {
			// cout << "\t\taction " << x << " see " << action << endl;
			adder += action;
		}

		prev_x = x;
	}

	sort(act.begin(), act.end(), [](pii a, pii b){
		if (a.F != b.F)
			return a.F > b.F;
		if (abs(a.S - b.S) > 10 * ml) {
			return abs(a.S) > abs(b.S);
		}
		return a.S > b.S;
	});

	value = 0;
	adder = 0;
	prev_x = mod;
	star = -mod;
	for (auto [x, action] : act) {
		value += abs(x - prev_x) * adder;
		if (value > m) {
			star = max(star, x + (value - m));
		}

		if (action >= mod) {
			int num = action - mod;
			// cout << "\tat " << x << " see " << value << " and star = " << star << ", " << star - v[num].F << endl;

			if (v[num].S < star - v[num].F)
				ans[num] = '0';
		} else {
			// cout << "\t\taction " << x << " see " << action << endl;
			adder += action;
		}

		prev_x = x;
	}

	cout << ans << endl;

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