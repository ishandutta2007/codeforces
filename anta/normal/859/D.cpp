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
	int N;
	while (~scanf("%d", &N)) {
		vector<vector<int> > P(1 << N, vector<int>(1 << N));
		for (int i = 0; i < 1 << N; ++ i) for (int j = 0; j < 1 << N; ++ j)
			scanf("%d", &P[i][j]);
		vector<vector<double>> prob(N + 1, vector<double>(1 << N));
		rep(i, 1 << N)
			prob[0][i] = 1;
		rer(k, 1, N) rep(i, 1 << N) {
			double x = 0;
			rep(j, 1 << N) if (i != j && (i >> (k - 1) ^ 1) == (j >> (k - 1)))
				x += prob[k - 1][j] * (P[i][j] * 1e-2);
			x *= prob[k - 1][i];
			prob[k][i] = x;
		}
		vector<vector<double>> dp(N + 1, vector<double>(1 << N));
		rep(i, 1 << N)
			dp[0][i] = 0;
		rer(k, 1, N) {
			rep(i, 1 << N) {
				double x = 0;
				rep(j, 1 << N) if (i != j && (i >> (k - 1) ^ 1) == (j >> (k - 1)))
					amax(x, dp[k - 1][i] + dp[k - 1][j] + prob[k][i] * (1 << (k - 1)));
				dp[k][i] = x;
			}
		}
		double ans = *max_element(dp[N].begin(), dp[N].end());
		printf("%.10f\n", ans);
	}
	return 0;
}