#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
 
ll n;
vector<ll> m;
bool viv = false;

ll dist(ll a, ll b, ll c, ll d) {
	return abs(a - c) + abs(b - d);
}

void solve() {
	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	vector<pll> all;
	all.push_back({x0, y0});
	while (all.back().F < 30 * kk * ml * ml && all.back().S < 30 * kk * ml * ml) {
		all.push_back({all.back().F * ax + bx, all.back().S * ay + by});
	}

	ll xs, ys, t;
	cin >> xs >> ys >> t;

	ll ans = 0;
	for (ll i = 0; i < all.size(); i++) {
		for (ll j = i; j < all.size(); j++) {
			ll pa = dist(xs, ys, all[i].F, all[i].S);
			ll pb = dist(xs, ys, all[j].F, all[j].S);
			ll pc = dist(all[i].F, all[i].S, all[j].F, all[j].S);
			ll lres = min(pa, pb) + pc;
			if (lres <= t)
				ans = max(ans, j - i + 1);
		}
	}
	cout << ans << '\n';
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}