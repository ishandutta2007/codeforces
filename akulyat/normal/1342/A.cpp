#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;
vector<ll> v;

void solve() {
	ll a, b, x, y;
	cin >> x >> y >> a >> b;
	ll z = min(abs(x), abs(y));
	b = min(b, 2 * a);
	ll ans = 0;
	ans += z * b;
	if (x < 0)
		x += z;
	else
		x -= z;
	if (y < 0)
		y += z;
	else
		y -= z;
	ans += a * (abs(x) + abs(y));
	cout << ans << '\n';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}