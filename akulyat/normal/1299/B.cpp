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
vector<pll> m;
bool viv = false;


void solve() {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		m.push_back({a, b});
	}

	if (n & 1) {
		cout << "No";
		exit(0);
	}

	for (ll i = 0; i < n; i++)
		m.push_back(m[i]);
	for (ll i = 0; i < n; i++)
		m.push_back(m[i]);

	for (ll i = 0; i < n; i++) {
		ll a = 0;
		a += m[i].F;
		a -= m[i + 1].F;
		a += m[i + n/2].F;
		a -= m[i + n/2 + 1].F;
		ll b = 0;
		b += m[i].S;
		b -= m[i + 1].S;
		b += m[i + n/2].S;
		b -= m[i + n/2 + 1].S;
		if (a || b) {
			cout << "No";
			exit(0);
		}
	}
	cout << "YES";

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