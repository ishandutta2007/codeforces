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

ll n, k;
vector<ll> v;
bool viv = false;
ll dp[10][ml];

void prepare() {
	for (int i = 0; i < 10; i++)
		dp[i][0] = 1;
	for (int j = 1; j < ml; j++) {
		for (int i = 0; i < 10; i++)
			dp[(i + 9) % 10][j] = dp[i][j - 1];
		dp[9][j] += dp[1][j - 1];
		for (int i = 0; i < 10; i++)
			dp[i][j] %= mod;
	}
}

void solve() {
	cin >> k >> n;
	vector<ll> cnt(10, 0);
	while (k) {
		cnt[k % 10] ++;
		k /= 10;
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[i][n] * cnt[i];
	ans %= mod;
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}