#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


template<typename Weight_>
struct WeightedTo {
	typedef int Vertex; typedef Weight_ Weight;
	Vertex to; Weight w;
	WeightedTo() {}
	WeightedTo(Vertex to_, Weight w_) : to(to_), w(w_) {}
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
		for(int e = 0; e < m; e ++) offsets[edges[e].first] ++;
		for(int v = 1; v <= n_; v ++) offsets[v] += offsets[v - 1];
		for(int e = 0; e < m; e ++)
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

struct EdgeSum {
	int totalLength;
	int minWeight;
	int minIndex;

	EdgeSum() : totalLength(0), minWeight(INF), minIndex(-1) {}
	explicit EdgeSum(int w, int i) : totalLength(w), minWeight(w), minIndex(i) {}
	EdgeSum &operator+=(const EdgeSum &that) {
		assert(!isDiconnected() && !that.isDiconnected());
		totalLength += that.totalLength;
		if(minWeight > that.minWeight) {
			minWeight = that.minWeight;
			minIndex = that.minIndex;
		}
		return *this;
	}

	static EdgeSum Disconnected() {
		return EdgeSum(INF, -2);
	}
	bool isDiconnected() const { return minIndex == -2; }
};

typedef StaticGraph<WeightedTo<EdgeSum> > Graph;

class TwoEdgeConnectivity {
	int N, N2, numCCs;
	vector<Graph::Edge> edges;
	Graph graph;
	vector<int> iord, ord, parent, num;
	vector<EdgeSum> edgeSum;
	vector<int> teccIndex;
	vector<int> root2, parent2, ccIndex2;
	vector<EdgeSum> edgeSum2;

public:
	struct WeightedEdge {
		pair<int, int> edge;
		EdgeSum sum;
	};

	void init(int N_) {
		N = N_;
		edges.clear();
	}

	void addEdge(const WeightedEdge &e) {
		int a, b;
		tie(a, b) = e.edge;
		EdgeSum w = e.sum;
		edges.push_back(Graph::Edge(a, Graph::To(b, w)));
		edges.push_back(Graph::Edge(b, Graph::To(a, w)));
	}

	void build() {
		graph.init(N, edges);
		ord.clear();
		iord.assign(N, -1);
		parent.assign(N, -2);
		edgeSum.assign(N, EdgeSum());
		num.assign(N, 0);
		rep(root, N) if(parent[root] == -2)
			dfs(root, -1);
		for(int ix = N - 1; ix >= 0; -- ix) {
			int i = ord[ix], p = parent[i];
			if(p == -1) continue;
			num[p] += num[i];
		}

		teccIndex.assign(N, -1);
		N2 = 0;
		root2.clear();
		for(int ix = 0; ix < N; ++ ix) {
			int i = ord[ix], p = parent[i];
			if(num[i] == 0) {
				root2.push_back(i);
				teccIndex[i] = N2 ++;
			} else {
				assert(p != -1);
				teccIndex[i] = teccIndex[p];
			}
		}
		parent2.assign(N2, -2);
		edgeSum2.assign(N2, EdgeSum());
		for(int i = N2 - 1; i >= 0; -- i) {
			int p1 = parent[root2[i]];
			int p2 = p1 == -1 ? -1 : teccIndex[p1];
			parent2[i] = p2;
			edgeSum2[i] = edgeSum[root2[i]];
		}
		numCCs = 0;
		ccIndex2.assign(N2, -2);
		rep(i, N2) {
			int p = parent2[i];
			ccIndex2[i] = p == -1 ? numCCs ++ : ccIndex2[p];
		}
	}

	int compressTree(vector<int> &vertexMap, vector<WeightedEdge> &res) const {
		int previ = -1;
		rep(i, N2) if(vertexMap[i] == 0) {
			if(previ != -1 && ccIndex2[previ] == ccIndex2[i]) {
				int lca = i;
				while(previ < lca)
					lca = parent2[lca];
				assert(lca >= 0);
				vertexMap[lca] = 0;
			}
			previ = i;
		}

		int newN = 0;
		rep(i, N2) if(vertexMap[i] == 0)
			vertexMap[i] = newN ++;

		res.clear();
		rep(i, N2) if(vertexMap[i] != -1) {
			EdgeSum sum = EdgeSum();
			int p = i;
			do {
				sum += edgeSum2[p];
				p = parent2[p];
			} while(p != -1 && vertexMap[p] == -1);
			if(p != -1) {
				int a = vertexMap[p], b = vertexMap[i];
				res.push_back(WeightedEdge{ { a, b }, sum });
			}
		}

		return newN;
	}

	EdgeSum getSum(int a, int b) const {
		assert(0 <= a && a < N2 && 0 <= b && b < N2);
		if(a == b) return EdgeSum();
		if(a > b) swap(a, b);
		int lca = b;
		while(a < lca)
			lca = parent2[lca];
		if(lca == -1)
			return EdgeSum::Disconnected();
		EdgeSum res = EdgeSum();
		for(; a != lca; a = parent2[a])
			res += edgeSum2[a];
		for(; b != lca; b = parent2[b])
			res += edgeSum2[b];
		return res;
	}

	int get2(int u) const {
		return teccIndex[u];
	}

	int getN2() const {
		return N2;
	}

	int getNumBridges() const {
		return N2 - numCCs;
	}

private:
	void dfs(int i, int p) {
		iord[i] = ord.size();
		ord.push_back(i);
		parent[i] = p;
		for(auto it = graph.edgesBegin(i); it != graph.edgesEnd(i); ++ it) {
			if(it->to == p) {
				p = -1;
				continue;
			}
			if(parent[it->to] == -2) {
				edgeSum[it->to] = it->getWeight();
				dfs(it->to, i);
			} else if(iord[it->to] < iord[i]) {
				++ num[i];
				-- num[it->to];
			}
		}
	}
};

struct BatchedTwoEdgeConnectivity {
	typedef pair<int, int> Edge;
	typedef TwoEdgeConnectivity::WeightedEdge WeightedEdge;
	typedef pair<int, int> Query;

	struct Interval {
		int l, r;
		Edge edge;
		EdgeSum weight;
	};

	void batchQuery(int N, const vector<Interval> &intervals, const vector<Query> &queries, vector<EdgeSum> &ans) const {
		if(queries.empty()) return;
		TwoEdgeConnectivity tec;
		int Q = queries.size();
		ans.resize(Q);
		int X = intervals.size();
		int logQ = 0;
		while((1 << logQ) < Q) ++ logQ;
		vector<Interval> tmpIntervals(X * (logQ + 1));
		copy(intervals.begin(), intervals.end(), tmpIntervals.begin());
		vector<Query> tmpQueries(Q);
		copy(queries.begin(), queries.end(), tmpQueries.begin());
		vector<int> vertexMap(N, -1);
		vector<WeightedEdge> treeEdges;
		queryRec(N, 0, Q, tmpIntervals.data(), X, tmpIntervals.data() + X, tec, treeEdges, vertexMap, tmpQueries.data(), ans);
	}

private:
	void queryRec(int N, int left, int right, Interval *intervals, int nIntervals, Interval *tmpIntervals, TwoEdgeConnectivity &tec, const vector<WeightedEdge> &treeEdges, vector<int> &vertexMap, Query *queries, vector<EdgeSum> &ans) const {
		bool noQuery = true;
		rep(i, right - left)
			noQuery &= queries[i].first == -1;
		if(noQuery) return;

		tec.init(N);
		for(const WeightedEdge &e : treeEdges)
			tec.addEdge(e);
		rep(i, nIntervals) {
			const Interval &x = intervals[i];
			if(x.l <= left && right <= x.r)
				tec.addEdge(WeightedEdge{ x.edge, x.weight });
		}

		tec.build();

		if(left + 1 == right) {
			int u, v;
			tie(u, v) = queries[0];
			if(u != -1)	//u == -1 
				ans[left] = tec.getSum(tec.get2(u), tec.get2(v));
			return;
		}

		int N2 = tec.getN2();
		vertexMap.assign(N2, -1);

		rep(i, nIntervals) {
			const Interval &x = intervals[i];
			int a = tec.get2(x.edge.first), b = tec.get2(x.edge.second);
			vertexMap[a] = 0;
			vertexMap[b] = 0;
		}

		rep(i, right - left) {
			auto &p = queries[i];
			if(p.first == -1) continue;
			int a = tec.get2(p.first), b = tec.get2(p.second);
			vertexMap[a] = 0;
			vertexMap[b] = 0;
		}

		vector<WeightedEdge> newTreeEdges;
		int newN;
		newN = tec.compressTree(vertexMap, newTreeEdges);

		rep(i, nIntervals) {
			Interval &x = intervals[i];
			x.edge.first = vertexMap[tec.get2(x.edge.first)];
			x.edge.second = vertexMap[tec.get2(x.edge.second)];
		}
		rep(i, right - left) {
			auto &p = queries[i];
			if(p.first >= 0) {
				int a = tec.get2(p.first), b = tec.get2(p.second);
				p.first = vertexMap[a];
				p.second = vertexMap[b];
				if(p.first == p.second) {
					p.first = p.second = -1;
					ans[left + i] = EdgeSum();
				}
			}
		}

		int mid = (left + right) / 2;

		int numL = 0;
		rep(i, nIntervals) {
			const Interval &x = intervals[i];
			if(!(x.l <= left && right <= x.r) && x.l < mid)
				tmpIntervals[numL ++] = x;
		}

		queryRec(newN, left, mid, tmpIntervals, numL, tmpIntervals + numL, tec, newTreeEdges, vertexMap, queries, ans);

		int numR = 0;
		rep(i, nIntervals) {
			const Interval &x = intervals[i];
			if(!(x.l <= left && right <= x.r) && mid < x.r)
				tmpIntervals[numR ++] = x;
		}
		queryRec(newN, mid, right, tmpIntervals, numR, tmpIntervals + numR, tec, newTreeEdges, vertexMap, queries + (mid - left), ans);
	}
};


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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		int s; int t;
		scanf("%d%d", &s, &t), -- s, -- t;

		vector<BatchedTwoEdgeConnectivity::Interval> intervals(m * 2);
		vector<int> weight(m);
		for(int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			weight[i] = w;
			intervals[i * 2 + 0] = { 0, i, { u, v }, EdgeSum(w, i) };
			intervals[i * 2 + 1] = { i + 1, m + 1, { u, v }, EdgeSum(w, i) };
		}

		BatchedTwoEdgeConnectivity btec;
		vector<pair<int, int>> queries(m + 1, make_pair(s, t));
		vector<EdgeSum> result;
		btec.batchQuery(n, intervals, queries, result);

		pair<int, vector<int>> ans(INF * 2, vector<int>());

		if(result[m].isDiconnected())
			amin(ans, make_pair(0, vector<int>{}));

		rep(i, m) {
			if(result[i].isDiconnected()) {
				amin(ans, make_pair(weight[i], vector<int>{ i }));
			} else if(result[i].minWeight != INF) {
				int j = result[i].minIndex;
				assert(result[i].minWeight == weight[j]);
				amin(ans, make_pair(weight[i] + weight[j], vector<int>{ i, j }));
			}
		}
		
		if(ans.first == INF * 2) {
			puts("-1");
		} else {
			printf("%d\n", ans.first);
			printf("%d\n", (int)ans.second.size());
			for(int i = 0; i < (int)ans.second.size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans.second[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}