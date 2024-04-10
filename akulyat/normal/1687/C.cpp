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
vector<pii> seg;

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	for (auto &i : v) {
		int d = 0;
		cin >> d;
		i -= d;		
	}
	seg.resize(m);
	for (auto &[l, r] : seg) {
		cin >> l >> r;
		l--;
	}

	vector<vector<int>> ends(n + 1);
	for (int i = 0; i < seg.size(); i++) {
		auto [l, r] = seg[i];
		ends[l].push_back(i);
		ends[r].push_back(i);
	}



	vector<ll> pr(1, 0);
	for (auto i : v)
		pr.push_back(pr.back() + i);
	if (pr.back()) {
		cout << "NO\n";
		return;
	}


	vector<int> bad_ends(m, 2);
	vector<bool> used(m, false);
	set<int> nice_seg;
	auto check_nice = [&](int i) {
		if (used[i] || bad_ends[i])
			nice_seg.erase(i);
		else {
			// cout << "add " << i << " with " << used[i] << ' ' << bad_ends[i] << '\n';
			nice_seg.insert(i);
		}
	};
	for (int i = 0; i < m; i++) {
		auto [l, r] = seg[i];
		if (!pr[l])
			bad_ends[i]--;
		if (!pr[r])
			bad_ends[i]--;
		check_nice(i);
	}

	set<int> non_zero;
	for (int i = 0; i < pr.size(); i++)
		if (pr[i])
			non_zero.insert(i);

	while (nice_seg.size()) {
		auto num = *nice_seg.begin();
		nice_seg.erase(num);
		used[num] = true;

		auto [l, r] = seg[num];
		auto z = non_zero.lower_bound(l);
		vector<int> to_del;
		while (z != non_zero.end() && (*z) < r) {
			for (auto i : ends[*z]) {
				bad_ends[i]--;
				check_nice(i);
			}
			ends[*z].clear();
			to_del.push_back(*z);
			z++;
		}
		for (auto i : to_del)
			non_zero.erase(i);
	}
	if (non_zero.size()) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
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