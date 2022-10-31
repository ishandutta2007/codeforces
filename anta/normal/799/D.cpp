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
	int H; int W; int h; int w;
	while (~scanf("%d%d%d%d", &H, &W, &h, &w)) {
		int n;
		scanf("%d", &n);
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		sort(as.begin(), as.end());
		reverse(as.begin(), as.end());
		int ans = INF;
		rep(hw, 2) {
			int A = (H + h - 1) / h, B = (W + w - 1) / w;
			if (A == 1 && B == 1) {
				amin(ans, 0);
				continue;
			}
			vector<int> dp(A + 1, -1);
			dp[1] = 1;
			rep(i, n) {
				for (int j = A; j >= 1; -- j) {
					int x = dp[j];
					if (x == -1) continue;
					int nj = (int)min((ll)j * as[i], (ll)A);
					amax(dp[nj], x);
					int nx = (int)min((ll)x * as[i], (ll)B);
					dp[j] = nx;
				}
				if (dp[A] == B) {
					amin(ans, i + 1);
					break;
				}
			}
			swap(h, w);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}