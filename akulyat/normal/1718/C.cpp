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
int n, q, k;
vector<bool> prime;
vector<int> v;
vector<int> parts;
vector<vector<ll>> sums;
vector<multiset<ll>> st;

vector<int> erat(int N) {
	vector<int> pr(N, true);
	pr[0] = pr[1] = false;
	vector<int> res;	
	for (int i = 2; i < N; i++) {
		if (pr[i]) {
			for (int val = 2 * i; val < N; val += i) {
				pr[val] = false;
			}
			res.push_back(i);
		}
	}
	// for (int i = 0; i < 10; i++)
	// 	cout << res[i] << ' ';
	// cout << endl;
	return res;
}

void precalc() {
	auto res = erat(200 * kk + 100);

	prime.resize(200 * kk + 200, false);

	for (auto i : res)
		prime[i] = true;
}

void change(int pl, ll old_val, ll val) {
	for (int i = 0; i < k; i++) {
		int sz = parts[i];
		int pos = pl % sz;
		st[i].erase(st[i].find(sums[i][pos]));
		sums[i][pos] += (val - old_val) * (sz);
		st[i].insert(sums[i][pos]);
	}

	v[pl] = val;
}

void calc() {
	parts.clear();
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			if (prime[n / i]) {
				parts.push_back(i);
				if (viv)
					cout << "\t\tUse " << i << endl;
			}
		}
	}
	k = parts.size();

	sums.assign(k, {});
	st.assign(k, {});
	for (int i = 0; i < k; i++) {
		sums[i].resize(parts[i], 0);	
		for (int j = 0; j < parts[i]; j++)
			st[i].insert(0);	
	}

	for (int i = 0; i < n; i++) {
		change(i, 0, v[i]);
	}
}

void change() {
	int p, x;
	cin >> p >> x;
	p--;
	change(p, v[p], x);
}

void do_ans() {
	ll ans = 0;	
	for (int i = 0; i < k; i++) {
		ll val = *st[i].rbegin();
		ans = max(ans, val);
	}
	cout << ans << '\n';
}

void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	calc();	

	do_ans();
	while (q--) {
		change();
		do_ans();
	}

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	precalc();
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}