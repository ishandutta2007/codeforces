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
	cin >> n;
	ll even = n / 2;
	ll odd = n - even;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		m.push_back(a);
		if (a != 0) {
			if (a & 1)
				odd--;
			else
				even--;
		}
	}

	vector<vector<vector<vector<ll>>>> dp;
	dp.resize(n + 1);
	for (ll i = 0; i < n + 1; i++) {
		dp[i].resize(n + 1);
		for (ll j = 0; j < n + 1; j++) {
			dp[i][j].resize(n + 1);
			for (ll u = 0; u < n + 1; u++)
				dp[i][j][u].resize(2, mod);
		}
	}
	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	for (ll i = 1; i < n + 1; i++) {
		for (ll j = 0; j <= n / 2; j++) {
			for (ll u = 0; u <= n - n / 2; u++) {
				if (m[i-1] == 0) {
					if (j != 0) {
						dp[i][j][u][0] = min(dp[i-1][j-1][u][0], dp[i-1][j-1][u][1] + 1);
					} else
						dp[i][j][u][0] = mod;
					if (u != 0) {
						dp[i][j][u][1] = min(dp[i-1][j][u-1][0] + 1, dp[i-1][j][u-1][1]);
					} else
						dp[i][j][u][1] = mod;
				} else {
					if (m[i-1] & 1) {
						dp[i][j][u][0] = mod;
						if (u > 0) {
							dp[i][j][u][1] = min(dp[i-1][j][u-1][0] + 1, dp[i-1][j][u-1][1]);
						} else
							dp[i][j][u][1] = mod;
					} else {
						dp[i][j][u][1] = mod;
						if (j > 0) {
							dp[i][j][u][0] = min(dp[i-1][j - 1][u][0], dp[i-1][j-1][u][1] + 1);
						} else
							dp[i][j][u][0] = mod;
					}
				}
//				cout << i << ' ' << j << ' ' << u << ' ' << " : " << dp[i][j][u][0] << ' ' << dp[i][j][u][1] << '\n';
			}
			// cout << endl;
		}
	}
	cout << min(dp[n][n/2][n - n/2][0], dp[n][n/2][n - n/2][1]) << endl;
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