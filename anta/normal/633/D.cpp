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
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		map<int, int> cnt;
		rep(i, n)
			++ cnt[a[i]];
		vi v;
		int ans = 0;
		if(cnt[0] >= 2)
			amax(ans, cnt[0]);
		rep(i, n) rep(j, n) if(i != j) {
			int x = a[i], y = a[j];
			if(x == 0 && y == 0)
				continue;
			v.clear();
			int len = 0;
			while(1) {
				auto it = cnt.find(x);
				if(it == cnt.end() || it->second == 0)
					break;
				v.push_back(x);
				-- cnt[x];
				++ len;
				int z = x + y;
				x = y, y = z;
			}
			amax(ans, len);
			for(int x : v)
				++ cnt[x];
		}
		printf("%d\n", ans);
	}
	return 0;
}