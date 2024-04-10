#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<typename Value, typename Compare = std::less<Value>, typename Index = int>
class BinaryHeap {
	Compare cmp;
	vector<Value> a;
	vector<Index> idx, nodeidx;
	int pos;

public:
	BinaryHeap(Compare cmp_ = Compare()) : cmp(cmp_) { }
	BinaryHeap(int n, Compare cmp_ = Compare()) : cmp(cmp_) { init(n); }

	void init(int n) {
		a.resize(n + 1);
		idx.assign(n + 1, -1);
		nodeidx.assign(n + 1, -1);
		pos = 1;
	}

	const Value &min() const { return a[1]; }
	const Value &get(Index i) const { return a[nodeidx[i]]; }
	Index argmin() const { return idx[1]; }
	Index size() const { return pos - 1; }
	bool empty() const { return pos == 1; }

	const Value &add(Index i, const Value &x) {
		Index node = nodeidx[i];
		if (node >= 0) return a[node];
		a[pos] = x;
		idx[pos] = i;
		nodeidx[i] = pos;
		++ pos;
		up(pos - 1);
		return x;
	}

	const Value &update(Index i, const Value &x) {
		Index node = nodeidx[i];
		if (node < 0) {
			a[pos] = x;
			idx[pos] = i;
			nodeidx[i] = pos;
			++ pos;
			up(pos - 1);
		} else {
			a[node] = x;
			up(node);
			down(node);
		}
		return x;
	}

	const Value &updatemin(Index i, const Value &x) {
		Index node = nodeidx[i];
		if (node >= 0 && !cmp(x, a[node])) return a[node];
		else return update(i, x);
	}

	Value remove(Index i) {
		if (i < 0) return Value();
		Index node = nodeidx[i];
		if (node < 0) return Value();
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
		for (Index c = i, p = c >> 1; p > 0 && cmp(a[c], a[p]); c >>= 1, p >>= 1) {
			swap(a[p], a[c]);
			swap(nodeidx[idx[p]], nodeidx[idx[c]]);
			swap(idx[p], idx[c]);
		}
	}

	void down(Index i) {
		Index bottom = pos;
		for (Index c = i; c * 2 < bottom; ) {
			Index b = c * 2 + (c * 2 + 1 < bottom && cmp(a[c * 2 + 1], a[c * 2]));
			if (!cmp(a[b], a[c])) break;
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
	while (!h.empty()) {
		int v = h.argmin(); Dist d = h.min();
		dist[v] = d;
		h.remove(v);
		vis[v] = true;
		for (typename Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
			if (!vis[it->to])
				h.updatemin(it->to, d + it->getWeight());
		}
	}
}

template<typename Weight_>
struct WeightedTo {
	typedef int Vertex; typedef Weight_ Weight;
	Vertex to; Weight w;
	WeightedTo() { }
	WeightedTo(Vertex to_, Weight w_) : to(to_), w(w_) { }
	Weight getWeight() const { return w; }
};
template<typename To_>
struct StaticGraph {
	typedef To_ To;
	typedef typename To::Vertex Vertex;
	typedef std::pair<Vertex, To> Edge;
	typedef const To *const_iterator;

	void init(int n_, const std::vector<Edge> &edges) {
		n = n_; int m = edges.size();
		tos.resize(m + 1); offsets.assign(n + 1, 0);
		for (int e = 0; e < m; e ++) offsets[edges[e].first] ++;
		for (int v = 1; v <= n_; v ++) offsets[v] += offsets[v - 1];
		for (int e = 0; e < m; e ++)
			tos[-- offsets[edges[e].first]] = edges[e].second;
	}
	int numVertices() const { return n; }
	int numEdges() const { return tos.size() - 1; }

	inline const_iterator edgesBegin(int v) const { return &tos[offsets[v]]; }
	inline const_iterator edgesEnd(int v) const { return &tos[offsets[v + 1]]; }
private:
	int n;
	std::vector<To> tos;
	std::vector<int> offsets;
};

int main() {
	using To = WeightedTo<int>;
	using Graph = StaticGraph<To>;
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		int s;
		scanf("%d", &s), -- s;
		int nNodes = 1;
		while (nNodes < n) nNodes *= 2;
		vector<Graph::Edge> edges;
		reu(i, 1, nNodes) {
			int A = nNodes * 2, B = 0;
			edges.emplace_back(A + i, To(A + i * 2 + 0, 0));
			edges.emplace_back(A + i, To(A + i * 2 + 1, 0));
			edges.emplace_back(B + i * 2 + 0, To(B + i, 0));
			edges.emplace_back(B + i * 2 + 1, To(B + i, 0));
		}
		rep(i, n) {
			edges.emplace_back(nNodes + i, To(nNodes * 3 + i, 0));
			edges.emplace_back(nNodes * 3 + i, To(nNodes + i, 0));
		}
		rep(i, q) {
			int ty;
			scanf("%d", &ty);
			int sL, sR, tL, tR;
			if (ty == 3) {
				int u;
				scanf("%d", &u), -- u;
				int l; int r;
				scanf("%d%d", &l, &r), -- l, -- r;
				sL = l, sR = r;
				tL = tR = u;
			} else {
				int u;
				scanf("%d", &u), -- u;
				sL = sR = u;
				if (ty != 2) {
					int u;
					scanf("%d", &u), -- u;
					tL = tR = u;
				} else {
					int l; int r;
					scanf("%d%d", &l, &r), -- l, -- r;
					tL = l, tR = r;
				}
			}
			int w;
			scanf("%d", &w);
			int qu = nNodes * 4 + i;
			for (int l = sL + nNodes, r = sR + 1 + nNodes; l < r; l >>= 1, r >>= 1) {
				if (l & 1) edges.emplace_back(l ++, To(qu, w));
				if (r & 1) edges.emplace_back(-- r, To(qu, w));
			}
			for (int l = tL + nNodes, r = tR + 1 + nNodes; l < r; l >>= 1, r >>= 1) {
				if (l & 1) edges.emplace_back(qu, To(nNodes * 2 + l ++, 0));
				if (r & 1) edges.emplace_back(qu, To(nNodes * 2 + -- r, 0));
			}
		}
		Graph g;
		g.init(nNodes * 4 + q, edges);
		vector<ll> dist;
		dijkstra(g, nNodes + s, dist);
		for (int i = 0; i < n; ++ i) {
			if (i != 0) putchar(' ');
			ll d = dist[nNodes + i];
			printf("%lld", d == numeric_limits<ll>::max() ? -1 : d);
		}
		puts("");
	}
	return 0;
}