#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int base;
	while (~scanf("%d", &base)) {
		char K[61];
		scanf("%s", K);
		int len = (int)strlen(K);
		vector<ll> dp(len + 1, INFL);
		dp[0] = 0;
		rep(i, len) {
			ll x = dp[i];
			if (x == INFL) continue;
			ll num = 0;
			rer(j, i + 1, len) {
				num = num * 10 + (K[j - 1] - '0');
				if (num >= base) break;
				if ((double)x * base + num > 1.1e18) break;
				amin(dp[j], x * base + num);
				if (K[i] == '0') break;
			}
		}
		ll ans = dp[len];
		printf("%lld\n", ans);
	}
	return 0;
}