#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define pii pair<int, int>
#define x first
#define y second

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }

int n;
vector<vector<int>> c;
vector<vector<int>> dp;

void solve() {
	cin >> n;

	c = vector<vector<int>> (2 * n, vector<int> (2 * n));

	int ans = 0;

	for (int i = 0; i < 2 * n; ++i)
	for (int j = 0; j < 2 * n; ++j)
		cin >> c[i][j];

	for (int i = n; i < 2 * n; ++i)
	for (int j = n; j < 2 * n; ++j) {
		ans += c[i][j];
		c[i][j] = 0;
	}

	int res = 1e18;
	res = min(res, c[0][n]);
	res = min(res, c[n - 1][n]);
	res = min(res, c[0][2 * n - 1]);
	res = min(res, c[n - 1][2 * n - 1]);

	res = min(res, c[n][0]);
	res = min(res, c[n][n - 1]);
	res = min(res, c[2 * n - 1][0]);
	res = min(res, c[2 * n - 1][n - 1]);

	cout << ans + res<< '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}