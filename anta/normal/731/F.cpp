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
		int A = *max_element(a.begin(), a.end());
		vector<int> cnt(A + 1);
		rep(i, n) ++ cnt[a[i]];
		vector<int> sumcnt(A + 2);
		rep(i, A + 1)
			sumcnt[i + 1] = sumcnt[i] + cnt[i];
		ll ans = 0;
		rer(x, 1, A) if(cnt[x] > 0) {
			ll total = 0;
			for(int y = x; y <= A; y += x) {
				int c = sumcnt[min(A + 1, y + x)] - sumcnt[y];
				total += (ll)c * y;
			}
			amax(ans, total);
		}
		printf("%lld\n", ans);
	}
	return 0;
}