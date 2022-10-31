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

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		map<int, vpii> a[2];
		vi xs;
		rep(i, n) {
			int x1; int y1; int x2; int y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if(y1 == y2) {
				if(x1 > x2)swap(x1, x2);
				a[0][y1].emplace_back(x1, +1);
				a[0][y1].emplace_back(x2 + 1, -1);
				xs.push_back(x1);
				xs.push_back(x2 + 1);
			} else {
				assert(x1 == x2);
				if(y1 > y2)swap(y1, y2);
				a[1][x1].emplace_back(y1, +1);
				a[1][x1].emplace_back(y2 + 1, -1);
				xs.push_back(x1);
			}
		}
		vector<pair<int, pii> >  b;
		ll ans = 0;
		rep(k, 2) {
			each(it, a[k]) {
				vpii &v = it->second;
				sort(all(v));
				int left = -INF;
				int d = 0;
				each(jt, v) {
					if(jt->second == +1) {
						if(d ++ == 0)
							left = jt->first;
					} else {
						if(-- d == 0) {
							if(k == 1) {
								b.emplace_back(left, mp(it->first, +1));
								b.emplace_back(jt->first, mp(it->first, -1));
							}
							ans += jt->first - left;
							left = -INF;
						}
					}
				}
				assert(d == 0);
			}
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		sort(all(b));
		FenwickTree ft;
		ft.init(xs.size());
		int bi = 0;
		each(it, a[0]) {
			for(; bi != b.size() && b[bi].first <= it->first; ++ bi) {
				int xi = lower_bound(xs.begin(), xs.end(), b[bi].second.first) - xs.begin();
				ft.add(xi, b[bi].second.second);
			}
			vpii &v = it->second;
			int left = -INF;
			int d = 0;
			each(jt, v) {
				if(jt->second == +1) {
					if(d ++ == 0)
						left = jt->first;
				} else {
					if(-- d == 0) {
						int Li = lower_bound(xs.begin(), xs.end(), left) - xs.begin();
						int Ri = lower_bound(xs.begin(), xs.end(), jt->first) - xs.begin();
						ans -= ft.sum(Li, Ri);
						left = -INF;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}