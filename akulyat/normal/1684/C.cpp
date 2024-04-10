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
vector<vector<int>> v;

int bad(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++)
		if (v[i] < v[i - 1])
			return i;
	return -1;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	vector<vector<int>> tos;
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i;
		auto cl = l;
		sort(cl.begin(), cl.end());
		tos.push_back(cl);
	}

	vector<bool> bad(m, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != tos[i][j])
				bad[j] = true;
		}
	}
	vector<int> pl;
	for (int i = 0; i < m; i++)
		if (bad[i])
			pl.push_back(i);
	while (pl.size() < 2)
		pl.push_back(0);
	if (pl.size() > 2) {
		cout << "-1\n";
		return;
	}
	int a = pl[0];
	int b = pl[1];

	for (int i = 0; i < n; i++) {
		swap(v[i][a], v[i][b]);
	}
	if (v != tos) {
		cout << "-1\n";
		return;
	}

	cout << a + 1 << ' ' << b + 1 << '\n';

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