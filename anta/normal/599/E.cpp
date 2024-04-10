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


struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

struct Query {
	char a, b, c;
};

int main() {
	int n; int m; int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		vi edge(n, 0);
		UnionFind uf; uf.init(n);
		vector<pii> edges(m);
		rep(i, m) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			edge[u] |= 1 << v;
			edge[v] |= 1 << u;
			uf.unionSet(u, v);
			edges[i] = {u, v};
		}
		vi cc(n);
		rep(i, n)
			cc[i] = uf.root(i);
		vector<Query> queries;
		map<pii, int> qmap;
		bool trivialok = true;
		rep(i, q) {
			int a; int b; int c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b, -- c;
//			a = rand() % n, b = rand() % n, c = rand() % n;
			if(a > b) swap(a, b);
			if(a == b) {
				trivialok &= c == a;
			} else if(qmap.count({a, b})) {
				trivialok &= qmap[{a, b}] == c;
			} else {
				qmap[{a, b}] = c;
				queries.push_back(Query{a, b, c});
			}
		}
		if(!trivialok) {
			puts("0");
			continue;
		}
		vector<vector<ll> > dp(1 << n, vector<ll>(n));
		rep(subs, 1 << n) rep(root, n) if(subs >> root & 1) {
			ll x = 0;
			if(subs == 1 << root) {
				x = 1;
			}
			int firsti = -1;
			rep(i, n) if((subs >> i & 1) && i != root) {
				firsti = i;
				break;
			}
			rep(child, n) if((subs >> child & 1) && ((edge[root] >> child & 1) || cc[root] != cc[child])) {
				int rem = subs - (1 << root) - (1 << child);
				for(int si = rem; ; (-- si) &= rem) {
					int s = si | 1 << child;
					if(s >> firsti & 1) {
						bool ok = true;
						for(const pii &e : edges) {
							if(!(subs >> e.first & 1) || !(subs >> e.second & 1)) continue;
							ok &= (e.first == root && e.second == child) || (e.second == root && e.first == child) || ((s >> e.first & 1) == (s >> e.second & 1));
						}
						for(const Query &q : queries) {
							if(!(subs >> q.a & 1) || !(subs >> q.b & 1)) continue;
							if(((s >> q.a & 1) == (s >> q.b & 1))) continue;
							ok &= q.c == root;
						}
						if(ok)
							x += dp[s][child] * dp[subs - s][root];
					}
					if(si == 0) break;
				}
			}
//			if(x != 0) cerr << subs << ", " << root << " = " << x << endl;
			dp[subs][root] = x;
		}
		ll ans = dp[(1 << n)-1][0];
		cout << ans << endl;
	}
	return 0;
}