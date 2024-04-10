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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
bool viv = false;

vector<ll> get(string s) {
	int n = s.size();
	vector<ll> res(n + 1, 1);
	bool good = true;
	for (int i = 1; i < n; i++) {
		good &= (s[i] != s[i - 1]);
		res[i + 1] = good;
	}
	return res;
}

vector<ll> get_nice(string s) {
	int n = s.size();
	vector<ll> res(n, 1);
	for (int i = 1; i < n; i++)
		if (s[i] != s[i - 1])
			res[i] += res[i - 1];
	return res;
}

void solve() {
	string s, t;
	cin >> s >> t;
	n = s.size(), m = t.size();


	vector<ll> prefs = get(s);
	vector<ll> preft = get(t);
	vector<ll> nices = get_nice(s);
	vector<ll> nicet = get_nice(t);

	vector<vector<ll>> dp[2];
	dp[0].resize(n + 1, vector<ll>(m + 1, 0));
	dp[1].resize(m + 1, vector<ll>(n + 1, 0));

	for (int i = 0; i < n; i++)
		dp[0][i + 1][0] = nices[i];
	for (int i = 0; i < m; i++)
		dp[1][i + 1][0] = nicet[i];

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i && s[i] != s[i - 1])
				dp[0][i + 1][j + 1] += dp[0][i][j + 1];
			if (s[i] != t[j])
				dp[0][i + 1][j + 1] += dp[1][j + 1][i];
			if (i && s[i] != t[j])
				dp[0][i + 1][j + 1] += nicet[j];
			dp[0][i + 1][j + 1] %= mod;
	
			if (j && t[j] != t[j - 1])
				dp[1][j + 1][i + 1] += dp[1][j][i + 1];
			if (t[j] != s[i])
				dp[1][j + 1][i + 1] += dp[0][i + 1][j];
			if (j && t[j] != s[i])
				dp[1][j + 1][i + 1] += nices[i];
			dp[1][j + 1][i + 1] %= mod;

			if (viv) {
	 			cout << "0 " << i + 1 << ' ' << j + 1 << ": " << dp[0][i + 1][j + 1] << endl;
				cout << "1 " << j + 1 << ' ' << i + 1 << ": " << dp[1][j + 1][i + 1] << endl;
			}

			ans += dp[0][i + 1][j + 1];
			ans += dp[1][j + 1][i + 1];	
			ans %= mod;
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