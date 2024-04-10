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

struct DynamicRMQ {
	typedef ll Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, -INFL);
	}
	void update(int i, Val x) {
		d[n + i] = x;
		for(int k = (n + i) / 2; k > 0; k >>= 1)
			d[k] = max(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n + i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = -INFL;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = max(m, d[(n + l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = max(m, d[(n + r) / (r&-r) - 1]);
		return m;
	}
};
int main() {
	int n;
	while(~scanf("%d", &n)) {
		const double PI = acos(-1.);
		vector<ll> v(n);
		rep(i, n) {
			int r; int h;
			scanf("%d%d", &r, &h);
			//pi r^2 h
			v[i] = (ll)r * r * h;
		}
		vector<ll> values = v;
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		int X = (int)values.size();
		DynamicRMQ rmq; rmq.init(X);
		ll maxi = 0;
		rep(i, n) {
			int k = lower_bound(values.begin(), values.end(), v[i]) - values.begin();
			ll x = max(0LL, rmq.query(0, k)) + v[i];
			amax(maxi, x);
			rmq.update(k, max(rmq.get(k), x));
		}
		double ans = maxi * PI;
		printf("%.10f\n", ans);
	}
	return 0;
}