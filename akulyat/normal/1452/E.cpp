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

ll n, m, k;
vector<pii> v;
bool viv = false;

int com(pii a, pii b) {
	a.F = max(a.F, b.F);
	a.S = min(a.S, b.S);
	int len = a.S - a.F + 1;
	len = max(len, 0);
	return len;
}

void solve() {
	cin >> n >> m >> k;
	v.resize(m);
	for (auto &p : v)
		cin >> p.F >> p.S;

	sort(v.begin(), v.end(), [&](const pii &a, const pii &b) {
		return a.F + a.S < b.F + b.S;
	});

	vector<vector<int>> dp(m, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		for (int st = 0; st <= n; st++) {
			dp[i][st] = com(v[i], (pii){st, st + k - 1});
			// cout << i << ' ' << st << " = " << dp[i][st] << endl;
		}
	}
	vector<int> pref(m + 1, 0);
	vector<int> suf(m + 1, 0);
	vector<vector<int>> fdp;
	vector<int> sum(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int bst = 0;
		for (int st = 0; st <= n; st++) {			
			sum[st] += dp[i][st];
			bst = max(bst, sum[st]);
		}
		pref[i + 1] = bst;
	}
	sum.assign(n + 1, 0);
	for (int i = m - 1; i >= 0; i--) {
		int bst = 0;
		for (int st = 0; st <= n; st++) {			
			sum[st] += dp[i][st];
			bst = max(bst, sum[st]);
		}
		suf[i] = bst;
	}

	int ans = 0;
	for (int p = 0; p <= m; p++) {
		ans = max(ans, pref[p] + suf[p]);
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