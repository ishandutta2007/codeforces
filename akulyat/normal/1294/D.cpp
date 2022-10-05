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
const long long mod = 998244353;
const long long mod2 = 1e9+7;
const long long inf = ml * ml * ml + 7;
const int pc = 123457;
const int pc2 = 110329;
const ld cons = 1.95004;
const ld eps = 1e-4;
 
ll n, k;
vector<ll> m;
bool viv = false;


void solve() {
	cin >> n >> k;
	m.resize(k, 0);
	set<pll> s;
	for (ll i = 0; i < k; i++)
		s.insert({0, i});
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		a %= k;

		s.erase({m[a], a});
		m[a]++;
		s.insert({m[a], a});

		auto z = *s.begin();
		ll ans = k * z.F + z.S;
		cout << ans << '\n';
	}
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