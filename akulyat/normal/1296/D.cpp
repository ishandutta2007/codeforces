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

ll has(ll x, ll y) {
	return x * ml + y;
}

void add(vector<pair<ll, pll>> &ans, map<ll, ll> &las, ll h, ll ind) {
	ans.push_back({ind - las[h], {las[h], ind}});
}

ll need(ll val, ll a, ll b) {
	val %= (a + b);
	if (val == 0)
		val = (a + b);
	return (val - 1) / a;
}

void solve() {
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<ll> m(n);
	for (auto &i : m)
		cin >> i;

	for (auto &i : m)
		i = need(i, a, b);

	sort(m.begin(), m.end());
	ll left = k;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll can = min(m[i], left);
		m[i] -= can;
		left -= can;
		if (m[i] == 0)
			ans++;
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