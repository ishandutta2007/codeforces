#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 105;
int t, n, a[N], b[N], dp[N][N * N], sum[N];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		rep(i, 1, n) sum[i] = sum[i - 1] + a[i] + b[i];
		rep(i, 0, n) rep(j, 0, 100 * n) dp[i][j] = inf;
		dp[0][0] = 0;
		rep(i, 1, n) {
			rep(sa, 0, (i - 1) * 100) {
				int sb = sum[i - 1] - sa;
				dp[i][sa + a[i]] = min(dp[i][sa + a[i]], dp[i - 1][sa] + a[i] * sa + b[i] * sb);
				dp[i][sa + b[i]] = min(dp[i][sa + b[i]], dp[i - 1][sa] + b[i] * sa + a[i] * sb);
			}
		}
		ll ans = infll;
		rep(s, 0, 100 * n) ans = min(ans, 1ll * dp[n][s]);
		ans *= 2;
		rep(i, 1, n) ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
		cout << ans << endl;
	}
	return 0;
}