#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

int main() {
	//mt19937 re;
	int n; int a; int b;
	while(~scanf("%d%d%d", &n, &a, &b)) {
		//auto rng = [&]() { return (re() % 1000) * 1e-3; };
		vector<double> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%lf", &p[i]);
		vector<double> u(n);
		for(int i = 0; i < n; ++ i)
			scanf("%lf", &u[i]);
		static float dpbuf[2][2002][2002];
		//memset(dpbuf, 0, sizeof dpbuf);
		auto *dp = dpbuf[0], *ndp = dpbuf[1];
		rep(i, n) {
			const int J = min(a, i), K = min(b, i);
			float y = p[i], z = u[i], w = 1 - (1 - y) * (1 - z);
			ndp[0][0] = dp[0][0];
			rer(j, 1, J + 1) {
				const int k = 0;
				auto *dst = ndp[j], *src0 = dp[j], *src1 = dp[j - 1];
				dst[k] = max(src0[k], src1[k] + y);
			}
			rer(k, 1, K + 1) {
				const int j = 0;
				auto *dst = ndp[j], *src0 = dp[j];
				dst[k] = max(src0[k], src0[k - 1] + z);
			}
			rer(j, 1, J + 1) {
				auto *dst = ndp[j], *src0 = dp[j], *src1 = dp[j - 1];
				rer(k, 1, K + 1)
					dst[k] = max(max(src0[k], src0[k - 1] + z), max(src1[k] + y, src1[k - 1] + w));
			}
			swap(dp, ndp);
		}
		double ans = 0;
		rer(j, 0, a) rer(k, 0, b)
			amax(ans, dp[j][k]);
		printf("%.10f\n", ans);
	}
	return 0;
}