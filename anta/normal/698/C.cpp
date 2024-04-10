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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<double> p(n);
		rep(i, n) scanf("%lf", &p[i]);
		vector<double> ans(n);
		vector<double> dp(1 << n);
		dp[0] = 1;
		rep(i, 1 << n) {
			double x = dp[i];
			if(x < 1e-99) continue;
			double rem = 0;
			int cnt = 0;
			rep(j, n) {
				if(i >> j & 1)
					++ cnt;
				else
					rem += p[j];
			}
			if(rem < 1e-99) continue;
			double cond = 1. / rem;
			rep(j, n) if(~i >> j & 1) {
				double y = x * p[j] * cond;
				if(cnt < k)
					ans[j] += y;
				dp[i | 1 << j] += y;
			}
		}
		rep(i, n) {
			if(i != 0) putchar(' ');
			printf("%.10f", ans[i]);
		}
		puts("");
	}
	return 0;
}