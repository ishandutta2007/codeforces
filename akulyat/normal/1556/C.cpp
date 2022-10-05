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

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;

ll solver(int pl) {
	ll bal = 0;
	ll mini = inf;
	bool mode = true;

	ll res = 0;
	if (pl + 1 < n)
		res += min(v[pl], v[pl + 1]);
	for (int i = pl; i < n; i++) {
		if (mode) {
			bal += v[i];
		} else {
			// cout << i << " bal, mini = " << bal << ' ' << mini << endl;
			if (mini != inf) {
				if (mini >= 0) {
					ll l1 = bal - mini;
					ll r1 = bal;
					ll l2 = 0;
					ll r2 = v[i];
					l1 = max(l1, l2);
					r1 = min(r1, r2);
					res += max(0ll, r1 + 1 - l1);
				}
			}
			// cout << "\tSEE " << res << endl;
			bal -= v[i];
			mini = min(mini, bal);
		}
		mode ^= 1;
	}
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll ans = 0;
	for (int i = 0; i < n; i += 2) {
		ans += solver(i);
		// cout << "see: " << ans << endl;
	}
	cout << ans << '\n';

	// cout << endl;
	// cout << endl;
	// cout << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

    // #ifdef DEBUG
        // cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    // #endif
}