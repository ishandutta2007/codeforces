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

struct TopK {
	static const int K = 10;
	int v[K];
	int n;
	TopK() : n(0) {}
	TopK(int x) : n(1) { v[0] = x; }
	TopK &operator+=(const TopK &that) {
		int tmp[K * 2];
		merge(v, v + n, that.v, that.v + that.n, tmp);
		n = min(K, n + that.n);
		rep(i, n) v[i] = tmp[i];
		return *this;
	}
};

struct PathCompressionTree {
	typedef TopK Sum;
private:
	vector<int> parent;
	vector<Sum> val, sum;
public:
	void init(int n, const vector<Sum> &initval) {
		parent.assign(n, -1);
		val = initval;
		sum.assign(n, Sum());
	}
	void link(int c, int p) {
		assert(parent[c] == -1 && p != -1);
		parent[c] = p;
		sum[c] = val[c];
	}
	int find(int u) {
		int p = parent[u], g;
		if(p == -1) return u;
		g = parent[u] = find(p);
		sum[u] += sum[p];
		return g;
	}
	Sum get(int u) {
		find(u);
		return sum[u];
	}
};

struct Query {
	int u, v, a, i;
};

vector<vi> g;
vector<bool> visited;
PathCompressionTree pct;
vector<vector<Query> > queries;
vector<vector<Query> > lca;
vector<TopK> vals, ans;

void dfs(int i, int p) {
	for(int j : g[i]) if(j != p)
		dfs(j, i);
	visited[i] = true;
	for(const Query &q : queries[i]) {
		if(visited[q.v])
			lca[pct.find(q.v)].push_back(q);
	}
	for(const Query &q : lca[i]) {
		ans[q.i] = vals[i];
		ans[q.i] += pct.get(q.u);
		ans[q.i] += pct.get(q.v);
		amin(ans[q.i].n, q.a);
	}
	if(p != -1)
		pct.link(i, p);
}

int main() {
	int n; int m; int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		g.assign(n, vi());
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vals.assign(n, TopK());
		for(int i = 0; i < m; ++ i) {
			int c;
			scanf("%d", &c), -- c;
			vals[c] += TopK(i);
		}
		pct.init(n, vals);
		queries.assign(n, vector<Query>());
		rep(i, q) {
			int u, v, a;
			scanf("%d%d%d", &u, &v, &a), -- u, -- v;
			queries[u].push_back({u, v, a, i});
			if(u != v) queries[v].push_back({v, u, a, i});
		}
		visited.assign(n, false);
		ans.assign(q, TopK());
		lca.assign(n, vector<Query>());
		dfs(0, -1);
		rep(i, q) {
			const TopK &x = ans[i];
			printf("%d", x.n);
			for(int i = 0; i < x.n; ++ i) {
				printf(" %d", x.v[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}