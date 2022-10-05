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
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	ll mx = v[0];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < mx) {
			int lans = 0;
			int d = mx - v[i];
			while (d)
				lans++, d >>= 1;
			ans = max(ans, lans);
		}
		mx = max(mx, v[i]);
	}
	cout << ans << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}