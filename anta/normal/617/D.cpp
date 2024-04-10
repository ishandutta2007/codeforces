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
	const int K = 3;
	int x[K], y[K];
	while(cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]) {
		int ans = 3;
		rep(rot, 2) {
			vi v(x, x + K);
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			if(v.size() != 2) {
				amin(ans, (int)v.size());
			} else {
				vpii w;
				rep(i, K)
					w.push_back(mp(x[i], y[i]));
				sort(all(w));
				do {
					bool ok = true, ok2 = false;
					rep(i, K - 1) {
						ok &= w[i].second <= w[i + 1].second;
						ok2 |= w[i].first == w[i + 1].first;
					}
					if(ok && ok2)
						amin(ans, 2);
				} while(next_permutation(all(w)));
			}
			rep(i, K)
				swap(x[i], y[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}