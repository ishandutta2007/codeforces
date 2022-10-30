#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct DynamicRMQ {
	typedef int Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, -INF);
	}
	void update(int i, Val x) {
		d[n+i] = x;
		for(int k = (n+i)/2; k > 0; k >>= 1) 
			d[k] = max(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n+i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = -INF;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = max(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = max(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};

struct Edge {
	int u, v, w, i;
	bool operator<(const Edge &that) const {
		if(u != that.u) return u < that.u;
		return w < that.w;
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<Edge> edges;
	vector<pii> edgews;
	rep(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), -- u, -- v, -- w;
		Edge e = { u, v, w, i };
		edges.push_back(e);
		edgews.push_back(mp(w, i));
	}
	sort(all(edges));
	sort(all(edgews)); reverse(all(edgews));

	vector<int> pos(m);
	rep(i, edges.size())
		pos[edges[i].i] = i;

	vector<vi> gw(n);
	rep(i, edges.size())
		gw[edges[i].u].push_back(edges[i].w);

	vector<int> off(n+1);
	rep(i, n) off[i+1] = off[i] + gw[i].size();

	DynamicRMQ rmq; rmq.init(m);
	int ans = 0;
	rep(wi, m) {
		int i = edgews[wi].second;
		const Edge &e = edges[pos[i]];
		//vw
		int t = upper_bound(all(gw[e.v]), e.w) - gw[e.v].begin();
		int x = rmq.query(off[e.v] + t, off[e.v+1]);
		int y = max(0, x) + 1;
		rmq.update(pos[i], y);
		amax(ans, y);
	}
	printf("%d\n", ans);
	return 0;
}