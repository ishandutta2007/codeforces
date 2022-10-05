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
	cin >> n;
	m.resize(n);
	for (auto &i : m)
		cin >> i;
	for (ll i = 0; i < n; i++) {
		m[i] -= i;
	}
	map<ll, vector<ll>> mp;
	for (ll i = 0; i < n; i++)
		mp[m[i]].push_back(i);
	ll ans = 0;
	for (auto p : mp) {
		auto v = p.S;
		ll val = v.size() * p.F;
		for (auto i : v)
			val += i;
		ans = max(ans, val);
	}
	cout << ans << endl;
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