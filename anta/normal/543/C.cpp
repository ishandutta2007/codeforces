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
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		vector<vi> a(n, vi(m));
		rep(i, n) rep(j, m)
			scanf("%d", &a[i][j]);
		vector<vi> masks(n, vi(m)), costs(n, vi(m));
		rep(i, n) rep(j, m) {
			masks[i][j] = 1 << i;
			rep(k, n) if(i != k) {
				if(s[i][j] == s[k][j]) {
					masks[i][j] |= 1 << k;
					costs[i][j] += a[k][j];
				}
			}
		}
		vector<int> dp(1 << n, INF);
		dp[0] = 0;
		rep(j, m) rep(k, 1 << n) {
			int x = dp[k];
			if(x == INF) continue;
			rep(i, n) if(~k >> i & 1) {
				amin(dp[k | 1 << i], x + a[i][j]);
				amin(dp[k | masks[i][j]], x + costs[i][j]);
			}
		}
		int ans = dp[(1 << n)-1];
		printf("%d\n", ans);
	}
	return 0;
}