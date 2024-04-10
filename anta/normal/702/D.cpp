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
	long long d;
	while(~scanf("%lld", &d)) {
		int k; int a; int b; int t;
		scanf("%d%d%d%d", &k, &a, &b, &t);
		ll ans;
		if(d <= k) {
			ans = (ll)d * a;
		} else if(t + (ll)k * a > (ll)k * b) {
			ans = (ll)k * a + (d - k) * b;
		} else {
			ll q = d / k, r = d % k;
			ans = k * q * a + (q - 1) * t + min(t + r * a, r * b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}