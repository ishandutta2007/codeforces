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
		vector<vi> dp(n + 1, vi(3, INF));
		dp[0][2] = 0;
		rep(i, n) rep(j, 3) {
			int x = dp[i][j];
			if(x == INF) continue;
			rep(k, 2) if((a[i] >> k & 1) && k != j)
				amin(dp[i + 1][k], x);
			amin(dp[i + 1][2], x + 1);
		}
		int ans = *min_element(dp[n].begin(), dp[n].end());
		printf("%d\n", ans);
	}
	return 0;
}