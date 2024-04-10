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

ll n, ans = inf;
vector<ll> v;
bool viv = false;

void check(ll c) {
	ll lans = 0;
	ll p = 1;
	for (int i = 0; i < n; i++) {
		lans += abs(v[i] - p);
		if (p > inf / c)
			return;
		p *= c;
	}
	ans = min(ans, lans);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	if (n > 100) {
		ll ans = 0;
		for (auto i : v)
			ans += (abs(i - 1));
		cout << ans;
		return;
	}
	for (int i = 1; i < ml / 10; i++)
		check(i);
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}