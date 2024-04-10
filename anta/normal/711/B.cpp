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
		vector<vector<ll> > a(n, vector<ll>(n));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < n; ++ j)
			scanf("%lld", &a[i][j]);
		ll tsum = 0;
		if(n == 1) {
			tsum = 1;
		} else {
			rep(i, n) {
				ll sum = 0;
				bool x = false;
				rep(j, n) {
					x |= a[i][j] == 0;
					sum += a[i][j];
				}
				if(!x) {
					tsum = sum;
					break;
				}
			}
		}
		ll ans = -1;
		rep(i, n) {
			rep(j, n) if(a[i][j] == 0) {
				ans = tsum - accumulate(a[i].begin(), a[i].end(), 0LL);
				if(ans <= 0)
					ans = -1;
				a[i][j] = ans;
			}
		}
		rep(i, n) {
			if(accumulate(a[i].begin(), a[i].end(), 0LL) != tsum)
				ans = -1;
		}
		rep(j, n) {
			ll sum = 0;
			rep(i, n) sum += a[i][j];
			if(sum != tsum) ans = -1;
		}
		{
			ll sum = 0;
			rep(i, n) sum += a[i][i];
			if(sum != tsum) ans = -1;
		}
		{
			ll sum = 0;
			rep(i, n) sum += a[i][n - 1 - i];
			if(sum != tsum) ans = -1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}