#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int Q;
	while (~scanf("%d", &Q)) {
		vector<uint32_t> pos(100000), neg(100000);
		for (int ii = 0; ii < Q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				int L; int R; int k;
				scanf("%d%d%d", &L, &R, &k), -- L, -- R;
				uint32_t *data = k > 0 ? pos.data() : neg.data();
				uint32_t b = abs(k) - 1;
				reu(x, L, R) {
					auto a = data[x] - 1;
					data[x] = (a < b ? a : b) + 1;
				}
			} else if (ty == 2) {
				int L; int R;
				scanf("%d%d", &L, &R), -- L, -- R;
				ll ans = 0;
				reu(x, L, R) {
						ans += (pos[x] + neg[x]) & ~(
							((int32_t)(pos[x] - 1) >> 31) |
							((int32_t)(neg[x] - 1) >> 31));
				}
				printf("%lld\n", ans);
			} else abort();
		}
	}
	return 0;
}