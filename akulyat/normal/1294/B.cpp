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
 
short n, k;
vector<pll> m;
bool viv = false;


void solve() {
	cin >> n;
	m.clear();
	m.resize(n);
	for (auto &p : m) {
		cin >> p.F;
		cin >> p.S;
	}
	m.push_back({0, 0});
	sort(m.begin(), m.end());	
	string s;
	for (ll i = 1; i < n + 1; i++) {
		ll r = m[i].F - m[i-1].F;
		ll u = m[i].S - m[i-1].S;
		if (r < 0 || u < 0) {
			cout << "NO\n";	
			return;	
		}
		while (r > 0)
			s += 'R', r--;
		while (u > 0)
			s += 'U', u--;
	}
	cout << "YES\n";
	cout << s << '\n';
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