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


ll n, p;
vector<ll> m;
bool viv = false;

void work(ll val) {
	cout << val << endl;
	exit(0);
}

void solve() {
	cin >> n >> p;
	m.resize(n);
	for (auto &i : m)
		cin >> i;

	vector<ll> cnt(p, 0);
	for (auto i : m)
		cnt[i % p]++;
	for (ll i = 0; i < p; i++)
		if (cnt[i] > 1) {
			work(0);
		}

	ll ans = 1;
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			ans *= abs(m[i] - m[j]);
			ans %= p;
		}
	}
	work(ans);
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