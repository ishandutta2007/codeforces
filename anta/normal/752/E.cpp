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
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		int A = *max_element(a.begin(), a.end());
		vector<int> dp;
		int lo = -1, up = A;
		while (up - lo > 0) {
			int mid = (lo + up + 1) / 2;
			dp.assign(A + 1, 0);
			rer(i, mid, A) {
				dp[i] = dp[i / 2] + dp[(i + 1) / 2];
				amax(dp[i], 1);
			}
			ll cnt = 0;
			rep(i, n)
				cnt += dp[a[i]];
			if (cnt >= k)
				lo = mid;
			else
				up = mid - 1;
		}
		printf("%d\n", lo);
	}
	return 0;
}