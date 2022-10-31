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
#include <unordered_map>
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

ll pack(int c, int v) { return (ll)c << 20 | v; }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	const int C = m;
	vector<int> degrees(n, 0);
	vector<vi> incidentColors(n, vi());
	vector<vi> vertices(C);
	unordered_map<ll,int> vimap;
	vector<vpii> edges(C);
	const int S = 300;
	rep(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), -- a, -- b, -- c;
		vertices[c].push_back(a);
		vertices[c].push_back(b);
		edges[c].push_back(mp(a, b));
		++ degrees[a];
		++ degrees[b];
		incidentColors[a].push_back(c);
		incidentColors[b].push_back(c);
	}
	rep(i, n) {
		vi &v = incidentColors[i];
		sort(all(v));
		v.erase(unique(all(v)), v.end());
	}
	vector<UnionFind> ufs(C);
	vector<vector<vi> > components(C);
	rep(i, C) {
		vi &v = vertices[i];
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		int V = v.size();
		rep(j, V)
			vimap[pack(i, v[j])] = j;
		ufs[i].init(V);
		each(j, edges[i]) {
			int a = lower_bound(all(v), j->first) - v.begin();
			int b = lower_bound(all(v), j->second) - v.begin();
			ufs[i].unionSet(a, b);
		}
	}
	map<pii,int> memo;
	int q;
	scanf("%d", &q);
	rep(ii, q) {
		int u, v;
		scanf("%d%d", &u, &v), -- u, -- v;
		if(mp(degrees[u], u) < mp(degrees[v], v))
			swap(u, v);
		if(!memo.count(mp(u, v))) {
			int ans = 0;
			each(c, incidentColors[v]) {
				auto a = vimap.find(pack(*c, u));
				auto b = vimap.find(pack(*c, v));
				if(a != vimap.end() && b != vimap.end())
					ans += ufs[*c].findSet(a->second, b->second);
			}
			memo[mp(u, v)] = ans;
		}
		printf("%d\n", memo[mp(u, v)]);
	}
	return 0;
}