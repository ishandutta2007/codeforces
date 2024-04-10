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
	long long b; long long d; long long s;
	while(~scanf("%lld%lld%lld", &b, &d, &s)) {
		ll ans = INFL;
		rep(p, 3) rep(q, 3) {
			ll x[3] = { b, d, s };
			rep(i, p) ++ x[i];
			reu(i, q + 1, 3) ++ x[i];
			ll days = max({ x[0], x[1], x[2] });
			ll t = days * 3 - accumulate(x, x + 3, 0LL);
			amin(ans, t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}