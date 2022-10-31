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
#include <fstream>
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
	int n; int d; int h;
	while(~scanf("%d%d%d", &n, &d, &h)) {
		assert(n - 1 >= d && d >= h && h >= 1);
		if((d == 1 && n > 2) || h < (d + 1) / 2) {
			puts("-1");
			continue;
		}
		vi par(n, -1);
		rep(i, h)
			par[i + 1] = i;
		if(h < d) {
			par[h + 1] = 0;
			rep(i, d - h - 1)
				par[h + i + 2] = h + i + 1;
		}
		rep(i, n - (d + 1))
			par[n - 1 - i] = h - 1;
		rep(i, n - 1)
			printf("%d %d\n", par[i + 1] + 1, i + 2);
	}
	return 0;
}