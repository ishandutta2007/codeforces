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
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<double> dp(n + 1), ndp(n + 1);
		ndp[0] = 1;
		vector<double> probs;
		rep(k, 10000) {
			dp.swap(ndp);
			ndp.assign(n + 1, 0);
			probs.push_back(dp[n]);
			rep(i, n + 1) {
				double x = dp[i];
				if (x < 1e-99) continue;
				double p = i * 1. / n;
				ndp[i] += x * p;
				if(i < n)
					ndp[i + 1] += x * (1 - p);
			}
		}
		rep(i, q) {
			int p;
			scanf("%d", &p);
			double x = (p - 1e-7) / 2000.;
			int ans = (int)(lower_bound(probs.begin(), probs.end(), x) - probs.begin());
			printf("%d\n", ans);
		}
	}
	return 0;
}