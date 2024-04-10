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
vector<int> a, b;


void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	int sum = 0;
	int sq = 0;
	for (auto i : a) {		
		sum += i;
		sq += i * i;
	}
	for (auto i : b) {
		sum += i;
		sq += i * i;
	}

	vector<bool> pos(102 * (n + 2));
	pos[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = (int)pos.size() - 1; j >= 0; j--) {
			bool can = false;
			int p1 = j - a[i];
			if (p1 >= 0)
				if (pos[p1])
					can = true;
			int p2 = j - b[i];
			if (p2 >= 0)
				if (pos[p2])
					can = true;
			pos[j] = can;
		}
	}
	ll ans = inf;
	for (int i = 0; i < pos.size(); i++) {
		if (pos[i]) {
			ll sa = i;
			ll sb = sum - sa;
			ll val = (sa * sa + sb * sb + sq * (n - 2));
			ans = min(ans, val);

			// cout << "\tcan " << i << ' ' << val << endl;
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