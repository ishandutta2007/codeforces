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
		vector<int> c(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		vector<string> w(n * 2);
		char buf[100001];
		rep(i, n) {
			scanf("%s", buf);
			w[i * 2 + 0] = buf;
			reverse(buf, buf + strlen(buf));
			w[i * 2 + 1] = buf;
		}
		ll x[2] = {0LL, c[0]};
		reu(i, 1, n) {
			ll nx[2];
			rep(p, 2) {
				ll t = INFL;
				rep(q, 2) {
					if(w[(i - 1) * 2 + q] <= w[i * 2 + p])
						amin(t, x[q]);
				}
				nx[p] = t + p * c[i];
			}
			rep(k, 2)
				x[k] = nx[k];
		}
		ll ans = min(x[0], x[1]);
		if(ans >= INFL)
			puts("-1");
		else
			printf("%lld\n", ans);
	}
	return 0;
}