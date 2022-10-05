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
int n, k;
vector<ll> v;


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	auto cv = v;
	for (int i = 0; i < n; i++)
		cv[i] -= n - i;

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);

	sort(ord.begin(), ord.end(), [&](int a, int b){
		return cv[a] > cv[b];
	});

	vector<bool> use(n, true);
	for (int i = 0; i < k; i++)
		use[ord[i]] = false;

	ll add = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (!use[i])
			add++;
		else
			sum += v[i] + add;
	}
	cout << sum << '\n';
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