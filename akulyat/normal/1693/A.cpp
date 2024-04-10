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
vector<ll> v;


void solve() {
	cin >> n;	
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	while (v.size() && !v.back())
		v.pop_back();

	if (v.empty()) {
		cout << "YES\n";		
		return;
	}


	v.insert(v.begin(), 0);
	v[1] -= 1;
	v.back() += 1;
	for (int i = 1; i < v.size(); i++)
		v[i] += v[i - 1];

	if (v.back()) {
		cout << "NO\n";		
		return;
	}
	for (auto i : v)
		if (i < 0) {
			cout << "NO\n";		
			return;
		}
	cout << "YES\n";		

	// if (v.size() == 1) {
	// 	cout << "NO\n";		
	// 	return;
	// }
	// for (int i = 1; i + 1 < v.size(); i++)
	// 	v[i] -= 2;
	// v[0] -= 1;	
	// v[v.size() - 1] -= 1;	


	// if (v[0] < 0) {
	// 	cout << "NO\n";		
	// 	return;
	// }
	// for (int i = 1; i < v.size(); i++) {
	// 	int x = v[i] - v[i - 1];
	// 	if (x < 0) {
	// 		cout << "NO\n";		
	// 		return;
	// 	}
	// 	v[i] = x;
	// }
	// if (v.back() != 0) {
	// 	cout << "NO\n";		
	// 	return;
	// }
	// cout << "YES\n";		
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