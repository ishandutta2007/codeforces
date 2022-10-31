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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> f(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &f[i]);
		vector<int> b(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &b[i]);
		vector<int> idx(n + 1, -1), cnt(n + 1);
		rep(i, n) {
			++ cnt[f[i]];
			idx[f[i]] = i;
		}
		bool am = false;
		bool ok = true;
		vi ans(m);
		rep(i, m) {
			ok &= idx[b[i]] != -1;
			am |= cnt[b[i]] > 1;
			ans[i] = idx[b[i]] + 1;
		}
		if(!ok) {
			puts("Impossible");
		}else if(am) {
			puts("Ambiguity");
		} else {
			puts("Possible");
			for(int i = 0; i < m; ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}