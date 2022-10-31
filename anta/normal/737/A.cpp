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
	int n; int k; int s; int t;
	while(~scanf("%d%d%d%d", &n, &k, &s, &t)) {
		vector<int> c(n);
		vector<int> v(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &c[i], &v[i]);
		vector<int> g(k + 2);
		for(int i = 0; i < k; ++ i)
			scanf("%d", &g[i + 2]);
		g[0] = 0, g[1] = s;
		sort(g.begin(), g.end());
		vector<ll> xs;
		rep(i, k + 1) {
			ll x = g[i + 1] - g[i];
			xs.push_back(x * 2LL);
		}
		sort(xs.begin(), xs.end());
		vector<ll> sum(xs.size() + 1);
		rep(i, xs.size())
			sum[i + 1] = sum[i] + xs[i];
		int ans = INF;
		rep(i, n) if(xs.back() / 2 <= v[i]) {
			//xs <= v[i] / 2
			int m = (int)(upper_bound(xs.begin(), xs.end(), v[i]) - xs.begin());
			ll T = 0;
			T += sum[m] / 2;
			T += (sum[xs.size()] - sum[m]) / 2 * 3;
			T -= (xs.size() - m) * v[i];
			if(T <= t)
				amin(ans, c[i]);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}