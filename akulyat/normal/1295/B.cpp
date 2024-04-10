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
	ll n, x;
	string s;
	cin >> n >> x;
	x = -x;	
	cin >> s;
	ll b = 0;
	for (auto i : s) 
		if (i == '1')
			b++;
		else
			b--;

	ll now = 0;
	ll ans = 0;
	for (auto i : s) {
		ll left = x - now;
		if (left == 0 && b == 0) {
			cout << -1 << '\n';
			return;
		}
//		cout << left << ' ' << b << endl;
		if (b != 0) {
			ll r = left / b;
			if (r >= 0 && r * b == left)
				ans++;
		}
		if (i == '1')
			now++;
		else
			now--;
	}
	cout << ans << endl;
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