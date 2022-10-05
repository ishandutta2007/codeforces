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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	reverse(v.begin(), v.end());
	vector<vector<ll>> dp(n + 1, vector<ll>(4, inf));
	for (int j = 0; j < 4; j++)
		dp[0][j] = 0;
	vector<vector<ll>> can(4);
	can[0].push_back(2);
	can[0].push_back(3);
	can[1].push_back(0);
	can[2].push_back(0);
	can[2].push_back(1);
	can[3].push_back(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (auto u: can[j]) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][u] + ((j < 2) && (v[i] == 1)));
			}
		}
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
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