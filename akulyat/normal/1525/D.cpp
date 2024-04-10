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

	vector<int> epl, ppl;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0)
			epl.push_back(i);
		else
			ppl.push_back(i);
	}
	vector<vector<ll>> dp(ppl.size() + 1, vector<ll>(epl.size() + 1, inf));
	vector<vector<ll>> mn(ppl.size() + 1, vector<ll>(epl.size() + 1, inf));
	for (int i = 0; i <= epl.size(); i++)
		mn[0][i] = dp[0][i] = 0;
	for (int i = 0; i < ppl.size(); i++) {
		for (int j = 0; j < epl.size(); j++) {
			dp[i + 1][j + 1] = mn[i][j] + abs(ppl[i] - epl[j]);
			mn[i + 1][j + 1] = min(dp[i + 1][j + 1], mn[i + 1][j]);
			// cout << i << ' ' << j << ": " << dp[i + 1][j + 1] << ' ' << mn[i + 1][j + 1] << endl; 
		}
	}
	ll ans = inf;
	for (auto i : dp.back())
		ans = min(ans, i);
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