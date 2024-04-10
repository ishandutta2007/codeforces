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


void solve() {
	ll n, tp;
	cin >> n >> tp;
	vector<pair<ll, pll>> m;
	for (ll i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		m.push_back({a, {b, c}});
	}	
	pair<ll, pll> now;
	now.S.F = now.S.S = tp;
	for (ll i = 0; i < m.size(); i++) {
		ll spend = m[i].F - now.F;
		now.S.F -= spend;
		now.S.S += spend;
		now.S.F = max(now.S.F, m[i].S.F);
		now.S.S = min(now.S.S, m[i].S.S);
		now.F = m[i].F;
//		cout << now.F << ": " << now.S.F << ' ' << now.S.S << endl;
		if (now.S.F > now.S.S) {
			cout << "NO\n";
			return;
		}

	}	
	cout << "YES\n";

}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}