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
		vector<int> b(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &b[i]);
		int S = accumulate(a.begin(), a.end(), 0);
		vector<vi> dp(n + 1, vi(S + 1, INF));
		const int Base = (int)1e5;
		dp[0][0] = 0;
		rep(i, n) {
			rep(j, S + 1) {
				int x = dp[i][j];
				if(x == INF) continue;
				amin(dp[i + 1][j], x + a[i]);
				amin(dp[i + 1][min(S, j + b[i])], x + Base);
			}
		}
		int ans = dp[n][S];
		printf("%d %d\n", ans / Base, ans % Base);
	}
	return 0;
}