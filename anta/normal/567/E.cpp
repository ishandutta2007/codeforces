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

template<typename Weight_>
struct WeightedTo {
	typedef int Vertex; typedef Weight_ Weight;
	Vertex to; Weight w;
	WeightedTo() { }
	WeightedTo(Vertex to_, Weight w_): to(to_), w(w_) { }
	Weight getWeight() const { return w; }
};
template<typename To_>
struct StaticGraph {
	typedef To_ To;
	typedef typename To::Vertex Vertex;
	typedef std::pair<Vertex,To> Edge;
	typedef const To *const_iterator;
 
	void init(int n_, const std::vector<Edge> &edges) {
		n = n_; int m = edges.size();
		tos.resize(m+1); offsets.resize(n+1);
		for(int e = 0; e < m; e ++) offsets[edges[e].first] ++;
		for(int v = 1; v <= n_; v ++) offsets[v] += offsets[v-1];
		for(int e = 0; e < m; e ++)
			tos[-- offsets[edges[e].first]] = edges[e].second;
	}
	int numVertices() const { return n; }
	int numEdges() const { return tos.size() - 1; }
 
	inline const_iterator edgesBegin(int v) const { return &tos[offsets[v]]; }
	inline const_iterator edgesEnd(int v) const { return &tos[offsets[v+1]]; }
private:
	int n;
	std::vector<To> tos;
	std::vector<int> offsets;
};
typedef StaticGraph<WeightedTo<int> > Graph;

template<typename Value, typename Compare = std::less<Value>, typename Index = int>
class BinaryHeap {
	Compare cmp;
	vector<Value> a;
	vector<Index> idx, nodeidx;
	int pos;

public:
	BinaryHeap(Compare cmp_ = Compare()): cmp(cmp_) { }
	BinaryHeap(int n, Compare cmp_ = Compare()): cmp(cmp_) { init(n); }

	void init(int n) {
		a.resize(n+1);
		idx.assign(n+1, -1);
		nodeidx.assign(n+1, -1);
		pos = 1;
	}

	const Value &min() const { return a[1]; }
	const Value &get(Index i) const { return a[nodeidx[i]]; }
	Index argmin() const { return idx[1]; }
	Index size() const { return pos - 1; }
	bool empty() const { return pos == 1; }

	const Value &add(Index i, const Value &x) {
		Index node = nodeidx[i];
		if(node >= 0) return a[node];
		a[pos] = x;
		idx[pos] = i;
		nodeidx[i] = pos;
		++ pos;
		up(pos-1);
		return x;
	}

	const Value &update(Index i, const Value &x) {
		Index node = nodeidx[i];
		if(node < 0) {
			a[pos] = x;
			idx[pos] = i;
			nodeidx[i] = pos;
			++ pos;
			up(pos-1);
		}else {
			a[node] = x;
			up(node);
			down(node);
		}
		return x;
	}

	const Value &updatemin(Index i, const Value &x) {
		Index node = nodeidx[i];
		if(node >= 0 && !cmp(x, a[node])) return a[node];
		else return update(i, x);
	}

	const Value remove(Index i) {
		if(i < 0) return Value();
		Index node = nodeidx[i];
		if(node < 0) return Value();
		-- pos;
		idx[node] = idx[pos];
		nodeidx[idx[pos]] = node;
		nodeidx[i] = -1;
		idx[pos] = -1;
		swap(a[pos], a[node]);
		up(node);
		down(node);
		return a[pos];
	}

private:
	void up(Index i) {
		for(Index c = i, p = c >> 1; p > 0 && cmp(a[c], a[p]); c >>= 1, p >>= 1) {
			swap(a[p], a[c]);
			swap(nodeidx[idx[p]], nodeidx[idx[c]]);
			swap(idx[p], idx[c]);
		}
	}

	void down(Index i) {
		Index bottom = pos;
		for(Index c = i; c * 2 < bottom; ) {
			Index b = c * 2 + (c * 2 + 1 < bottom && cmp(a[c * 2 + 1], a[c * 2]));
			if(!cmp(a[b], a[c])) break;
			swap(a[c], a[b]);
			swap(nodeidx[idx[c]], nodeidx[idx[b]]);
			swap(idx[c], idx[b]);
			c = b;
		}
	}
};

template<typename Dist, typename Graph>
void dijkstra(const Graph &g, int s, vector<Dist> &dist) {
	int n = g.numVertices();
	dist.assign(n, numeric_limits<Dist>::max());
	vector<bool> vis(n);
	BinaryHeap<Dist> h(n);
	h.add(s, 0);
	while(!h.empty()) {
		int v = h.argmin(); Dist d = h.min();
		dist[v] = d;
		h.remove(v);
		vis[v] = true;
		for(typename Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
			if(!vis[it->to])
				h.updatemin(it->to, d + it->getWeight());
		}
	}
}

void transposeGraph(const Graph &g, Graph &h) {
	int n = g.numVertices();
	std::vector<Graph::Edge> edges;
	for(int v = 0; v < n; v ++)
		for(Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
			Graph::To t = *it; t.to = v;
			edges.push_back(Graph::Edge(it->to, t));
		}
	h.init(n, edges);
}


struct State {
	int i, parent, j; bool b;
	State() { }
	State(int i_, int parent_, int j_, bool b_): i(i_), parent(parent_), j(j_), b(b_) { }
};
void compute_lowlinks(const vector<vector<int> > &g, vector<int> &ord, vector<int> &low) {
	int n = g.size();
	ord.assign(n, -1); low.assign(n, -1);
	int order = 0;
	vector<State> stk;
	for(int ii = 0; ii < n; ii ++) if(ord[ii] == -1) {
		stk.push_back(State(ii, -1, 0, false));
		while(!stk.empty()) {
			State s = stk.back(); stk.pop_back();
			if(s.j == 0)
				low[s.i] = ord[s.i] = order ++;
			if(s.b)
				low[s.i] = min(low[s.i], low[g[s.i][s.j-1]]);
			if(g[s.i].size() == s.j)
				continue;
			int v = g[s.i][s.j];
			if(ord[v] == -1) {
				stk.push_back(State(s.i, s.parent, s.j+1, true));
				stk.push_back(State(v, s.i, 0, false));
			}else if(v != s.parent) {
				stk.push_back(State(s.i, s.parent, s.j+1, false));
				low[s.i] = min(low[s.i], ord[v]);
			}else {
				stk.push_back(State(s.i, s.parent, s.j+1, false));
			}
		}
	}
}

inline bool is_bridge_edge(int i, int j, const vector<int> &ord, const vector<int> &low) {
	return ord[i] < low[j] || ord[j] < low[i];
}

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

int main() {
	int n, m, s, t;
	while(~scanf("%d%d%d%d", &n, &m, &s, &t)) {
		-- s, -- t;
		vector<Graph::Edge> edges(m);
		rep(i, m) {
			int a, b, l;
			scanf("%d%d%d", &a, &b, &l), -- a, -- b;
			edges[i] = Graph::Edge(a, Graph::To(b, l));
		}
		Graph g, ig;
		g.init(n, edges);
		transposeGraph(g, ig);
		vector<long long> dist, idist;
		dijkstra(g, s, dist);
		dijkstra(ig, t, idist);
		ll shortest = dist[t];
		map<pii,int> dagedges;
		rep(i, m) {
			const Graph::Edge &e = edges[i];
			int a = e.first, b = e.second.to;
			int l = e.second.w;
			if(dist[a] < INFL && dist[b] < INFL && dist[a] + l + idist[b] == shortest)
				++ dagedges[minmax(a, b)];
		}
		vector<vi> dag(n);
		UnionFind uf; uf.init(n);
		each(i, dagedges) {
			if(i->second > 1)
				uf.unionSet(i->first.first, i->first.second);
			dag[i->first.first].push_back(i->first.second);
			dag[i->first.second].push_back(i->first.first);
		}
		vi ord, low;
		compute_lowlinks(dag, ord, low);
		rep(i, m) {
			const Graph::Edge &e = edges[i];
			int a = e.first, b = e.second.to;
			int l = e.second.w;
			if(dist[a] >= INFL || idist[b] >= INFL) {
				puts("NO");
				continue;
			}
			ll t = (dist[a] + l + idist[b]) - shortest + 1;
			if(t == 1 && dagedges.count(minmax(a, b)) && is_bridge_edge(a, b, ord, low) && !uf.findSet(a, b)) {
				puts("YES");
				continue;
			}
			if(t >= l) {
				puts("NO");
				continue;
			}
			printf("CAN %d\n", (int)t);
		}
	}
	return 0;
}