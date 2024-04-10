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
	long long k; long long d; long long t;
	while (~scanf("%lld%lld%lld", &k, &d, &t)) {
		d = (k + (d - 1)) / d * d;
		double lo = 0, up = 2e18;
		rep(ii, 100) {
			double mid = (lo + up) * .5;
			double on = 0;
			auto q = floor(mid / d), r = mid - q * d;
			on += q * k;
			on += min(r, (double)k);
			(t <= on + (mid - on) / 2 ? up : lo) = mid;
		}
		printf("%.10f\n", (lo + up) * .5);
	}
	return 0;
}