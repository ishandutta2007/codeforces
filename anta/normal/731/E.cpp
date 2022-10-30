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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<ll> sum(n + 1);
		rep(i, n)
			sum[i + 1] = sum[i] + a[i];
		vector<ll> dp(n + 1, -INFL);
		dp[n] = 0;
		ll mx = -INFL;
		for(int i = n - 1; i >= 1; -- i) {
			amax(mx, sum[i + 1] - dp[i + 1]);
			dp[i] = mx;
		}
		ll ans = dp[1];
		printf("%lld\n", ans);
	}
	return 0;
}