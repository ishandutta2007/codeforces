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

map<int, int> asked;
ll ans = inf;
int qr;

int res(int w) {
	if (asked.count(w))
		return asked[w];

	assert(qr);
	qr--;

	cout << "? " << w << endl;
	cin >> asked[w];
	if (asked[w])
		ans = min(ans, (ll)w * asked[w]);
	return asked[w];
}

void solve() {
	cin >> n;
	qr = n + 30;
	int l = 0;
	int r = n * 2000 + (n - 1);
	// r = 10;
	while (l + 1 < r) {
		int m = l + r >> 1;
		int val = res(m);
		if (val == 1)
			r = m;
		else
			l = m;
	}
	int summl_n_1 = r;
	int suml = summl_n_1 - n + 1;

	if (viv)
		cout << "suml = " << suml << endl;

	// l = 0;
	// r = 2 * kk;
	// while (l + 1 < r) {
	// 	int m = l + r >> 1;
	// 	int val = res(m);
	// 	if (val == 0)
	// 		l = m;
	// 	else
	// 		r = m;
	// }
	// int maxl = r;
	// for (int i = 1; i < maxl; i++)
	// 	asked[i] = 0;
	// if (viv)
	// 	cout << "maxl = " << maxl << endl;


	for (int k = 1; k <= n; k++) {
		int s = summl_n_1 - (k - 1);
		while (s % k)
			s++;
		res(s / k);
	}

	cout << "! " << ans << '\n';

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