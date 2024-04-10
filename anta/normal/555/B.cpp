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
		vector<ll> l(n), r(n);
		rep(i, n)
			scanf("%I64d%I64d", &l[i], &r[i]);
		vector<ll> a(m);
		rep(i, m)
			scanf("%I64d", &a[i]);
		vector<pair<pair<ll,ll>,int> > intervals;
		rep(i, n-1) {
			ll L = l[i+1] - r[i];
			ll R = r[i+1] - l[i];
			intervals.push_back(mp(mp(L, R), i));
		}
		sort(all(intervals));
		vector<pair<ll,int> > points(m);
		rep(i, m)
			points[i] = mp(a[i], i);
		sort(all(points));
		vi ans(n-1, -1);
		priority_queue<pair<pair<ll,ll>,int> > q;
		for(int i = 0, j = 0; j < (int)points.size(); ) {
			if(i < (int)intervals.size() && intervals[i].first.first <= points[j].first) {
				q.push(mp(mp(-intervals[i].first.second, intervals[i].first.first), intervals[i].second));
				++ i;
			}else {
				ll x = points[j].first;
				while(!q.empty()) {
					ll R = -q.top().first.first;
					ll L = q.top().first.second;
					int k = q.top().second;
					q.pop();
					if(L <= x && x <= R) {
						ans[k] = points[j].second;
						break;
					}
				}
				++ j;
			}
		}
		if(count(all(ans), -1) == 0) {
			puts("Yes");
			rep(i, n-1) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");
		}else {
			puts("No");
		}
	}
	return 0;
}