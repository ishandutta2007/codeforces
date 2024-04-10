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
	typedef StaticGraph<To> Graph;
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
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + (c+1 == offsets.size() ? sortednodes.size() : offsets[c+1]); }

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

int level_ancestor(const CentroidPathDecomposition &cpd, int x, int d) {
	int c, p;
	const int *head;
	if(d > cpd.depths[x]) return -1;
	cpd.get(x, c, p);
	while(d < cpd.depths[*(head = cpd.nodesBegin(c))])
		cpd.go_up(c, p);
	return head[d - cpd.depths[*head]];
}

int get_ancestor_child(const CentroidPathDecomposition &cpd, int x, int y) {
	return level_ancestor(cpd, y, cpd.depths[x] + 1);
}

vector<vi> g;
vi depths;
vector<Graph::Edge> edges;
vi subtsize;
vi parents;

void dfs(int i, int p, int dep) {
	subtsize[i] = 1;
	parents[i] = p;
	depths[i] = dep;
	each(j, g[i]) if(*j != p) {
		edges.push_back(Graph::Edge(i, *j));
		dfs(*j, i, dep + 1);
		subtsize[i] += subtsize[*j];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	g.assign(n, vi());
	rep(i, n-1) {
		int a, b;
		scanf("%d%d", &a, &b), -- a, -- b;
//		a = i+1, b = i/2;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	depths.assign(n, -1);
	subtsize.assign(n+1, 0);
	parents.assign(n, -1);
	dfs(0, -1, 0);
	subtsize[n] = 0;
	Graph gg; gg.init(n, edges);
	SchieberVishkinLCA lca;
	lca.build(gg, 0);
	CentroidPathDecomposition cpd;
	cpd.build(g, 0);
	int m;
	scanf("%d", &m);
	rep(ii, m) {
		int x, y;
		scanf("%d%d", &x, &y), -- x, -- y;
//		x=rand()%n,y=rand()%n;
//		int aans = 0;
//		rep(p, n) if(depths[x] + depths[p] - depths[lca.query(x, p)] * 2 == depths[y] + depths[p] - depths[lca.query(y, p)] * 2) ++ aans;
		int z = lca.query(x, y);
		int len = depths[x] + depths[y] - depths[z] * 2;
		int ans;
		if(x == y) {
			ans = n;
		}else if(len % 2 != 0) {
			ans = 0;
		}else {
			int l = len / 2;
			int t = depths[x] - depths[z];
			if(l > t) {
				swap(x, y);
				t = depths[x] - depths[z];
			}
			if(l < t) {
				int w = level_ancestor(cpd, x, depths[x] - l);
				int cx = x == w ? n : get_ancestor_child(cpd, w, x);
				ans = n - subtsize[cx] - (n - subtsize[w]);
			}else if(l == t) {
				int cx = x == z ? n : get_ancestor_child(cpd, z, x);
				int cy = y == z ? n : get_ancestor_child(cpd, z, y);
				ans = n - subtsize[cx] - subtsize[cy];
			}else {
				assert(false);
				return 1;
			}
		}
//		if(ans != aans)
//			cerr << ans << ", " << aans << endl;
		printf("%d\n", ans);
	}
	return 0;
}