#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

class BinaryHeapNumbering {
public:
	static uint64_t lca(uint64_t u, uint64_t v) {
		int du = depth(u), dv = depth(v);
		if(du < dv)
			v >>= dv - du;
		else
			u >>= du - dv;
		return u >> bsr((u ^ v) << 1 | 1);
	}

	static int depth(uint64_t u) {
		return bsr(u);
	}

private:

	static int bsr(uint64_t x) {
#if defined(__GNUC__)
		return 63 - __builtin_clzll(x);
#else
		int r = 0;
		if(x & 0xffffffff00000000ULL) x >>= 32, r += 32;
		if(x & 0xffff0000U) x >>= 16, r += 16;
		if(x & 0xff00U) x >>= 8, r += 8;
		if(x & 0xf0U) x >>= 4, r += 4;
		if(x & 0xcU) x >>= 2, r += 2;
		if(x & 0x2U)           r += 1;
		return r;
#endif
	}
};

int main() {
	int q;
	while(~scanf("%d", &q)) {
		map<ll, ll> cost;
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				long long u; long long v; int w;
				scanf("%lld%lld%d", &u, &v, &w);
				ll x = BinaryHeapNumbering::lca(u, v);
				while(u != x) {
					cost[u] += w;
					u /= 2;
				}
				while(v != x) {
					cost[v] += w;
					v /= 2;
				}
			} else if(ty == 2) {
				long long u; long long v;
				scanf("%lld%lld", &u, &v);
				ll x = BinaryHeapNumbering::lca(u, v);
				ll ans = 0;
				while(u != x) {
					ans += cost[u];
					u /= 2;
				}
				while(v != x) {
					ans += cost[v];
					v /= 2;
				}
				printf("%lld\n", ans);
			} else abort();
		}
	}
	return 0;
}