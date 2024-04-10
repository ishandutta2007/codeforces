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
		vi l(n), d(n);
		rep(i, n) scanf("%d", &l[i]);
		rep(i, n) scanf("%d", &d[i]);
		int L = *max_element(all(l));
		vector<vi> v(L+1);
		rep(i, n) v[l[i]].push_back(d[i]);
		rer(l, 1, L) sort(all(v[l]));
		int D = *max_element(all(d));
		int cnt = 0;
		vector<int> dcnt(D+1, 0);
		int ans = INF;
		int remcost = accumulate(all(d), 0);
		rer(l, 1, L) {
			int c = v[l].size();
			//(cnt + c - t) / 2 < c
			//cnt - c < t
			int t = max(0, cnt - c + 1);
			int cost = 0;
			rer(d, 1, D) {
				int a = min(dcnt[d], t);
				cost += a * d;
				t -= a;
			}
			each(i, v[l]) {
				remcost -= *i;
				++ dcnt[*i];
			}
			cost += remcost;
			if(t == 0) {
//				cerr << l << ": " << cost << endl;
				amin(ans, cost);
			}
			cnt += c;
		}
		printf("%d\n", ans);
	}
	return 0;
}