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

struct WeightedStaticGraph {
	typedef int Vertex;
	typedef int Weight; typedef int Dist;
	static const Dist InfDist;
	struct To {
		Vertex to; Weight w;
		To() { }
		To(Vertex to_, Weight w_): to(to_), w(w_) { }
	};
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
 
	inline const_iterator edgesBegin(int v) const { return &tos[offsets[v]]; }
	inline const_iterator edgesEnd(int v) const { return &tos[offsets[v+1]]; }
private:
	int n;
	std::vector<To> tos;
	std::vector<int> offsets;
};
const WeightedStaticGraph::Dist WeightedStaticGraph::InfDist = INF;
typedef WeightedStaticGraph Graph;

bool topologicalSort(int n, Graph::Vertex f[], Graph::Vertex ord[]) {
	vector<int> deg(n);
	for(int i = 0; i < n; i ++) if(f[i] != -1) deg[f[i]] ++;
	int q = 0;
	for(int i = 0; i < n; i ++) if(deg[i] == 0) ord[q ++] = i;
	for(int p = 0; p < q; p ++) {
		Graph::Vertex to = f[ord[p]];
		if(to != -1)
			if((-- deg[to]) == 0) ord[q ++] = to;
	}
	for(int i = 0; i < n; i ++) if(deg[i] > 0) return false;
	return true;
}
 
bool queueBasedBellmanFord(const Graph &g, int s, Graph::Dist dist[], Graph::Vertex prev[]) {
	int n = g.numVertices();
	queue<Graph::Vertex> q; vector<bool> onqueue(n);
	fill(dist, dist+n, Graph::InfDist);
	fill(prev, prev+n, -1);
	vector<Graph::Vertex> tmp_ord(n);
	int relaxes = 0;
	dist[s] = 0; q.push(s); onqueue[s] = true;
	while(!q.empty()) {
		Graph::Vertex v = q.front(); q.pop(); onqueue[v] = false;
		relaxes ++;
		for(Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
			relaxes ++;
			Graph::Dist d = dist[v] + it->w; Graph::Vertex u = it->to;
			if(d < dist[u]) {
				if(!onqueue[u]) {
					onqueue[u] = true;
					q.push(u);
				}
				dist[u] = d;
				prev[u] = v;
				if(relaxes >= n) {	//n
					relaxes = 0;
					if(!topologicalSort(n, prev, &tmp_ord[0]))
						return false;
				}
			}
		}
	}
	return true;
}

int main() {
	typedef Graph::Edge Edge;
	typedef Graph::To To;
	int m, t, r;
	scanf("%d%d%d", &m, &t, &r);
	vector<int> w(m);
	rep(i, m) scanf("%d", &w[i]);
	vector<Graph::Edge> edges;
	int T = 300;
	int V = T * 2 + 3;
	rep(i, V-1) {
		//x_{i+1} - x_i <= 1
		//-x_{i+1} - 1 >= -x_i
		edges.push_back(Edge(i+1, To(i, 1)));
		edges.push_back(Edge(i, To(i+1, 0)));
	}
	rep(i, m) {
		//x_{w-t} - x_{w+1} >= r
		//x_{w-t} - r >= x_{w+1}
		edges.push_back(Edge(T + w[i] - t + 1, To(T + w[i] + 1, -r)));
	}
	Graph g; g.init(V, edges);
	vector<int> dist(V);
	vector<int> prev(V);
	bool ok = queueBasedBellmanFord(g, 0, &dist[0], &prev[0]);
	int candles = -dist[V-1];
	if(!ok)
		puts("-1");
	else
		printf("%d\n", candles);
	return 0;
}