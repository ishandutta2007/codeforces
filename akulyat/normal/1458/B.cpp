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
const long long K = 10000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<pii> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	int sum = 0;
	for (auto &p : v) {
		cin >> p.F >> p.S;
		swap(p.F, p.S);
		sum += p.F;
	}
	vector<vector<int>> dp(n + 1, vector<int>(K + 1, -mod));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int was = i; was >= 0; was--) {
			for (int l = 0; l < K + 1 - v[i].F; l++) {
				dp[was + 1][l + v[i].F] = max(dp[was + 1][l + v[i].F], dp[was][l] + v[i].S);
			}
		}
	}
	// for (int i = 0; i <= n; i++) {
	// 	for (int l = 0; l < 20; l++) {
	// 		cout << i << ' ' << l << ": " << dp[i][l] << '\n';
	// 	}
	// }
	cout << fixed << setprecision(10);
	for (int i = 1; i <= n; i++) {
		ld ans = 0;
		for (int l = 0; l <= K; l++) {
			if (dp[i][l] >= 0) {
				ans = max(ans, min((ld)dp[i][l], l + (ld)(sum - l) / 2.0));
			}
		}
		cout << ans << ' ';
	}
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