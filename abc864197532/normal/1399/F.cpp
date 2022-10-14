#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 18, K = 350;

void solve() {
	int n;
	cin >> n;
	vector <pii> a(n);
	vector <int> v;
	fop (i,0,n) {
		cin >> a[i].X >> a[i].Y;
		v.pb(a[i].X);
		v.pb(a[i].Y);
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	int m = v.size();
	vector <int> seg[m];
	set <pii> cnt;
	fop (i,0,n) {
		a[i].X = lower_bound(all(v), a[i].X) - v.begin();
		a[i].Y = lower_bound(all(v), a[i].Y) - v.begin();
		seg[a[i].Y].pb(a[i].X);
		cnt.insert({a[i].X, a[i].Y});
	}
	vector <vector <int>> dp(m, vector <int> (m, 0));
	fop (d,0,m) fop (i,0,m) {
		int j = i + d;
		if (j >= m) break;
		if (i < j) dp[i][j] = dp[i][j - 1];
		for (int k : seg[j]) if (k >= i) {
			dp[i][j] = max(dp[i][j], dp[k][j] + (i <= k - 1 ? dp[i][k - 1] : 0));
		}
		if (cnt.count({i, j})) dp[i][j]++;
	}
	cout << dp[0][m - 1] << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}