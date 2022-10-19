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
int t, n, dp[N], val[N][N], a[N];
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
		rep(l, 1, n) {
			rep(r, l, n) {
				rep(_, 0, 1000) {
					bool flag = 1;
					rep(i, l, r) if (a[i] == _) {
						flag = 0;
						break;
					}
					if (flag) {
						val[l][r] = _ + 1;
						break;
					}
				}
			}
		}
		ll ans = 0;
		rep(l, 1, n) {
			dp[l - 1] = 0;
			rep(i, l, n) {
				dp[i] = 0;
				rep(j, l - 1, i - 1) dp[i] = max(dp[i], dp[j] + val[j + 1][i]);
				ans += dp[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}