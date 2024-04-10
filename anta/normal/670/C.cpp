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
		map<int, int> cnt;
		vector<int> a(n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
			++ cnt[a[i]];
		}
		int m;
		scanf("%d", &m);
		vector<int> b(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &b[i]);
		vector<int> c(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &c[i]);
		pair<pii, int> ans(mp(-1, -1), -1);
		rep(i, m) {
			int x = cnt[b[i]];
			int y = cnt[c[i]];
			amax(ans, mp(mp(x, y), i));
		}
		printf("%d\n", ans.second + 1);
	}
	return 0;
}