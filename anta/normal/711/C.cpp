#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m; int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		vector<int> c(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		vector<vector<ll> > p(n, vector<ll>(m));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j)
			scanf("%lld", &p[i][j]);
		rep(i, n) if(c[i] != 0) {
			rep(j, m) {
				p[i][j] = c[i] == j + 1 ? 0 : INFL;
			}
		}
		vector<vector<ll>> dp(n + 1, vector<ll>((m + 1) * (k + 2), INFL));
		dp[0][m * (k + 2) + 0] = 0;
		rep(i, n) rep(j, m + 1) rep(kk, k + 1) {
			ll x = dp[i][j * (k + 2) + kk];
			if(x == INFL) continue;
			rep(l, m) {
				int nk = kk + (j != l);
				amin(dp[i + 1][l * (k + 2) + nk], x + p[i][l]);
			}
		}
		ll ans = INFL;
		rep(j, m)
			amin(ans, dp[n][j * (k + 2) + k]);
		if(ans == INFL) {
			puts("-1");
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}