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
	int e; int s; int n; int m;
	while(~scanf("%d%d%d%d", &e, &s, &n, &m)) {
		vpii v(n);
		rep(i, n) {
			int t, p;
			scanf("%d%d", &t, &p), -- t;
			v[i] = mp(t, p);
		}
		vi queries(m);
		rep(i, m)
			scanf("%d", &queries[i]);
		vi poses;
		rep(i, n) {
			int p = v[i].second;
			poses.push_back(p);
			poses.push_back(p + s);
		}
		rep(i, m) {
			poses.push_back(queries[i]);
			poses.push_back(queries[i] + s);
		}
		poses.push_back(e);
		sort(poses.begin(), poses.end());
		poses.erase(unique(poses.begin(), poses.end()), poses.end());
		int P = poses.size();
		vector<vector<int> > cnts(3, vector<int>(P+1));
		rep(i, n) {
			int l = lower_bound(poses.begin(), poses.end(), v[i].second) - poses.begin();
			int r = lower_bound(poses.begin(), poses.end(), v[i].second + s) - poses.begin();
			rep(j, v[i].first + 1) {
				++ cnts[j][l];
				-- cnts[j][r];
			}
		}
		vector<vector<ll> > sums(3, vector<ll>(P+1));
		rep(i, 3) {
			rep(j, P)
				cnts[i][j + 1] += cnts[i][j];
			rep(j, P)
				sums[i][j + 1] = sums[i][j] + (j + 1 < P && cnts[i][j] > 0 ? poses[j + 1] - poses[j] : 0);
		}
		int goal = lower_bound(poses.begin(), poses.end(), e) - poses.begin();
		rep(i, m) {
			int a = lower_bound(poses.begin(), poses.end(), queries[i] + s) - poses.begin();
			ll ans1, ans2;
			if(goal <= a) {
				ans1 = ans2 = 0;
			} else {
				ll dist = (ll)poses[goal] - poses[a];
				ll x2 = sums[2][goal] - sums[2][a];
				ll x1 = sums[1][goal] - sums[1][a];
				ll x0 = sums[0][goal] - sums[0][a];
				if(x2 == dist) {
					ans1 = ans2 = 0;
				} else if(x1 == dist) {
					ans1 = 0;
					ans2 = dist - x2;
				} else if(x0 == dist) {
					ans1 = dist - x1;
					ans2 = (dist - x2) - ans1;
					assert(ans2 >= 0);
				} else {
					ans1 = ans2 = -1;
				}
			}
			printf("%I64d %I64d\n", ans1, ans2);
		}
	}
	return 0;
}