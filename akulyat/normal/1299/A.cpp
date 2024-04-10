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
vector<ll> m, v, mm;
bool viv = false;


void solve() {
	cin >> n;
	m.resize(n);
	for (auto &i : m)
		cin >> i;
	ll best = 0;
	ll val = 1;
	mm = v = m;
	for (ll i = 0; i < 30; i++) {
		ll cnt = 0;
		ll who = -1;
		for (ll j = 0; j < n; j++) {
			if (m[j] & 1) {
				cnt++;
			}
		}
		if (cnt != 1) 
			for (ll j = 0; j < n; j++) {
				if (m[j] & 1) {
					v[j] -= val;
				}
			}
		for (auto &j : m)
			j /= 2;
		val *= 2;
	}
	vector<pll> vv;
	for (ll i = 0; i < n; i++)
		vv.push_back({v[i], mm[i]});
	sort(vv.rbegin(), vv.rend());
	for (auto i : vv)
		cout << i.S << ' ';
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