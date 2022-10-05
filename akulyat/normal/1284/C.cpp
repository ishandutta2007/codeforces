#include <bits/stdc++.h>
 
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
//const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, t, m, ans, mod;
vector<ll> p, f;
bool viv = false;

void check(vector<ll> p) {
	ll n = p.size();
	for (ll i = 0; i < n; i++)
		for (ll j = i + 1; j <= n; j++) {
			ll mi = inf;
			ll ma = -inf;
			for (ll u = i; u < j; u++)
				ma = max(ma, p[u]),
				mi = min(mi, p[u]);
//			cout << i << ' ' << j << ' ' << mi << ' ' << ma << endl;
			if (ma - mi + 1 == j - i)
				ans++;
		}		
}

void solve() {
	cin >> n >> mod;
	
	ll ans2 = 0;
	f.push_back(1);
	for (ll i = 1; i < n + 10; i++) {
		f.push_back(f.back() * i);
		f.back() %= mod;
	}
	for (ll i = 0; i < n; i++) {
		ll l = i + 1;
		ll kol = n - i;
		ll var = kol;
		ll lans = kol;
		lans *= var;
		lans %= mod;
		lans *= f[l];
		lans %= mod;
		lans *= f[n - l];
		lans %= mod;
		ans2 += lans;
	}
	ans2 %= mod;
	cout << ans2 << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}