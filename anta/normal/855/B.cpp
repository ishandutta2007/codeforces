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
	int n; int p; int q; int r;
	while (~scanf("%d%d%d%d", &n, &p, &q, &r)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<ll> maxR(n + 1);
		maxR[n] = -INFL;
		for (int i = n - 1; i >= 0; -- i)
			maxR[i] = max(maxR[i + 1], (ll)r * a[i]);
		ll maxL = -INFL;
		ll ans = -INFL;
		rep(i, n) {
			amax(maxL, (ll)p * a[i]);
			amax(ans, maxL + (ll)q * a[i] + maxR[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}