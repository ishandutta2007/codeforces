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
vector<int> v;
vector<pii> bad;

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	bad.resize(m);
	for (auto &i : bad)
		cin >> i.F >> i.S;
	// bad.clear();
	set<pii> s;
	unordered_map<int, set<int>> bad2;
	for (auto p : bad) {
		bad2[p.F].insert(p.S);
		bad2[p.S].insert(p.F);
		s.insert(p);
		s.insert({p.S, p.F});
	}

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		// cout << "\t\t\tadd " << v[i] << endl;
		mp[v[i]]++;
	}

	unordered_map<int, set<int>> mp2;
	for (auto p : mp) {
		// cout << "\t\twas " << p.F << ' ' << p.S << endl;
		mp2[p.S].insert(p.F);
	}

	ll ans = -inf;
	vector<int> cnts;
	for (auto p : mp2)
		cnts.push_back(p.F);

	vector<int> bst;
	for (auto v : cnts)
		bst.push_back(*mp2[v].rbegin());


	for (int i = 0; i < cnts.size(); i++) {
		for (int j = i + 1; j < cnts.size(); j++) {
			int val1 = bst[i];
			int val2 = bst[j];
			if (val1 != val2 && s.count({val1, val2}) == 0) {
				ll lans = (ll)(val1 + val2) * (ll)(mp[val1] + mp[val2]);
				// cout << "\tuse " << val1 << ' ' << val2 << ' ' << lans << endl;
				ans = max(ans, lans);
			}
		}
	}
	for (int i = 0; i < cnts.size(); i++) {
		// for (int j = i + 1; j < cnts.size(); j++) {
		// 	auto val1 = *mp2[cnts[i]].rbegin();
		// 	auto val2 = *mp2[cnts[j]].rbegin();
		// 	if (val1 != val2 && s.count({val1, val2}) == 0) {
		// 		ll lans = (ll)(val1 + val2) * (ll)(mp[val1] + mp[val2]);
		// 		// cout << "\tuse " << val1 << ' ' << val2 << ' ' << lans << endl;
		// 		ans = max(ans, lans);
		// 	}
		// }
		if (mp2[cnts[i]].size() > 1) {
			auto val1 = *mp2[cnts[i]].rbegin();
			auto z = mp2[cnts[i]].rbegin();
			z++;
			auto val2 = *z;
			if (val1 != val2 && s.count({val1, val2}) == 0) {
				ll lans = (ll)(val1 + val2) * (ll)(mp[val1] + mp[val2]);
				// cout << "\tuse " << val1 << ' ' << val2 << ' ' << lans << endl;
				ans = max(ans, lans);
			}
		}

		for (auto val : mp2[cnts[i]]) {
			int val1 = val;
			unordered_set<int> intr;
			for (auto fr : bad2[val]) {
				intr.insert(mp[fr]);
			}
			for (auto cnt : intr) {
				auto z = mp2[cnt].rbegin();
				while (z != mp2[cnt].rend() && ((*z == val) || (bad2[val].count(*z))))
					z++;
				if (z != mp2[cnt].rend()) {
					auto val2 = *z;
					ll lans = (ll)(val1 + val2) * (ll)(mp[val1] + mp[val2]);
					// cout << "\tuse " << val1 << ' ' << val2 << ' ' << lans << endl;
					ans = max(ans, lans);					
				}
			}
		}
	}

	cout << ans << '\n';

	// vector<pii> have;
	// for (auto p : mp2) {
	// 	for (auto val : p.S)
	// 		have.push_back({val, p.F});
	// }


	// set<pii> s;
	// for (auto p : bad) {
	// 	s.insert(p);
	// 	s.insert({p.S, p.F});
	// }

	// int n = have.size();
	// ll ans = -inf;
	// // cout << "n = " << n << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = i + 1; j < n; j++) {
	// 		// cout << "\tsee " << have[i].F << ' ' << have[j].F << endl;
	// 		if (s.count({have[i].F, have[j].F}) == 0) {
	// 			ans = max(ans, (ll)(have[i].F + have[j].F) * (ll)(have[i].S + have[j].S));
	// 		}
	// 	}
	// }
	// cout << ans << '\n';
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