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

const int K = 320;

template <class T>
int counter(vector<T> vec) {
	int same = 0;
	int res = 0;
	for (int j = 0; j < vec.size(); j++) {
		same++;
		if (j && vec[j - 1] != vec[j])
			same = 1;
		res = max(res, same);
	}
	return res;
}


int work(int st) {
	auto vec = v;
	int sum = 0;
	for (int j = 0; j < n; j++) {
		vec[j] -= sum;
		sum += st;
	}
	sort(vec.begin(), vec.end());
	return counter(vec);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	int ans = 0;
	for (int st = -K; st <= K; st++) {
		ans = max(ans, work(st));
	}

	for (int i = 0; i < n; i++) {
		vector<int> sts; 
		for (int j = i + 1; j < min(n, i + K); j++) {
			// cout << i << ' ' << j << endl;
			if ((v[j] - v[i]) % (j - i) == 0) {
				int st = (v[j] - v[i]) / (j - i);
				sts.push_back(st);
			}
		}
		ans = max(ans, counter(sts) + 1);
	}
	cout << n - ans << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}