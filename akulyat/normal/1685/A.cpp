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
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (n & 1) {
		cout << "NO\n";
		return;
	}
	sort(v.begin(), v.end());
	vector<int> a, b;
	for (int i = 0; i < n / 2; i++) {
		a.push_back(v[i]);
		b.push_back(v[i + n / 2]);
	}
	// reverse(b.begin(), b.end());
	// b.push_back(b[0]);
	// b.push_back(b[1]);
	// reverse(b.begin(), b.end());
	// b.pop_back();
	// b.pop_back();
	// reverse(b.begin(), b.end());
	v.clear();
	for (int i = 0; i < n / 2; i++) {
		v.push_back(a[i]);
		v.push_back(b[i]);
	}

	v.push_back(v[0]);
	v.push_back(v[1]);

	for (int i = 0; i < n; i++) {
		bool nice1 = (v[i] < v[i + 1]) && (v[i + 1] > v[i + 2]);
		bool nice2 = (v[i] > v[i + 1]) && (v[i + 1] < v[i + 2]);
		if (nice1 || nice2) {

		} else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) 
		cout << v[i] << ' ';
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