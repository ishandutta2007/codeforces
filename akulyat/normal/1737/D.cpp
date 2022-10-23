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
vector<vector<int>> e;

vector<ll> dist;

void BFS(int v) {
	for (auto &i : dist)
		i = mod;
	dist[v] = 0;
	vector<int> d(1, v);
	int pl = 0;
	while (pl < d.size()) {
		auto r = d[pl++];
		for (auto u : e[r]) {
			if (dist[u] > dist[r] + 1) {
				dist[u] = dist[r] + 1;
				d.push_back(u);
			}
		}
	}
}

void solve() {
    cin >> n >> m;
    dist.assign(n, mod);
    e.assign(n, {});
    vector<pair<pii, ll>> ed;
    for (int i = 0; i < m; i++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	a--, b--;
    	e[a].push_back(b);
    	e[b].push_back(a);
    	ed.push_back({{a, b}, c});
    }

    BFS(0);
    auto da = dist;
    BFS(n - 1);
    auto db = dist;

    ll ans = inf;
    for (auto [p, len] : ed) {
    	auto [a, b] = p;

    	ll lans1 = len * (min(da[a] + db[b], db[a] + da[b]) + 1);

    	ans = min(ans, lans1);

    	// ll lans2 = len * (min(da[a] + db[a], db[b] + da[b]) + 1);
    	// ans = min(ans, min(lans1, lans2));
    }

    for (int c = 0; c < n; c++) {
    	BFS(c);
    	int coef = dist[0] + dist[n - 1] + 1;
	    for (auto [p, len] : ed) {
	    	auto [a, b] = p;

	    	int lcoef = max(dist[a], dist[b]);
	    	ll lans = (coef + lcoef) * len;
	    	ans = min(ans, lans);

	    	// if (lans == 132) {
	    	// 	cout << c << " with " << a << ' ' << b << " see " << coef << ' ' << lcoef << endl;
	    	// }
	    }
    }

    cout << ans << '\n';
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