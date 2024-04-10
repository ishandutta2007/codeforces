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
vector<vector<ll>> m;
vector<vector<ll>> v;
bool viv = false;

ll check(vector<ll> v) {
	// for (auto i : v)
	// 	cout << i << ' ';
	// cout << endl;
	ll n = v.size();
	vector<ll> good;
	good.resize(n);
	for (ll i = 0; i < n; i++) {
		if (v[i] != ml) {
			ll r = i - v[i];
			if (r < 0)
				r += n;
			if (r >= 0 && r < n)
				good[r]++;
		}
	}
	ll res = ml;
	for (ll i = 0; i < n; i++) {
		res = min(res, i + n - good[i]);
//		cout << good[i] << ' ';
	}
//	cout << endl;
//	cout << res << endl;
	return res;
}

void solve() {
	cin >> n >> k;
	v.resize(k);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < k; j++) {
			ll a;
			cin >> a;
			a -= (j + 1);
			if (a >= 0 && a <= (k * (n - 1)) && a % k == 0) 
				a /= k;
			else
				a = ml;
			v[j].push_back(a);
		}
	}
	ll ans = 0;
	for (auto l : v)
		ans += check(l);
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