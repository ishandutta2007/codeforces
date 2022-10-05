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

ll n;
vector<ll> a, b;
bool viv = false;


void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(n);
	for (auto &i : b)
		cin >> i;

	ll ma = mod, mb = mod;
	for (auto i : a)
		ma = min(ma, i);
	for (auto i : b)
		mb = min(mb, i);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll va = a[i] - ma;
		ll vb = b[i] - mb;
		ans += max(va, vb);
	}
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