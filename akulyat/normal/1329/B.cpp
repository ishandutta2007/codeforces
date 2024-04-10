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
vector<ll> v;
bool viv = false;


void solve() {
	ll d, m;
	cin >> d >> m;

	vector<vector<ll>> dp;
	dp.resize(34);
	for (auto &l : dp)
		l.resize(34);
	ll ans = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = i; j < 32; j++) {
			ll st = 1ll << j;
			ll dif = min(st * 2, d + 1) - st;
			dif = max(0ll, dif);
			// if (i == 0)
			// 	cout << j << ' ' << dif << endl;
			for (int u = 0; u < j; u++) {
				dp[i + 1][j] += dp[i][u] * dif;
				dp[i + 1][j] %= m;
			}
			if (i == 0)
				dp[i + 1][j] += dif;
			ans += dp[i + 1][j];
			ans %= m;
//			cout << i << ' ' << j << ' ' << dp[i][j];
		}
	}

	cout << ans << endl;



}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}