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


map<int,int>::iterator splitInterval(map<int,int> &intervals, int i) {
	map<int,int>::iterator it = -- intervals.upper_bound(i);
	if(it->first != i) {
		intervals.insert(mp(i, it->second));
		it->second = i;
		it = intervals.find(i);
	}
	return it;
}

int main() {
	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	map<int,int> intervals[2];
	priority_queue<pii> qs[2];
	rep(k, 2) {
		int t = k == 0 ? w : h;
		intervals[k][0] = t;
		intervals[k][t] = t;
		qs[k].push(mp(t, 0));
	}
	
	rep(i, n) {
		char ty[2]; int x;
		scanf("%s%d", ty, &x);
		int k = *ty == 'V' ? 0 : 1;
		{	map<int,int>::const_iterator it = splitInterval(intervals[k], x);
			qs[k].push(mp(it->second - it->first, it->first));
			if(it != intervals[k].begin()) {
				-- it;
				qs[k].push(mp(it->second - it->first, it->first));
			}
		}
		int maxs[2];
		rep(k, 2) {
			while(1) {
				pii p = qs[k].top();
				if(intervals[k].count(p.second) && intervals[k][p.second] == p.second + p.first) {
					maxs[k] = p.first;
					break;
				}
				qs[k].pop();
			}
		}
		ll ans = (ll)maxs[0] * maxs[1];
		printf("%I64d\n", ans);
	}
	return 0;
}