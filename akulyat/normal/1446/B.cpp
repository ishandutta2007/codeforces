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

ll n, m;
string s, t;
vector<vector<int>> dp;
bool viv = false;


void solve() {
	cin >> n >> m;
	cin >> s >> t;
	dp.resize(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int res = 4 * (s[i] == t[j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + res - 2);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j] - 1);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1] - 1);
			ans = max(ans, dp[i + 1][j + 1]);
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