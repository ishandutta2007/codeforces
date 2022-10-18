//copied. Testing something.
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
#include <functional>
#include <bitset>
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

struct BiconnectedComponents {
	struct Edge {
		int from, to;
	};
	struct To {
		int to; int edge;
	};
	vector<Edge> edges;
	vector<vector<To> > g;
	vector<int> low, ord, depth;
	vector<bool> isArtic;
	vector<int> edgeColor;
	vector<int> edgeStack;
	int colors;
	int dfsCounter;

	void init(int n) {
		edges.clear();
		g.assign(n, vector<To>());
	}

	void addEdge(int u, int v) {
		if(u > v) swap(u, v);
		Edge e = { u, v };
		int ei = edges.size();
		edges.push_back(e);
		To tu = { v, ei }, tv = { u, ei };
		g[u].push_back(tu);
		g[v].push_back(tv);
	}

	void run() {
		int n = g.size(), m = edges.size();
		low.assign(n, -2);
		ord.assign(n, -1);
		depth.assign(n, -2);
		isArtic.assign(n, false);
		edgeColor.assign(m, -1);
		edgeStack.clear();
		colors = 0;

		for(int i = 0; i < n; ++ i) if(ord[i] == -1) {
			dfsCounter = 0;
			dfs2(i);
		}
	}

private:
  inline void dfs2(int root){
    vector<pair<int,int>> S;
    S.push_back({root,-1});
    while(!S.empty()){
      pair<int,int> it = S.back();
      S.pop_back();
      int i = it.first, j = it.second;
      if(j == -1){
        low[i] = ord[i] = dfsCounter++;
      }
      else{
        low[i] = min(low[i],low[g[i][j].to]);
        if(ord[i] == 0 || low[g[i][j].to] >= ord[i]){
          if(ord[i]!=0 || j >= 1)
            isArtic[i] = true;
          while(!edgeStack.empty()){
						edgeColor[edgeStack.back()] = colors;
						if(edgeStack.back() == g[i][j].edge){edgeStack.pop_back();break;}
            edgeStack.pop_back();
	  				}
	  				++colors;
          }
      }
      while(j+1 < (int)g[i].size()){
        j++;
        if(ord[g[i][j].to] == -1){
          depth[g[i][j].to] = depth[i] + 1;
          edgeStack.push_back(g[i][j].edge);
          S.push_back({i,j});
          S.push_back({g[i][j].to,-1});
          break;
        }
			  else if(depth[g[i][j].to] < depth[i] - 1) {
				low[i] = min(low[i], ord[g[i][j].to]);
				edgeStack.push_back(g[i][j].edge);
        }
      }
    }
  }
	void dfs(int i) {
		low[i] = ord[i] = dfsCounter ++;
		for(int j = 0; j < (int)g[i].size(); ++ j) {
			int to = g[i][j].to, ei = g[i][j].edge;
			if(ord[to] == -1) {
				depth[to] = depth[i] + 1;
				edgeStack.push_back(ei);
				dfs(to);
				low[i] = min(low[i], low[to]);
				if(ord[i] == 0 || low[to] >= ord[i]) {
					if(ord[i] != 0 || j >= 1)
						isArtic[i] = true;
					while(!edgeStack.empty()) {
						int fi = edgeStack.back(); edgeStack.pop_back();
						edgeColor[fi] = colors;
						if(fi == ei) break;
					}
					++ colors;
				}
			}else if(depth[to] < depth[i] - 1) {
				low[i] = min(low[i], ord[to]);
				edgeStack.push_back(ei);
			}
		}
	}
};

struct CentroidPathDecomposition {
	vector<int> colors, positions;	//Vertex -> Color, Vertex -> Offset
	vector<int> lengths, parents, branches;	//Color -> Int, Color -> Color, Color -> Offset
	vector<int> parentnodes, depths;	//Vertex -> Vertex, Vertex -> Int
	//vector<FenwickTree>1
	//sortednodes[lefts[v], rights[v])vsubtree
	vector<int> sortednodes, offsets;	//Index -> Vertex, Color -> Index
	vector<int> lefts, rights;	//Vertex -> Index

	struct BuildDFSState {
		int i, len, parent;
		BuildDFSState() { }
		BuildDFSState(int i_, int l, int p): i(i_), len(l), parent(p) { }
	};

	//
	void build(const vector<vi> &g, int root) {
		int n = g.size();

		colors.assign(n, -1); positions.assign(n, -1);
		lengths.clear(); parents.clear(); branches.clear();
		parentnodes.assign(n, -1); depths.assign(n, -1);

		sortednodes.clear(); offsets.clear();
		lefts.assign(n, -1); rights.assign(n, -1);

		vector<int> subtreesizes;
		measure(g, root, subtreesizes);

		typedef BuildDFSState State;
		depths[root] = 0;
		vector<State> s;
		s.push_back(State(root, 0, -1));
		while(!s.empty()) {
			State t = s.back(); s.pop_back();
			int i = t.i, len = t.len;
			int index = sortednodes.size();
			int color = lengths.size();

			if(t.parent == -3) {
				rights[i] = index;
				continue;
			}

			if(t.parent != -2) {
				assert(parents.size() == color);
				parents.push_back(t.parent);
				branches.push_back(len);
				offsets.push_back(index);
				len = 0;
			}
			colors[i] = color;
			positions[i] = len;

			lefts[i] = index;
			sortednodes.push_back(i);

			int maxsize = -1, maxj = -1;
			each(j, g[i]) if(colors[*j] == -1) {
				if(maxsize < subtreesizes[*j]) {
					maxsize = subtreesizes[*j];
					maxj = *j;
				}
				parentnodes[*j] = i;
				depths[*j] = depths[i] + 1;
			}
			s.push_back(State(i, -1, -3));
			if(maxj == -1) {
				lengths.push_back(len + 1);
			}else {
				each(j, g[i]) if(colors[*j] == -1 && *j != maxj)
					s.push_back(State(*j, len, color));
				s.push_back(State(maxj, len + 1, -2));
			}
		}
	}
	
	void get(int v, int &c, int &p) const {
		c = colors[v]; p = positions[v];
	}
	bool go_up(int &c, int &p) const {
		p = branches[c]; c = parents[c];
		return c != -1;
	}

	inline const int *nodesBegin(int c) const { return &sortednodes[0] + offsets[c]; }
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + offsets[c+1]; }

private:
	void measure(const vector<vi> &g, int root, vector<int> &out_subtreesizes) const {
		out_subtreesizes.assign(g.size(), -1);
		vector<int> s;
		s.push_back(root);
		while(!s.empty()) {
			int i = s.back(); s.pop_back();
			if(out_subtreesizes[i] == -2) {
				int s = 1;
				each(j, g[i]) if(out_subtreesizes[*j] != -2)
					s += out_subtreesizes[*j];
				out_subtreesizes[i] = s;
			}else {
				s.push_back(i);
				each(j, g[i]) if(out_subtreesizes[*j] == -1)
					s.push_back(*j);
				out_subtreesizes[i] = -2;
			}
		}
	}
};

struct DynamicRMQ {
	typedef int Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, INF);
	}
	void update(int i, Val x) {
		d[n+i] = x;
		for(int k = (n+i)/2; k > 0; k >>= 1) 
			d[k] = min(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n+i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = INF;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = min(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = min(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};

int lowest_common_ancestor(const CentroidPathDecomposition &cpd, int x, int y) {
	int cx, px, cy, py;
	cpd.get(x, cx, px);
	cpd.get(y, cy, py);
	while(cx != cy) {
		if(cpd.depths[*cpd.nodesBegin(cx)] < cpd.depths[*cpd.nodesBegin(cy)])
			cpd.go_up(cy, py);
		else
			cpd.go_up(cx, px);
	}
	return cpd.nodesBegin(cx)[min(px, py)];
}


struct To {
	typedef int Vertex;
	Vertex to;
	To() { }
	To(Vertex to_): to(to_) { }
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
typedef StaticGraph<To> Graph;

class SchieberVishkinLCA {
public:
	
	typedef unsigned Word;
	typedef Graph::Vertex Vertex;
private:

	static inline Word lowestOneBit(Word v) {
		return v & (~v+1);
	}
	static inline Word highestOneBitMask(Word v) {
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		return v >> 1;
	}

	std::vector<Word> indices;			//Vertex -> index
	std::vector<Word> maxHIndices;		//Vertex -> index
	std::vector<Word> ancestorHeights;	//Vertex -> Word
	std::vector<Vertex> pathParents;	//index-1 -> Vertex
public:
	//g
	void build(const Graph &g, Vertex root) {
		return build(g, std::vector<Vertex>(1, root));
	}
	void build(const Graph &g, const std::vector<Vertex> &roots) {
		int N = g.numVertices();

		ancestorHeights.resize(N);
		std::vector<Vertex> parents(N);
		maxHIndices.resize(N);
		std::vector<Vertex> vertices; vertices.reserve(N);
		indices.resize(N);

		//inorder traversal
		Word currentIndex = 1;
		for(int ri = 0; ri < (int)roots.size(); ri ++) {
			Vertex root = roots[ri];
			parents[root] = root;	//
			vertices.push_back(root);
		}
		while(!vertices.empty()) {
			Vertex v = vertices.back(); vertices.pop_back();
			indices[v] = currentIndex ++;
			for(const Graph::To *it = g.edgesBegin(v); it != g.edgesEnd(v); ++ it) {
				parents[it->to] = v;
				vertices.push_back(it->to);
			}
		}

		//BFS ()
		int head = 0, tail = roots.size();
		vertices.resize(N);
		for(int ri = 0; ri < (int)roots.size(); ri ++)
			vertices[ri] = roots[ri];
		while(head != tail) {
			Vertex v = vertices[head ++];
			for(const Graph::To *it = g.edgesBegin(v); it != g.edgesEnd(v); ++ it)
				vertices[tail ++] = it->to;
		}

		//
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it)
			maxHIndices[*it] = indices[*it];
		for(std::vector<Vertex>::const_reverse_iterator it = vertices.rbegin(); it != vertices.rend(); ++ it) {
			Vertex v = *it, parent = parents[v];
			if(lowestOneBit(maxHIndices[parent]) < lowestOneBit(maxHIndices[v]))
				maxHIndices[parent] = maxHIndices[v];
		}

		//A
		for(int ri = 0; ri < (int)roots.size(); ri ++) {
			Vertex root = roots[ri];
			ancestorHeights[root] = 0;
		}
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it) {
			Vertex v = *it;
			ancestorHeights[v] = ancestorHeights[parents[v]] | lowestOneBit(maxHIndices[v]);
		}

		pathParents.swap(parents);	//
		for(int ri = 0; ri < (int)roots.size(); ri ++) {
			Vertex root = roots[ri];
			pathParents[indices[root]-1] = root;
		}
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it) {
			Vertex v = *it;
			for(const Graph::To *jt = g.edgesBegin(v); jt != g.edgesEnd(v); ++ jt) {
				if(maxHIndices[v] != maxHIndices[jt->to])
					pathParents[indices[jt->to]-1] = v;
				else
					pathParents[indices[jt->to]-1] = pathParents[indices[v]-1];
			}
		}
	}

	Vertex query(Vertex v, Vertex u) const {
		//binary treeLCA
		Word Iv = maxHIndices[v], Iu = maxHIndices[u];
		Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
		Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
		Word j = lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
		//j = hI(lca(v,u))  (hI(x) = 2^(complete binary treeI(x)), I(x) = maxHIndices[x])
		//(hI(lca(v,u)) = j)hI(v)hI(u)
		Vertex x, y;
		if(j == hIv) x = v;
		else {			//lcav
			Word kMask = highestOneBitMask(ancestorHeights[v] & (j-1));	//vj
			x = pathParents[(indices[v] & ~kMask | (kMask+1))-1];	//indices[v]k
		}
		if(j == hIu) y = u;
		else {			//lcau
			Word kMask = highestOneBitMask(ancestorHeights[u] & (j-1));	//uj
			y = pathParents[(indices[u] & ~kMask | (kMask+1))-1];	//indices[u]k
		}
		return indices[x] < indices[y] ? x : y;	//in-order
	}
};

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<int> weights(n);
	rep(i, n) scanf("%d", &weights[i]);
	BiconnectedComponents bc;
	bc.init(n);
	rep(i, m) {
		int a, b;
		scanf("%d%d", &a, &b), -- a, -- b;
		bc.addEdge(a, b);
	}
	bc.run();
	int C = bc.colors;
	vector<vi> tree(C + n + 1);
	vector<vi> handles(n);
	vi tmpv;
	rep(i, n) {
		tmpv.clear();
		each(j, bc.g[i]) {
			int ei = j->edge;
			tmpv.push_back(bc.edgeColor[ei]);
		}
		sort(all(tmpv));
		tmpv.erase(unique(all(tmpv)), tmpv.end());
		if(tmpv.empty()) { cerr <<"err" << endl; return 1; }
		if(tmpv.size() == 1) {
			handles[i].push_back(tmpv[0]);
		}else {
			handles[i].push_back(C + i);
			each(j, tmpv) {
				tree[C + i].push_back(*j);
				tree[*j].push_back(C + i);
			}
		}
	}
	const int B = 500;
	vector<int> bigvertices;
	rep(i, n) {
		int v = handles[i][0];
		if(v < C) continue;
		if((int)tree[v].size() < B) {
			each(j, tree[v])
				handles[i].push_back(*j);
		}else {
			bigvertices.push_back(i);
		}
	}
	int root = C + n;
	rep(i, C + n) if(tree[i].empty()) {
		tree[i].push_back(root);
		tree[root].push_back(i);
	}
	if(!tree[0].empty()) {
		tree[0].push_back(root);
		tree[root].push_back(0);
	}
	CentroidPathDecomposition cpd;
	cpd.build(tree, root);
	vector<Graph::Edge> gedges;
	rep(i, C + n + 1) {
		int p = cpd.parentnodes[i];
		if(p != -1) gedges.push_back(Graph::Edge(p, i));
	}
	Graph gg; gg.init(C + n + 1, gedges);
	SchieberVishkinLCA lca;
	lca.build(gg, root);
	DynamicRMQ rmq;
	rmq.init(C + n + 1);
	vector<set<int> > sets(C + n + 1);
	rep(i, n) {
		each(v, handles[i]) {
			int c, p;
			cpd.get(*v, c, p);
			int o = cpd.offsets[c] + p;
			sets[o].insert(weights[i]);
			rmq.update(o, *sets[o].begin());
		}
	}
	char ty[2];
	rep(ii, q) {
		scanf("%s", &ty);
		if(*ty == 'C') {
			int a, neww;
			scanf("%d%d", &a, &neww), -- a;
			int oldw = weights[a];
			weights[a] = neww;
			each(v, handles[a]) {
				int c, p;
				cpd.get(*v, c, p);
				int o = cpd.offsets[c] + p;
				sets[o].erase(oldw);
				sets[o].insert(neww);
				rmq.update(o, *sets[o].begin());
			}
		}else if(*ty == 'A') {
			int a, b;
			scanf("%d%d", &a, &b), -- a, -- b;
			int ans = INF;
			if(a == b) {
				printf("%d\n", weights[a]);
				continue;
			}
			int u = handles[a][0], v = handles[b][0];
			{
				int w = lowest_common_ancestor(cpd, u, v), wc, wp;
				cpd.get(w, wc, wp);
				rep(uv, 2) {
					int c, p;
					cpd.get(uv == 0 ? u : v, c, p);
					while(1) {
						int top = c == wc ? wp + uv : 0;
						int o = cpd.offsets[c], len = cpd.lengths[c];
						//[o + top, o + p] ()
						int t = rmq.query(o + top, o + p + 1);
						amin(ans, t);
						if(c == wc) break;
						cpd.go_up(c, p);
					}
				}
			}
			each(i, bigvertices) {
				int w = C + *i;
				{	int l = lca.query(u, w);
					if(cpd.parentnodes[w] == l)
						amin(ans, weights[*i]);
				}
				{	int l = lca.query(v, w);
					if(cpd.parentnodes[w] == l)
						amin(ans, weights[*i]);
				}
			}
			printf("%d\n", ans);
		}else return 1;
	}
	return 0;
}