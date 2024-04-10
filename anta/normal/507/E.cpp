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
void dijkstra(const Graph &g, int s, vector<Dist> &dist, vector<int> &parent) {
	int n = g.numVertices();
	dist.assign(n, numeric_limits<Dist>::max());
	parent.assign(n, -1);
	vector<bool> vis(n);
	BinaryHeap<Dist> h(n);
	h.add(s, 0);
	while(!h.empty()) {
		int v = h.argmin(); Dist d = h.min();
		dist[v] = d;
		h.remove(v);
		vis[v] = true;
		for(typename Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
			if(!vis[it->to]) {
				Dist e = d + it->getWeight();
				if(h.updatemin(it->to, e) == e)
					parent[it->to] = v;
			}
		}
	}
}

int main() {
	typedef StaticGraph<WeightedTo<int> > Graph;
	int n, m;
	scanf("%d%d", &n, &m);
	int Base = 1000000;
	vector<Graph::Edge> edges;
	map<pii,int> edgemap;
	rep(i, m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z), -- x, -- y;
		if(x > y) swap(x, y);
		edgemap[mp(x, y)] = z;
		int cost = z == 0 ? Base + 1 : Base - 1;
		edges.push_back(Graph::Edge(x, Graph::To(y, cost)));
		edges.push_back(Graph::Edge(y, Graph::To(x, cost)));
	}
	Graph g; g.init(n, edges);
	vector<long long> dist;
	vector<int> parent;
	dijkstra(g, 0, dist, parent);
	for(int t = n-1; t != 0; ) {
		int p = parent[t];
		int x = p, y = t;
		if(x > y) swap(x, y);
		edgemap[mp(x, y)] |= 2;
		t = p;
	}
	vector<pair<pii,int> > ans;
	each(i, edgemap) if((i->second & 1) != (i->second >> 1))
		ans.push_back(mp(i->first, i->second >> 1));
	printf("%d\n", (int)ans.size());
	each(i, ans)
		printf("%d %d %d\n", i->first.first + 1, i->first.second + 1, i->second);
	return 0;
}