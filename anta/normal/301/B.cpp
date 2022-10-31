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
	typedef int Weight;
	typedef long long Dist;
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
const WeightedStaticGraph::Dist WeightedStaticGraph::InfDist = INFL;
typedef WeightedStaticGraph Graph;

int main() {
	int n; int d;
	while(~scanf("%d%d", &n, &d)) {
		vector<int> a(n - 2);
		for(int i = 0; i < n - 2; ++ i)
			scanf("%d", &a[i]);
		vector<int> x(n);
		vector<int> y(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &x[i], &y[i]);
		int H = 100, W = 100;
		int HH = H * 2 + 1, WW = W * 2 + 1;
		vector<vi> add(HH, vi(WW, 0));
		rep(i, n - 2)
			add[H + y[i + 1]][W + x[i + 1]] += a[i];
		vector<Graph::Edge> edges;
		rer(y, -H, H) rer(x, -W, W) {
			static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
			rep(dir, 4) {
				int yy = y + dy[dir], xx = x + dx[dir];
				if(yy < -H || yy > H || xx < -W || xx > W) continue;
				edges.push_back(Graph::Edge((H + y) * WW + (W + x), Graph::To((H + yy) * WW + (W + xx), add[H + yy][W + xx] - d)));
			}
		}
		Graph g; g.init(HH * WW, edges);
		int src = (H + y[0]) * WW + (W + x[0]);
		int dst = (H + y[n - 1]) * WW + (W + x[n - 1]);
		long long l = 0, u = (ll)HH * WW * d;
		while(u - l > 0) {
			long long mid = (l + u) / 2;
//			cerr << "mid = " << mid << endl;
			queue<Graph::Vertex> q;
			vector<bool> onqueue(g.numVertices());
			vector<long long> dist(g.numVertices(), -1);
			dist[src] = mid;
			q.push(src);
			onqueue[src] = true;
			while(!q.empty()) {
				Graph::Vertex v = q.front();
				if(v == dst) break;
				q.pop();
				onqueue[v] = false;
				for(Graph::const_iterator it = g.edgesBegin(v), et = g.edgesEnd(v); it != et; ++ it) {
					Graph::Dist t = dist[v] + it->w;
					Graph::Vertex u = it->to;
					if(t >= 0 && t > dist[u]) {
						if(!onqueue[u]) {
							onqueue[u] = true;
							q.push(u);
						}
						dist[u] = t;
					}
				}
			}
			if(dist[dst] >= 0)
				u = mid;
			else
				l = mid + 1;
		}
		cout << u << endl;
	}
	return 0;
}