#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }

long long nCr_saturated(long long n, long long k) {
	if(k > n) return 0;
	if(k > n / 2) k = n - k;
	if(k == 0) return 1;
	long long r = 1;
	for(int j = 1; j <= k; j ++) {
		ll a = n - k + j; int b = j;
		{
			int g = gcd((int)((n - k) % j), j);
			a /= g, b /= g;
		}
		r /= b;
		if(r * 1. * a > 2e18)
			return (long long)1e18 + 1;
		r *= a;
	}
	return min(r, (long long)1e18 + 1);
}

long long nCr(long long n, ll k) {
	return nCr_saturated(n, k);
}

long long calcCount(long long bound, ll c0, ll c1) {
	assert(c0 <= c1);
	long long r = 0;
	for(ll x = 0; (long long)x * c1 < bound; ++ x) {
		long long y = (bound - (long long)x * c1 - 1) / c0;
		//\sum_{i=0}^y C(x+i,x) = C(x+y+1,x+1)
		r += nCr(x + y + 1, x + 1);
		if(r > 1e18) return INFL;
	}
	return r;
}

long long calcSum(ll x, long long y, ll c0, ll c1) {
	return (y + 1) * nCr(x + y + 1, x) * (c0 * y + c1 * (x + 2LL)) / (x + 2);
}

int main() {
	int n; int c0; int c1;
	while(~scanf("%d%d%d", &n, &c0, &c1)) {
		if(c0 > c1) swap(c0, c1);
		if(c0 == 0) {
			long long ans = (long long)c1 * (n - 1);
			printf("%lld\n", ans);
			continue;
		}
		long long lo = 0, up = 1;
		while(calcCount(up, c0, c1) < n - 1) up *= 2;
		while(up - lo > 0) {
			long long mid = (lo + up + 1) / 2;
			if(calcCount(mid, c0, c1) > n - 1)
				up = mid - 1;
			else
				lo = mid;
		}
		long long bound = up;
		cerr << bound << ": " << calcCount(bound, c0, c1) << ", " << calcCount(bound + 1, c0, c1) << endl;
		long long ans = 0;
		for(ll x = 0; (long long)x * c1 < bound; ++ x) {
			long long y = (bound - (long long)x * c1 - 1) / c0;
			ans += (c1 * x + c0 * (y + 1)) * nCr(x + y, x);
			//i >= (bound - c1 * (x + 1)) / c0
			long long iL = (bound - c1 * (x + 1) + c0 - 1) / c0;
			if(y < iL) continue;
			ans += calcSum(x, y, c0, c1);
			if(0 < iL) ans -= calcSum(x, iL - 1, c0, c1);
		}
		ll rem = (n - 1) - calcCount(bound, c0, c1);
		assert(rem >= 0);
		ans += rem * (bound + c0 + c1);
		printf("%lld\n", ans);
	}
	return 0;
}