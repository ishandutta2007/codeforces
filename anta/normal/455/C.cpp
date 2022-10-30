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

pii fartest_dfs(const vector<vi> &g, int i, int p) {
	pii r = mp(1, i);
	each(j, g[i]) if(*j != p) {
		pii q = fartest_dfs(g, *j, i);
		amax(r, mp(q.first + 1, q.second));
	}
	return r;
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<vi> g(n);
	UnionFind uf; uf.init(n);
	rep(i, m) {
		int a, b;
		scanf("%d%d", &a, &b), -- a, -- b;
		g[a].pb(b);
		g[b].pb(a);
		uf.unionSet(a, b);
	}
	vector<int> diam(n);
	rep(i, n) if(uf.root(i) == i) {
		pii p = fartest_dfs(g, i, -1);
		pii q = fartest_dfs(g, p.second, -1);
		diam[i] = q.first;
	}
	rep(ii, q) {
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int x;
			scanf("%d", &x), -- x;
			int ans = diam[uf.root(x)] - 1;
			printf("%d\n", ans);
		}else {
			int x, y;
			scanf("%d%d", &x, &y), -- x, -- y;
			if(!uf.findSet(x, y)) {
				int ndiam = 0;
				ndiam += diam[uf.root(x)] / 2 + 1;
				ndiam += diam[uf.root(y)] / 2 + 1;
				amax(ndiam, diam[uf.root(x)]);
				amax(ndiam, diam[uf.root(y)]);
//				cerr << x+1 << ", " << y+1 << ": " << diam[uf.root(x)] << ", " << diam[uf.root(y)] << " -> " << ndiam << endl;
				uf.unionSet(x, y);
				diam[uf.root(x)] = ndiam;
			}
		}
	}
	return 0;
}