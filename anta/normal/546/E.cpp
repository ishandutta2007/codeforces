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

struct MaximumFlow {
	typedef int Index;
	typedef int Flow;
	static const Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	//g
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for(Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if(u == t) d = level[u];
				each(e, g[u]) if(e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for(Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while(1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if(f == 0) break;
				total += f; update = true;
			}
		}while(update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if(u == t || f == 0) return f;
		Index lv = level[u];
		if(lv == -1) return 0;
		level[u] = -1;
		for(; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if(level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if(l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> a(n);
		rep(i, n) scanf("%d", &a[i]);
		vector<int> b(n);
		rep(i, n) scanf("%d", &b[i]);
		int src = n + n, dst = src + 1;
		MaximumFlow mf; mf.init(dst + 1);
		rep(i, n)
			mf.add(src, i, a[i]);
		rep(i, n)
			mf.add(i, n + i, INF);
		rep(i, m) {
			int p, q;
			scanf("%d%d", &p, &q), -- p, -- q;
			mf.add(p, n + q, INF);
			mf.add(q, n + p, INF);
		}
		rep(i, n)
			mf.add(n + i, dst, b[i]);
		vector<vector<MaximumFlow::Edge> > og = mf.g;
		int f = mf.maximumFlow(src, dst);
//		cerr << "f = " << f << endl;
		if(f != accumulate(all(a), 0) || f != accumulate(all(b), 0)) {
			puts("NO");
			continue;
		}
		vector<vi> ans(n, vi(n, 0));
		rep(i, n) rep(j, mf.g[i].size()) {
			int e = mf.g[i][j].to;
			if(!(n <= e && e < n + n)) continue;
			int c = og[i][j].capacity - mf.g[i][j].capacity;
			ans[i][e - n] = c;
		}
		puts("YES");
		rep(i, n) {
			rep(j, n) {
				if(j != 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}