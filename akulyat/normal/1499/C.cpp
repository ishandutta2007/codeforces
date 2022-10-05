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

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	ll nl = 1, nu = 1;
	ll sl = v[0], su = v[1];
	ll ml = v[0], mu = v[1];
	ll ans = n * (v[0] + v[1]);
	for (int i = 2; i < n; i++) {
		if (!(i & 1)) {
			nl++;
			sl += v[i];
			ml = min(ml, v[i]);
		} else {
			nu++;
			su += v[i];
			mu = min(mu, v[i]);
		}
		ans = min(ans, sl + su + (n - nl) * ml + (n - nu) * mu);
	}
	cout << ans << '\n';
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