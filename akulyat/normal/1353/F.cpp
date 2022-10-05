#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
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
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> v, dp;
	vector<vector<bool>> can;
	v.resize(n);
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i;
	}
	dp.resize(n);
	for (auto &l : dp)
		l.resize(m);
	can.resize(n);
	for (auto &l : can)
		l.resize(m);

	ll ans = 3 * inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 0;
			can[i][j] = true;
			for (int x = i; x >= 0; x--) {
				for (int y = j; y >= 0; y--) {
					if (x != i || y != j) {
						ll want = (v[i][j] - (i - x) - (j - y));
						dp[x][y] = inf;									
						can[x][y] = false;
						if (y != j && can[x][y + 1]) {
							dp[x][y] = min(dp[x][y + 1] + (v[x][y] - (want)), dp[x][y]);
							can[x][y] = true;
						}
						if (x != i && can[x + 1][y]) {
							dp[x][y] = min(dp[x + 1][y] + (v[x][y] - (want)), dp[x][y]);
							can[x][y] = true;
						}
						can[x][y] = can[x][y] & (v[x][y] >= want);
					}
				}
			}
			for (int x = i; x < n; x++) {
				for (int y = j; y < m; y++) {
					if (x != i || y != j) {
						ll want = (v[i][j] - (i - x) - (j - y));
						dp[x][y] = inf;									
						can[x][y] = false;
						if (y != j && can[x][y - 1]) {
							dp[x][y] = min(dp[x][y - 1] + (v[x][y] - (want)), dp[x][y]);
							can[x][y] = true;
						}
						if (x != i && can[x - 1][y]) {
							dp[x][y] = min(dp[x - 1][y] + (v[x][y] - (want)), dp[x][y]);
							can[x][y] = true;
						}
						can[x][y] = can[x][y] & (v[x][y] >= want);
					}
				}
			}
			if (i == n - 1 && j == m - 1 && viv) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						cout << can[i][j];
					cout << endl;
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						cout << dp[i][j] << '\t';
					cout << endl;
				}
			}
			if (can[0][0] && can[n - 1][m - 1]) {
				if (viv)
					cout << "_____ " << i << ' ' << j << ' ' << dp[0][0] + dp[n - 1][m - 1] << '\n';
				ans = min(ans, dp[0][0] + dp[n - 1][m - 1]);
			}
		}
	}
	// 2 1 0 -1 -2 -3 -4 -5 -6
	// 2 1 5  1  3  8  4  5  2
	// 0 0 5  2  5 11  8 10  8
	// 0 0 5  7 12 23 31 41 49
	cout << ans << '\n';
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