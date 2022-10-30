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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INFL));
		dp[n][0] = 0;
		for(int i = n - 1; i >= 0; -- i) rep(j, n - i) {
			ll x = dp[i + 1][j];
			amin(dp[i][j], max(0LL, x - a[i]));
			amin(dp[i][j + 1], x);
		}
		vector<ll> list(n + 1);
		list[n] = 0;
		for(int j = n - 1; j >= 0; -- j)
			list[j] = max(list[j + 1], dp[0][j]);
		rep(i, m) {
			long long b;
			scanf("%lld", &b);
			int ans = (int)(lower_bound(list.begin(), list.end(), b, greater<ll>()) - list.begin());
			printf("%d\n", ans);
		}
	}
	return 0;
}