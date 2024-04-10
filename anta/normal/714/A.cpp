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
	long long l1; long long r1; long long l2; long long r2;
	while(~scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2)) {
		long long k;
		scanf("%lld", &k);
		ll L = max(l1, l2), R = min(r1, r2);
		ll ans = L > R ? 0 : R + 1 - L - (L <= k && k <= R ? 1 : 0);
		printf("%lld\n", ans);
	}
	return 0;
}