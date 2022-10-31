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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> dp(n+1, INF), dpprev(n+1, -1);
		vi v;
		rep(i, 1 << 7) if(i != 0) {
			int x = 0;
			rep(j, 7)
				x = x * 10 + (i >> j & 1);
			if(x <= n)
				v.push_back(x);
		}
		dp[0] = 0;
		rep(i, n) {
			int x = dp[i];
			if(x == INF) continue;
			each(j, v) {
				int t = i + *j;
				if(t <= n && dp[t] > x + 1) {
					dp[t] = x + 1;
					dpprev[t] = *j;
				}
			}
		}
		vi ans;
		for(int i = n; i > 0; ) {
			int t = dpprev[i];
			ans.push_back(t);
			i -= t;
		}
		printf("%d\n", (int)ans.size());
		rep(i, ans.size()) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}