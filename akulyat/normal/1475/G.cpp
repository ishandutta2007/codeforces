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

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	vector<ll> dp(n, 1);
	vector<ll> pl(200 * kk + 1, -1);
	for (int i = 0; i < n; i++) {
		if (pl[v[i]] == -1)
			pl[v[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		if (i + 1 < n && v[i + 1] == v[i])
			dp[i + 1] = dp[i] + 1;
		else {
			for (int j = 2 * v[i]; j < 200 * kk + 1; j += v[i])
				if (pl[j] != -1)
					dp[pl[j]] = max(dp[pl[j]], dp[i] + 1);
		}
		// for (auto i : dp)
		// 	cout << i << ' ';
		// cout << '\n';
	}
	ll ans = n;
	for (auto i : dp)
		ans = min(ans, n - i);
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}