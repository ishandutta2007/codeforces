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

template<typename T>
typename map<int, pair<int, T> >::iterator splitInterval(map<int, pair<int, T> > &intervals, int i) {
	typename map<int, pair<int, T> >::iterator it = -- intervals.upper_bound(i);
	if(it->first != i) {
		intervals.insert(mp(i, it->second));
		it->second.first = i;
		it = intervals.find(i);
	}
	return it;
}

int main() {
	int n; int m; int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		char *s = new char[n+1];
		scanf("%s", s);
		vi cnt(k * k, 0);
		rep(i, n - 1) {
			int t = (s[i] - 'a') * k + (s[i + 1] - 'a');
			++ cnt[t];
		}
		map<int, pair<int, char> > intervals;
		rep(i, n)
			intervals[i] = mp(i + 1, s[i]);
		intervals[n] = mp(n, -1);
		for(int ii = 0; ii < m; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int l, r; char c[2];
				scanf("%d%d%s", &l, &r, c), -- l;
				auto it = splitInterval(intervals, l), jt = splitInterval(intervals, r - 1);
				if(0 < l) {
					char p = splitInterval(intervals, l - 1)->second.second;
					char q = it->second.second;
					-- cnt[(p - 'a') * k + (q - 'a')];
					++ cnt[(p - 'a') * k + (*c - 'a')];
				}
				for(auto kt = it; kt != jt; ++ kt) {
					int len = kt->second.first - kt->first;
					char p = kt->second.second;
					if(1 < len) {
						cnt[(p - 'a') * k + (p - 'a')] -= len - 1;
						cnt[(*c - 'a') * k + (*c - 'a')] += len - 1;
					}
					char q = (++ kt)->second.second; -- kt;
					-- cnt[(p - 'a') * k + (q - 'a')];
					++ cnt[(*c - 'a') * k + (*c - 'a')];
				}
				if(r < n) {
					char p = jt->second.second;
					char q = splitInterval(intervals, r)->second.second;
					-- cnt[(p - 'a') * k + (q - 'a')];
					++ cnt[(*c - 'a') * k + (q - 'a')];
				}
				intervals.erase(it, jt);
				intervals.erase(jt);
				intervals[l] = mp(r, *c);
			} else if(ty == 2) {
				char p[11];
				scanf("%s", p);
				int ans = 1;
				rep(i, k) rep(j, i + 1)
					ans += cnt[(p[i] - 'a') * k + (p[j] - 'a')];
				printf("%d\n", ans);
			} else abort();
		}


		delete[] s;
	}
	return 0;
}