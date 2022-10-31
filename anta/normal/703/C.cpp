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
	int n; int w; int v; int u;
	while(~scanf("%d%d%d%d", &n, &w, &v, &u)) {
		vector<int> x(n);
		vector<int> y(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &x[i], &y[i]);
		bool ok = true;
		rep(i, n)
			ok &= (ll)y[i] * v <= (ll)x[i] * u;
		double ans = 0;
		if(!ok) {
			rep(i, n)
				amax(ans, x[i] * 1. / v - y[i] * 1. / u);
		}
		ans += w * 1. / u;
		printf("%.10f\n", ans);
	}
	return 0;
}