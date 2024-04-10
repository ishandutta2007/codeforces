#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

ll calc(ll n) {
	ll res = 0;
	for(int k = 2; ; ++ k) {
		ll b = (ll)k * k, c = b * k;
		if(n < c) break;
		res += n / c;
	}
	return res;
}

int main() {
	long long m;
	while(~scanf("%lld", &m)) {
		ll lo = 0, up = 10000000000000000;
		while(up - lo > 0) {
			ll mid = (lo + up) / 2;
			if(calc(mid) >= m)
				up = mid;
			else
				lo = mid + 1;
		}
		ll ans = calc(lo) == m ? lo : -1;
		printf("%lld\n", ans);
	}
	return 0;
}