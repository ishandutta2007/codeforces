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
	int d; int n; int m;
	while(~scanf("%d%d%d", &d, &n, &m)) {
		vector<pii> v(m);
		rep(i, m) {
			int x; int p;
			scanf("%d%d", &x, &p);
			v[i] = mp(x, p);
		}
		sort(all(v));
		v.insert(v.begin(), mp(0, 0));
		v.push_back(mp(d, 0));
		ll ans = 0;
		priority_queue<pii> q;
		int last = 0;
		rep(i, (int)v.size() - 1) {
			q.push(mp(-v[i].second, v[i].first));
			int x = v[i + 1].first;
			while(x > last) {
				if(q.empty())
					goto no;
				pii p = q.top(); q.pop();
				if(p.second > last - n) {
					int plus = min(x - last, p.second - (last - n));
					ans += (ll)plus * -p.first;
					q.push(p);
					last += plus;
				}
			}
		}
	no:;
		if(last < d)
			puts("-1");
		else
			printf("%lld\n", ans);
	}
	return 0;
}