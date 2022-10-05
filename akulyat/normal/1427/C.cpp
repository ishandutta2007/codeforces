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
typedef pair<pii, pii> ppii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = mod; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, r;
vector<vector<ll>> v;
vector<ppii> dp;
bool viv = false;

void work() {

}

void solve() {
	cin >> r >> n;
	dp.resize(n + 1);
	dp[0] = {{0, 0}, {0, 0}};
	vector<int> mx(n + 1);
	mx[0] = 0;
	for (int i = 0; i < n; i++) {
		int j = i;
		ll t, a, b;
		cin >> t >> a >> b;
		a--, b--;
		dp[i + 1] = {{-inf, t}, {a, b}};
		int res = -inf;
		while (j != -1 && t - dp[j].F.S <= kk) {
			if (t - dp[j].F.S >= abs(a - dp[j].S.F) + abs(b - dp[j].S.S)) 
				res = max(res, dp[j].F.F + 1);
			j--;
		}
		if (j != -1)
			res = max(res, mx[j] + 1);
		dp[i + 1].F.F = res;
		mx[i+ 1] = max(mx[i], dp[i + 1].F.F);
	}
	cout << mx.back();
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