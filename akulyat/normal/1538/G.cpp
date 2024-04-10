#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll x, y, a, b;
vector<ll> v;
bool viv = false;

bool can(int cnt) {
	ll fx = x, fy = y;
	fx -= a * cnt;
	fy -= a * cnt;
	if (fx < 0 || fy < 0)
		return false;
	if (b - a) {
		ll add = fx / (b - a);
		add += fy / (b - a);
		return (add >= cnt);
	}
	return true;
}

void solve() {
	cin >> x >> y >> a >> b;
	if (a > b)
		swap(a, b);

	ll l = -1;
	ll r = 2 * mod;
	while (l + 1 < r) {
		ll m = l + r >> 1;
		if (can(m))
			l = m;
		else
			r = m;
	}
	cout << l << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}