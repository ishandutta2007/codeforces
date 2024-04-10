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
#include <bitset>
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
		d.assign(n * 2, INF);
	}
	void update(int i, Val x) {
		d[n+i] = x;
		for(int k = (n+i)/2; k > 0; k >>= 1) 
			d[k] = min(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n+i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = INF;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = min(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = min(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};


vector<vpii> g;
vector<vi> packets;
vector<vpii> queries;
vector<bool> ans;
vector<vi> v;
vector<int> depth;
DynamicRMQ rmq;

void dfs(int i, int d) {
	each(j, queries[i]) {
		v[j->first].push_back(j->second);
		depth[j->second] = d;
	}
	each(j, packets[i]) each(k, v[*j]) {
		ans[*k] = -rmq.query(depth[*k], d) <= *j;
	}
	each(j, g[i]) {
		rmq.update(d, -j->second);
		dfs(j->first, d+1);
	}
	each(j, queries[i])
		v[j->first].pop_back();
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	g.assign(n, vpii());
	packets.assign(n, vi());
	queries.assign(n, vpii());
	vector<bool> root(n, true);
	int p = 0, q = 0;
	rep(ii, m) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int x, y;
			scanf("%d%d", &x, &y), -- x, -- y;
			g[y].push_back(mp(x, p));
			root[x] = false;
		}else if(t == 2) {
			int x;
			scanf("%d", &x), -- x;
			packets[x].push_back(p);
			++ p;
		}else if(t == 3) {
			int x, i;
			scanf("%d%d", &x, &i), -- x, -- i;
			queries[x].push_back(mp(i, q));
			++ q;
		}
	}
	ans.assign(q, false);
	v.assign(p, vi());
	depth.assign(q, -1);
	rmq.init(n);
	rep(i, n) if(root[i]) dfs(i, 0);
	rep(i, q) puts(ans[i] ? "YES" : "NO");
	return 0;
}