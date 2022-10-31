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
	int n;
	while (~scanf("%d", &n)) {
		vector<int> w(n * 2);
		for (int i = 0; i < n * 2; ++ i)
			scanf("%d", &w[i]);
		sort(w.begin(), w.end());
		vector<vi> dp(n * 2 + 1, vi(3, INF));
		dp[0][0] = 0;
		rep(i, n * 2) rep(j, 3) {
			int x = dp[i][j];
			if (x == INF) continue;
			if (i + 2 <= n * 2)
				amin(dp[i + 2][j], x + (w[i + 1] - w[i]));
			if (j < 2)
				amin(dp[i + 1][j + 1], x);
		}
		int ans = dp.back()[2];
		printf("%d\n", ans);
	}
	return 0;
}