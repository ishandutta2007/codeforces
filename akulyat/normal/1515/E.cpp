#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef unsigned long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
// const long long mod = ml * kk + 7;
const ll inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


ll n, mod;
vector<ll> v;
bool viv = false;

ll dp[500][500];
ll C[500][500];

inline ll gc(int n, int k) {
	return (n < 0 || k < 0 || k > n) ? 0 : C[n][k];
}

void prepare() {
	C[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		int s = 0;
		if (i == 0)
			s = 1;
		for (int j = s; j <= n; j++) {
			C[i][j] = gc(i - 1, j) + gc(i - 1, j - 1);
			C[i][j] %= mod;
		}
	}
	// for (int i = 0; i < 7; i++) {
	// 	for (int j = 0; j < 7; j++) {
	// 		cout << C[i][j] << '\t';
	// 	}
	// 	cout << '\n';
	// }
}

void solve() {
	cin >> n >> mod;
	prepare();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;

	int D = 2;
	ll add = 0, sum = 0;
	ll DD = 10 * inf;
	for (int l = 1; l <= n; l++) {
		for (int s = (l + 1) / 2; s <= l; s++) {
			dp[l][s] += dp[l - 1][s - 1];
			if (l != 1)
				dp[l][s] += dp[l - 1][s - 1];
			for (int i = 1; i < l; i++) {
				int lf = i - 1;
				int rg = l - i - 1;
				if (lf <= rg) {
					int cf = (lf != 0) + (rg != 0);
					cf *= 2 * (lf < rg) + (lf == rg);
					for (int ls = (lf + 1) / 2; ls <= lf; ls++) {
						int rs = s - 1 - ls;
						if (rg / 2 <= rs && rs <= rg)
							dp[l][s] += cf * gc(s - 1, ls) * ((dp[lf][ls] * dp[rg][rs]) % mod);
						if (dp[l][s] > DD)
							dp[l][s] %= mod;
					}
				}
				dp[l][s] %= mod;
			}
			for (int i = 1; i < l - 1; i++) {
				int lf = i - 1;
				int rg = l - i - 2;
				if (lf <= rg) {
					int cf = (lf != 0) && (rg != 0);
					cf *= 2 * (lf < rg) + (lf == rg);
					for (int ls = (lf + 1) / 2; ls <= lf; ls++) {
						int rs = s - 1 - ls;
						if (rg / 2 <= rs && rs <= rg)
							dp[l][s] += cf * gc(s - 1, ls) * ((dp[lf][ls] * dp[rg][rs]) % mod);
						if (dp[l][s] > DD)
							dp[l][s] %= mod;
					}
				}
				dp[l][s] %= mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		ans += dp[n][i], ans %= mod;
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