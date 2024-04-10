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

ll n, c;
vector<ll> a, b;
bool viv = false;


void solve() {
	cin >> n >> c;
	a.resize(n);
	b.resize(n - 1);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	ll ans = (c + a[0] - 1) / a[0];
	ll have = 0;
	ll sum_days = 0;
	if (viv)
		cout << 0 << ": " << ans << " from " << sum_days << '\n';
	for (int i = 1; i < n; i++) {
		ll days = (b[i - 1] + a[i - 1] - 1 - have) / a[i - 1];
		days = max(days, 0ll);
		sum_days += days;
		sum_days++;
		have += days * a[i - 1];
		have -= b[i - 1];
		ll now = (c - have + a[i] - 1) / a[i] + sum_days;
		if (viv)
			cout << i << ": " << now << " from " << sum_days << '\n';
		ans = min(ans, now);
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