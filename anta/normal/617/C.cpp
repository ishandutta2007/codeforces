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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

ll sq(int x) { return (ll)x * x; }

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int x1; int y1; int x2; int y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		vector<int> xs(n + 1);
		vector<int> ys(n + 1);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &xs[i], &ys[i]);
		xs[n] = x1, ys[n] = y1;
		ll ans = INFL;
		rep(i, n + 1) {
			ll r1 = sq(xs[i] - x1) + sq(ys[i] - y1);
			ll r2 = 0;
			rep(j, n) if(sq(xs[j] - x1) + sq(ys[j] - y1) > r1)
				amax(r2, sq(xs[j] - x2) + sq(ys[j] - y2));
			amin(ans, r1 + r2);
		}
		cout << ans << endl;
	}
	return 0;
}