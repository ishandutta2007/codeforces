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
	int n; int m; int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		int x; int s;
		scanf("%d%d", &x, &s);
		vector<int> a(m + 1);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &a[i + 1]);
		vector<int> b(m + 1);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &b[i + 1]);
		a[0] = x, b[0] = 0;
		vector<int> c(k + 1);
		for(int i = 0; i < k; ++ i)
			scanf("%d", &c[i + 1]);
		vector<int> d(k + 1);
		for(int i = 0; i < k; ++ i)
			scanf("%d", &d[i + 1]);
		c[0] = d[0] = 0;
		assert(is_sorted(d.begin(), d.end()));
		for(int i = 1; i <= k; ++ i)
			amax(c[i], c[i - 1]);
		ll ans = INFL;
		rep(i, m + 1) {
			int p = a[i], q = s - b[i];
			int j = (int)(upper_bound(d.begin(), d.end(), q) - d.begin()) - 1;
			if(j == -1) continue;
			amin(ans, (ll)max(0, n - c[j]) * p);
		}
		printf("%lld\n", ans);
	}
	return 0;
}