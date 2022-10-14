#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1000007, x = 864197532, N = 50000;
const double eps = 1e-6, Pi = 3.1415926535;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	fop (i,0,n) fop (j,0,m) cin >> a[i][j];
	int dp[n][m][4];
	fop (i,0,n) fop (j,0,m) fop (k,0,4) dp[i][j][k] = 0;
	fop (i,0,n) fop (j,0,m) {
		if (!i && !j) {
			dp[i][j][0] = a[i][j];
		} else if (!i) {
			dp[i][j][0] = dp[i][j - 1][0] + a[i][j];
		} else if (!j) {
			dp[i][j][0] = dp[i - 1][j][0] + a[i][j];
		} else {
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i][j];
		}
	}
	FOP (i,n,0) FOP (j,m,0) {
		if (i == n - 1 && j == m - 1) {
			dp[i][j][1] = a[i][j];
		} else if (i == n - 1) {
			dp[i][j][1] = dp[i][j + 1][1] + a[i][j];
		} else if (j == m - 1) {
			dp[i][j][1] = dp[i + 1][j][1] + a[i][j];
		} else {
			dp[i][j][1] = max(dp[i + 1][j][1], dp[i][j + 1][1]) + a[i][j];
		}
	}
	FOP (i,n,0) fop (j,0,m) {
		if (i == n - 1 && !j) {
			dp[i][j][2] = a[i][j];
		} else if (i == n - 1) {
			dp[i][j][2] = dp[i][j - 1][2] + a[i][j];
		} else if (!j) {
			dp[i][j][2] = dp[i + 1][j][2] + a[i][j];
		} else {
			dp[i][j][2] = max(dp[i + 1][j][2], dp[i][j - 1][2]) + a[i][j];
		}
	}
	fop (i,0,n) FOP (j,m,0) {
		if (!i && j == m - 1) {
			dp[i][j][3] = a[i][j];
		} else if (!i) {
			dp[i][j][3] = dp[i][j + 1][3] + a[i][j];
		} else if (j == m - 1) {
			dp[i][j][3] = dp[i - 1][j][3] + a[i][j];
		} else {
			dp[i][j][3] = max(dp[i - 1][j][3], dp[i][j + 1][3]) + a[i][j];
		}
	}
	int ans = 0;
	fop (i,1,n - 1) fop (j,1,m - 1) {
		ans = max(ans, dp[i][j - 1][0] + dp[i + 1][j][2] + dp[i][j + 1][1] + dp[i - 1][j][3]);
		ans = max(ans, dp[i - 1][j][0] + dp[i][j - 1][2] + dp[i + 1][j][1] + dp[i][j + 1][3]);
	}
	cout << ans << endl;
}