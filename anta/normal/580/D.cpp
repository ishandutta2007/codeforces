#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		vi a(n);
		rep(i, n) scanf("%d", &a[i]);
		vector<vi> g(n, vi(n, 0));
		rep(i, k) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c), -- x, -- y;
			g[x][y] += c;
		}
		vector<ll> dp(n << n, -INFL);
		rep(i, n)
			dp[(1 << i) * n + i] = a[i];
		rep(i, 1 << n) rep(j, n) {
			ll x = dp[i * n + j];
			if(x < 0) continue;
			rep(k, n) if(~i >> k & 1)
				amax(dp[(i | 1 << k) * n + k], x + a[k] + g[j][k]);
		}
		ll ans = 0;
		rep(i, 1 << n) {
			int p = 0;
			rep(j, n) p += i >> j & 1;
			if(p == m) {
				rep(j, n)
					amax(ans, dp[i * n + j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}