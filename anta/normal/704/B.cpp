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
	int n; int s; int e;
	while(~scanf("%d%d%d", &n, &s, &e)) {
		-- s, -- e;
		vector<int> pos(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &pos[i]);
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> b(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &b[i]);
		vector<int> c(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		vector<int> d(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &d[i]);
		vector<int> diffs(n + 1);
		//i
		rep(i, n + 1) {
			int diff;
			if(i <= min(s, e))
				diff = 0;
			else if(i <= max(s, e))
				diff = s < e ? -1 : 1;
			else
				diff = 0;
			diffs[i] = diff;
		}
		vector<ll> dp, ndp(n + 1, INFL);
		ndp[0] = 0;
		rep(i, n) {
			dp.swap(ndp);
			ndp.assign(n + 1, INFL);
			int m = i == n - 1 ? 0 : pos[i + 1] - pos[i];
			int fromCost[3] = { a[i], 0, b[i] };
			int toCost[3] = { c[i], 0, d[i] };
			rep(j, n) if(i == 0 || j > 0 || j + diffs[i] > 0) {
				ll x = dp[j];
				if(x == INFL) continue;
				rer(from, -1, 1) rer(to, -1, 1) {
					if((from == 0) != (i == s))
						continue;
					if((to == 0) != (i == e))
						continue;
					if(j < (from == -1 ? 1 : 0))
						continue;
					if(j + diffs[i] < (to == -1 ? 1 : 0))
						continue;
					int nj = j - (from == -1 ? 1 : 0) + (to == 1 ? 1 : 0);
					if(nj + diffs[i + 1] < (from == 1 ? 1 : 0))
						continue;
					ll cost = x;
					cost += fromCost[from + 1];
					cost += toCost[to + 1];
					cost += (ll)(nj * 2 + diffs[i + 1]) * m;
					amin(ndp[nj], cost);
				}
			}
		}
		ll ans = ndp[0];
		printf("%lld\n", ans);
	}
	return 0;
}