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

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> x(n + 1);
		vector<int> y(n + 1);
		for(int i = 0; i < n + 1; ++ i)
			scanf("%d%d", &x[i], &y[i]);
		vector<int> ds(n);
		rep(i, n) {
			int d;
			if(y[i] != y[i + 1])
				d = y[i] < y[i + 1] ? 0 : 2;
			else
				d = x[i] < x[i + 1] ? 1 : 3;
			ds[i] = d;
		}
		long long A = 0;
		rep(i, n)
			A += (ll)x[i] * y[i + 1] - (ll)y[i] * x[i + 1];
		assert(A != 0);
		int ans = 0;
		rep(i, n) {
			ans += (ds[(i + 1) % n] - ds[i] + 4) % 4 == (A > 0 ? 1 : 3);
		}
		printf("%d\n", ans);
	}
	return 0;
}