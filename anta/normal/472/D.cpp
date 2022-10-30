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
	UnionFind(int size_) : data(size_, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

typedef int Weight;
struct Edge {
	int x, y;
	Weight w;
	Edge() { }
	Edge(int x_, int y_, Weight w_): x(x_), y(y_), w(w_) { }
};
bool operator<(const Edge &a, const Edge &b) { return a.w < b.w; }

vector<vi> g;
vector<long long> dist;
vector<vector<int> > d;

void dfs(int i, int p, long long t) {
	dist[i] = t;
	each(j, g[i]) if(*j != p)
		dfs(*j, i, t + d[i][*j]);
}

int main() {
	int n;
	scanf("%d", &n);
	d.assign(n, vector<int>(n));
	rep(i, n) rep(j, n) scanf("%d", &d[i][j]);
	bool ok = true;
	rep(i, n) rep(j, i) {
		ok &= d[i][j] == d[j][i];
		ok &= d[i][j] > 0;
	}
	rep(i, n)
		ok &= d[i][i] == 0;
	if(!ok) {
		puts("NO");
		return 0;
	}
	vector<Edge> edges; edges.reserve(n * (n-1) / 2);
	rep(i, n) rep(j, i) edges.push_back(Edge(i, j, d[i][j]));
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	g.assign(n, vi());
	for(int i = 0; i < (int)edges.size(); i ++) {
		int x = edges[i].x, y = edges[i].y;
		if(uf.unionSet(x, y)) {
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}
	dist.resize(n);
	rep(i, n) {
		dfs(i, -1, 0);
		rep(j, n)
			ok &= dist[j] == d[i][j];
	}
	puts(ok ? "YES" : "NO");
	return 0;
}