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

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

void twoDimensionalSumQuery(vector<pair<int,int> > points, vector<pair<pair<int,int>,pair<int,int> > > queries, vector<int> &ans) {
	int n = points.size(), m = queries.size();
	vector<int> positions;
	rep(i, n) positions.pb(points[i].second);
	sort(all(positions));
	positions.erase(unique(all(positions)), positions.end());
	int p = positions.size();
	FenwickTree t; t.init(p);
	sort(all(points)); sort(all(queries));
	int left = 0;
	rep(i, m) {
		int x = queries[i].first.first;
		while(left < n && points[left].first < x) {
			int j = lower_bound(all(positions), points[left].second) - positions.begin();
			t.add(j, 1);
			left ++;
		}
		int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
		ans[queries[i].second.second] += t.sum(y) * queries[i].second.first;
	}
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &p[i]);
		vector<int> pos(n+1, -1);
		rep(i, n)
			pos[p[i]] = i;
		vpii points;
		rer(i, 1, n) for(int j = i; j <= n; j += i) {
			int a = pos[i], b = pos[j];
			if(a > b) swap(a, b);
			points.push_back(make_pair(n - 1 - a, b));
		}
		vector<pair<pii,pii> > queries(m);
		rep(i, m) {
			int l, r;
			scanf("%d%d", &l, &r), -- l;
			queries[i] = mp(mp(n - l, r), mp(1, i));
		}
		vi ans(m, 0);
		twoDimensionalSumQuery(points, queries, ans);
		rep(i, m)
			printf("%d\n", ans[i]);
	}
	return 0;
}