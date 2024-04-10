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

struct DynamicRMQ {
	typedef int Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, INF);
	}
	void update(int i, Val x) {
		d[n+i] = x;
		for(int k = (n+i)/2; k > 0; k >>= 1) 
			d[k] = min(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n+i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = INF;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = min(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = min(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};

int main() {
	int n, q;
	while(~scanf("%d%d", &n, &q)) {
		vector<pair<bool,int> > queries(q);
		rep(i, q) {
			char s[2];
			int x, y;
			scanf("%d%d%s", &x, &y, s), -- x, -- y;
			queries[i] = mp(*s == 'U', *s == 'U' ? y : x);
		}
		vi coords;
		coords.push_back(0);
		rep(i, q) {
			coords.push_back(queries[i].second);
			coords.push_back(n - 1 - queries[i].second);
		}
		sort(all(coords));
		coords.erase(unique(all(coords)), coords.end());
		int X = coords.size();
		DynamicRMQ rmqs[2];
		rep(k, 2)
			rmqs[k].init(X);
		set<int> s;
		rep(i, q) {
			bool k = queries[i].first;
			int yi = lower_bound(all(coords), queries[i].second) - coords.begin();
			int xi = lower_bound(all(coords), n - 1 - queries[i].second) - coords.begin();
			if(s.count(k ? yi : xi)) {
				puts("0");
				continue;
			}
			s.insert(k ? yi : xi);
			int l = -1, u = yi;
			while(u - l > 0) {
				int mid = (l + u + 1) / 2;
				int t = rmqs[!k].query(mid, yi);
				if(t <= coords[xi])
					l = mid;
				else
					u = mid-1;
			}

			int t = l == -1 ? -1 : coords[l];
			int ans = coords[yi] - t;
			printf("%d\n", ans);

			rmqs[k].update(xi, t + 1);
		}
	}
	return 0;
}