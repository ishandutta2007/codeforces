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
	int h, q;
	while(cin >> h >> q) {
		vector<pair<pair<ll,ll>,int> > queries(q);
		vector<ll> xs;
		xs.push_back(1LL << (h-1));
		xs.push_back(1LL << h);
		rep(i, q) {
			int y; long long L, R; int ans;
			scanf("%d%I64d%I64d%d", &y, &L, &R, &ans), -- y;
			rep(j, h - y - 1) {
				L = L * 2 + 0;
				R = R * 2 + 1;
			}
//			cerr << L << ", " <<R << endl;
			queries[i] = mp(mp(L, R + 1), ans);
			xs.push_back(L);
			xs.push_back(R + 1);
		}
		sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
		int X = xs.size();
		vi cnt(X, 0);
		rep(i, q) {
			int li = lower_bound(all(xs), queries[i].first.first) - xs.begin();
			int ri = lower_bound(all(xs), queries[i].first.second) - xs.begin();
			if(queries[i].second == 1)
				++ cnt[li], -- cnt[ri];
			else
				++ cnt[0], -- cnt[li], ++ cnt[ri], -- cnt[X - 1];
		}
		rep(i, X-1) cnt[i+1] += cnt[i];
		long long ans = -1;
		rep(i, X-1) if(cnt[i] == q) {
			if(ans != -1 || xs[i+1] - xs[i] > 1) {
				ans = -2;
				break;
			}else {
				ans = xs[i];
			}
		}
		if(ans == -1)
			puts("Game cheated!");
		else if(ans == -2)
			puts("Data not sufficient!");
		else
			cout << ans << endl;
	}
	return 0;
}