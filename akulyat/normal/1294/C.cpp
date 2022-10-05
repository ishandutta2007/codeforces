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
	ll n;
	cin >> n;
	ll a, b;
	a = b = -1;
	for (ll i = 2; i < 40 * kk; i++) {
		if (!(n % i)) {
			a = i;
			n /= a;
			i = ml;
		}

	}
	if (a == -1) {
		cout << "NO\n";
		return;
	}
	for (ll i = 2; i < 40 * kk; i++) {
		if (!(n % i) && i != a) {
			b = i;
			n /= b;
			i = ml;
		}

	}
	if (b == -1) {
		cout << "NO\n";
		return;
	}
	if (n != a && n != b && n != 1) {
		cout << "YES\n";
		cout << a << ' ' << b << ' ' << n << '\n';
	} else
		cout << "NO\n";
		
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