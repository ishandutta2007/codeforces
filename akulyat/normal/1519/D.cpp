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
vector<ll> a, b;
bool viv = false;


void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];

	ll dp[n + 1][n + 1];
	for (int i = 0; i < n; i++) 
		dp[i][i] = dp[i + 1][i] = sum;

	ll ans = sum;
	for (int len = 1; len < n; len++) {
		for (int i = 0; i < n - len; i++) {
			int l = i;
			int r = i + len;
			ll a1 = a[l];
			ll a2 = a[r];
			ll b1 = b[l];
			ll b2 = b[r];

			dp[i][i + len] = dp[i + 1][i + len - 1] - a1 * b1 - a2 * b2 + a1 * b2 + a2 * b1;
			// cout << i << " - " << i + len << ": " << dp[i][i + len] << '\n';
			ans = max(ans, dp[i][i + len]);
		}
	}
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