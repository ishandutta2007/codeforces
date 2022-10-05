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
vector<long long> v, dp;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;	
	dp.assign(n, 0);
	multiset<int> seg;
	for (int i = n - 1; i >= 0; i--) {
		long long want = 0;
		for (int j = i + 2; j < n; j++) {
			if (j - i <= v[i]) {
				want++;
			}
			long long can = min(want, dp[j]);
			dp[j] -= can;
			want -= can;
		}
		dp[i] = v[i] - 1;
	}
	long long ans = 0;
	for (auto i : dp)
		ans += i;
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