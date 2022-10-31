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
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<pair<int, ll>> dpL(n + 1), dpR(n + 1);
		dpL[0] = { 0, 0 };
		for (int i = 0; i < n; ++ i) {
			int x = max(a[i], dpL[i].first + 1);
			dpL[i + 1] = { x, dpL[i].second + (x - a[i]) };
		}
		dpR[n] = { 0, 0 };
		for (int i = n - 1; i >= 0; -- i) {
			int x = max(a[i], dpR[i + 1].first + 1);
			dpR[i] = { x, dpR[i + 1].second + (x - a[i]) };
		}
		ll ans = INFL;
		rep(i, n) {
			int x = max({ a[i], dpL[i].first + 1, dpR[i + 1].first + 1 });
			ll cost = dpL[i].second + dpR[i + 1].second + (x - a[i]);
			amin(ans, cost);
		}
		printf("%lld\n", ans);
	}
	return 0;
}