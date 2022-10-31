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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> sum(n + 1);
		rep(i, n) sum[i + 1] = sum[i] + a[i];
		const int MaxK = 88 + 1, MaxDiff = 63 + 1;
		const int undef = INF * 2;
		vector<vi> memo((n + 1) * (MaxDiff * 2 + 1), vi((MaxK + 1) * 2, undef));
		int maxK = 0, maxDiff = 0;
		auto rec = [&](auto rec, int L, int R, int k, int turn) -> int {
			amax(maxK, k);
			amax(maxDiff, abs((n - R) - L));
			int &r = memo[L * (MaxDiff * 2 + 1) + (((n - R) - L) + MaxDiff)][k * 2 + turn];
			if(r != undef) return r;
			if(turn == 0) {
				if(L + k > R) {
					r = 0;
				} else {
					r = -INF;
					amax(r, (sum[L + k] - sum[L]) - rec(rec, L + k, R, k, turn ^ 1));
					if(L + k + 1 <= R)
						amax(r, (sum[L + k + 1] - sum[L]) - rec(rec, L + k + 1, R, k + 1, turn ^ 1));
				}
			} else {
				if(L > R - k) {
					r = 0;
				} else {
					r = -INF;
					amax(r, (sum[R] - sum[R - k]) - rec(rec, L, R - k, k, turn ^ 1));
					if(L <= R - k - 1)
						amax(r, (sum[R] - sum[R - k - 1]) - rec(rec, L, R - k - 1, k + 1, turn ^ 1));
				}
			}
			return r;
		};
		int ans = rec(rec, 0, n, 1, 0);
		printf("%d\n", ans);
	}
	return 0;
}