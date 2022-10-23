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
vector<int> v;


void solve() {
	cin >> n;

	int r1, c1, r2, c2, r3, c3;
	cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

	int r0, c0;
	cin >> r0 >> c0;

	int mr = (r1 == r2 || r1 == r3) ? r1 : r2;
	int mc = (c1 == c2 || c1 == c3) ? c1 : c2;

	if ((mr == 1 || mr == n) && (mc == 1 || mc == n)) {
		// cout << "\t\tSEE " << mr << ' ' << mc << endl;
		if (mr == r0 || mc == c0) {
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}


	if (!((r0 ^ r1) & 1) && !((c0 ^ c1) & 1)) {
		cout << "YES\n";
		return;
	}
	if (!((r0 ^ r2) & 1) && !((c0 ^ c2) & 1)) {
		cout << "YES\n";
		return;
	}
	if (!((r0 ^ r3) & 1) && !((c0 ^ c3) & 1)) {
		cout << "YES\n";
		return;
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