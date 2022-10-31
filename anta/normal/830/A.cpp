#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n; int k; int p;
	while (~scanf("%d%d%d", &n, &k, &p)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> b(k);
		for (int i = 0; i < k; ++ i)
			scanf("%d", &b[i]);
		rep(i, n)
			a[i] -= p;
		rep(i, k)
			b[i] -= p;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll ans = INFL;
		rer(i, 0, k - n) {
			ll t = 0;
			rep(j, n) {
				ll u = abs((ll)a[j] - b[i + j]) + abs(b[i + j]);
				amax(t, u);
			}
			amin(ans, t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}