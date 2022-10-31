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

struct MinVal {
	int x, i;
	MinVal(): x(INF), i(-1) { }
	MinVal(int x_, int i_): x(x_), i(i_) { }
	MinVal &operator+=(const MinVal &that) {
		if(x > that.x)
			x = that.x, i = that.i;
		return *this;
	}
	bool operator<(const MinVal &that) const {
		return x != that.x ? x < that.x : i < that.i;
	}
};

struct FenwickTree {
	typedef MinVal T;
	vector<T> v;
	void init(int n) { v.assign(n, T()); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = T();
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
};

typedef MinVal V;
typedef int T;
void twoDimensionalSumQuery(vector<pair<pair<T,T>,V> > points, vector<pair<pair<T,T>,int> > queries, vector<V> &ans) {
	int n = points.size(), m = queries.size();
	vector<T> positions;
	rep(i, n) positions.pb(points[i].first.second);
	sort(all(positions));
	positions.erase(unique(all(positions)), positions.end());
	int p = positions.size();
	FenwickTree t; t.init(p);
	sort(all(points)); sort(all(queries));
	int left = 0;
	rep(i, m) {
		T x = queries[i].first.first;
		while(left < n && points[left].first.first < x) {
			int j = lower_bound(all(positions), points[left].first.second) - positions.begin();
			t.add(j, points[left].second);
			left ++;
		}
		int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
		ans[queries[i].second] += t.sum(y);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vi l(n), r(n);
	rep(i, n) scanf("%d%d", &l[i], &r[i]);
	vi a(m), b(m), c(m);
	rep(i, m) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	vector<pii> maxi(m, mp(-1,-1));
	vector<pair<pii,V> > points(n);
	vector<pair<pii,int> > queries(m);
	vector<V> results;
	//min(b_j,r_i) - max(a_j,l_i)

	//b_j <= r_i, a_j >= l_i: b_j - a_j
	rep(i, n) points[i] = mp(mp(-r[i], l[i]), V(0, i));
	rep(j, m) queries[j] = mp(mp(-b[j]+1, a[j]+1), j);
	results.assign(m, V());
	twoDimensionalSumQuery(points, queries, results);
	rep(j, m) if(results[j].x < INF) amax(maxi[j], mp(b[j] - a[j], results[j].i));

	//b_j <= r_i, a_j < l_i: b_j - l_i
	rep(i, n) points[i] = mp(mp(-r[i], -l[i]), V(l[i], i));
	rep(j, m) queries[j] = mp(mp(-b[j]+1, -a[j]), j);
	results.assign(m, V());
	twoDimensionalSumQuery(points, queries, results);
	rep(j, m) if(results[j].x < INF) amax(maxi[j], mp(b[j] - results[j].x, results[j].i));

	//b_j > r_i, a_j >= l_i: r_i - a_j
	rep(i, n) points[i] = mp(mp(r[i], l[i]), V(-r[i], i));
	rep(j, m) queries[j] = mp(mp(b[j], a[j]+1), j);
	results.assign(m, V());
	twoDimensionalSumQuery(points, queries, results);
	rep(j, m) if(results[j].x < INF) amax(maxi[j], mp(-results[j].x - a[j], results[j].i));

	//b_j > r_i, a_j < l_i: r_i - l_i
	rep(i, n) points[i] = mp(mp(r[i], -l[i]), V(-(r[i] - l[i]), i));
	rep(j, m) queries[j] = mp(mp(b[j], -a[j]), j);
	results.assign(m, V());
	twoDimensionalSumQuery(points, queries, results);
	rep(j, m) if(results[j].x < INF) amax(maxi[j], mp(-results[j].x, results[j].i));

	pair<ll,pii> ans(0, mp(-1,-1));
	rep(j, m) {
//		cerr << j << ": " << maxi[j].first << ", " << maxi[j].second << endl;
		if(maxi[j].second != -1)
			amax(ans, mp((ll)maxi[j].first * c[j], mp(maxi[j].second, j)));
	}
	if(ans.first <= 0) {
		puts("0");
	}else {
		cout << ans.first << endl;
		cout << ans.second.first+1 << " " << ans.second.second+1 << endl;
	}
	return 0;
}