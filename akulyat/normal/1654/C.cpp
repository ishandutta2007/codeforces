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

map<ll, int> mp;
int used = 0;

bool work(ll cur) {
	if (mp[cur] >= 1) {
		used++;
		mp[cur]--;
		return true;
	}
	if (cur == 1)
		return false;
	ll a = cur / 2;
	ll b = cur - a;
	return work(a) && work(b);
}

void solve() {
	cin >> n;
	v.resize(n);
	ll sum = 0;
	mp.clear();
	for (auto &i : v) {
		cin >> i;
		sum += i;
		mp[i]++;
	}
	sort(v.begin(), v.end());


	used = 0;
	bool res = work(sum);
	// if (used != n)
	// 	res = false;
	if (res)
		cout << "YES\n";
	else
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