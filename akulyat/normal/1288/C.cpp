#include <bits/stdc++.h>
 
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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n;
vector<ll> m;
bool viv = false;

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> dp;
	dp.resize(2 * m + 1);
	for (auto &l : dp)
		l.resize(n);
	dp[0][0] = 1;
	for (ll i = 1; i <= 2 * m; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll u = 0; u <= j; u++)
				dp[i][j] += dp[i-1][u];
			dp[i][j] %= mod;
		}
	}

	ll ans = 0;
	for (auto i : dp.back())
		ans += i;
	ans %= mod;
	cout << ans << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}