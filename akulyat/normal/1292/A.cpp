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
 
ll n, q, bad;
vector<vector<ll>> ban;
bool viv = false;

bool banned(ll a, ll b) {
	if (b < 0)
		return false;
	if (b >= n)
		return false;
	return ban[a][b];
}

void add(ll a, ll b, ll val) {
	ll v = 0;
	v += banned(a ^ 1, b - 1);
	v += banned(a ^ 1, b);
	v += banned(a ^ 1, b + 1);

	v *= val;
	bad += v;
}

void solve() {
	cin >> n >> q;
	ban.resize(2);
	ban[0].resize(n);
	ban[1].resize(n);
	while (q--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		ban[a][b] ^= true;
		if (ban[a][b])
			add(a, b, 1);
		else
			add(a, b, -1);
		if (ban[0][0] || ban[1][n - 1] || bad)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
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