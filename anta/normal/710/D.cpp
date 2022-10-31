#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int exgcd(int a, int b, int &g) {
	int u = 1, v = 0;
	while(b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	g = a;
	return u;
}

long long crt(long long a1, long long n1, int a2, int n2, long long &resn) {
	int t, g;
	t = exgcd(n1 % n2, n2, g);
	if((a1 - a2) % g != 0) return -1;
	int n2_g = n2 / g;
	int d = (a2 - a1) / g % n2_g;
	int h = (long long)d * t % n2_g;
	if(h < 0) h += n2_g;
	long long n = n1 * n2_g;
	long long a = a1 + n1 * h;
	resn = n;
	return a;
}

template<typename T, typename U>
inline auto floordiv(T x, U y) -> decltype(x / y) {
	auto q = x / y, r = x % y;
	return q - ((r != 0) & ((r<0) ^ (y<0)));
}

int main() {
	int a1; int b1; int a2; int b2;
	while(~scanf("%d%d%d%d", &a1, &b1, &a2, &b2)) {
		int L; int R;
		scanf("%d%d", &L, &R);
		int o1 = floordiv(b1, a1);
		int o2 = floordiv(b2, a2);
		b1 -= o1 * a1;
		b2 -= o2 * a2;
		long long a3, b3;
		b3 = crt(b1, a1, b2, a2, a3);
		ll ans = 0;
		if(b3 != -1) {
			ll o3 = max(
				floordiv((ll)o1 * a1 + b1 - b3 - 1, a3) + 1,
				floordiv((ll)o2 * a2 + b2 - b3 - 1, a3) + 1);
			ll r = floordiv(R - b3, a3);
			ll l = max(floordiv(L - b3 - 1, a3) + 1, o3);
			ans = max(r + 1 - l, 0LL);
		}
		printf("%lld\n", ans);
	}
	return 0;
}