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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n;
vector<int> v;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	vector<vector<int>> pl(n);
	for (int i = 0; i < n; i++)
		pl[i].push_back(-1);
	for (int i = 0; i < n; i++)
		pl[v[i]].push_back(i);
	for (int i = 0; i < n; i++)
		pl[i].push_back(n);

	vector<vector<int>> dp(n, vector<int>(n, mod));
	for (int i = 1; i < n; i++)
		dp[i][i - 1] = 0;
	for (int l = 1; l <= n; l++) {
		if (viv)
			cout << "l = " << l << endl;
		for (int i = 0, j = i + l - 1; j < n; i++, j++) {
			if (l == 1) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + (v[j] != v[j - 1]));
				dp[i][j] = min(dp[i][j], dp[i + 1][j] + (v[i] != v[i + 1]));

				int lv = v[i];
				int npl = *upper_bound(pl[lv].begin(), pl[lv].end(), i);
				while (npl <= j) {
					dp[i][j] = min(dp[i][j], dp[i][npl] + dp[npl][j]);
					npl = *upper_bound(pl[lv].begin(), pl[lv].end(), npl);
				}

				if (v[i] == v[j]) {
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);					
				}
			}
			if (viv)	
				cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}
	cout << dp[0][n - 1] << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}