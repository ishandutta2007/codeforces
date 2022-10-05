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
 
ll n, m, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> m >> k;
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		ll a; 
		cin >> a;
		v.push_back(a);
	}

	vector<pll> p;
	for (ll i = 0; i < m; i++) {
		p.push_back({v[i], v[n - m + i]});
	}

	ll sz = m - k;
	sz = max(sz, 1ll);
	multiset<ll> s;
	for (ll i = 0; i < sz; i++) {
		s.insert(max(p[i].F, p[i].S));
	}
	ll ans = *s.begin();
	for (ll i = sz; i < p.size(); i++) {
		s.erase(s.find(max(p[i - sz].F, p[i - sz].S)));
		s.insert(max(p[i].F, p[i].S));
		ans = max(ans, *s.begin());
	}
	cout << ans << '\n';
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