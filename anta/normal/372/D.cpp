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
#include <list>
#include <cassert>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

vector<int> edges[100000];
 
int cpd_size[100000];			// -> -1
int cpd_parentnode[100000];		// ->  (root-1)
int cpd_colors;					//
int cpd_color[100000];			// -> 
int cpd_position[100000];		// -> (0-origin)
vector<int> cpd_nodes[100000];	// -> s
int cpd_length[100000];			// -> 
int cpd_parent[100000];			// -> 
int cpd_branch[100000];			// -> 
 
int cpd_measure(int i, int parent) {
	cpd_parentnode[i] = parent;
	int s = 0;
	each(j, edges[i]) if(*j != parent) {
		s += cpd_measure(*j, i);
	}
	cpd_size[i] = s;
	return s + 1;
}
 
void cpd_getcolor(int i, int parent, int length) {
	int currentcolor = cpd_colors;
	cpd_color[i] = currentcolor;
	cpd_position[i] = length;
	cpd_nodes[currentcolor].push_back(i);
	int maxsize = -INF, maxj = -1;
	each(j, edges[i]) if(*j != parent) {
		if(maxsize < cpd_size[*j]) {
			maxsize = cpd_size[*j];
			maxj = *j;
		}
	}
	if(maxj == -1) {
		cpd_length[currentcolor] = length + 1;
		cpd_colors ++;
	}else {
		cpd_getcolor(maxj, i, length + 1);
		each(j, edges[i]) if(*j != parent && *j != maxj) {
			cpd_parent[cpd_colors] = currentcolor;
			cpd_branch[cpd_colors] = length;
			cpd_nodes[cpd_colors].clear();
			cpd_getcolor(*j, i, 0);
		}
	}
}
 
void cpd_init(int root) {
	cpd_nodes[0].clear();
	cpd_measure(root, -1);
	cpd_colors = 0;
	cpd_parent[0] = -1;
	cpd_branch[0] = 0;
	cpd_getcolor(root, -1, 0);
}


typedef int Vertex;
struct Graph {
	typedef std::pair<Vertex, Vertex> Edge;
	struct To {
		Vertex to;
	};

	int n, m;

	Graph(int n_, const std::vector<Edge> &edges):
		n(n_), m(edges.size()), tos(m+1), offsets(n+1, 0) {
		for(int e = 0; e < m; e ++) offsets[edges[e].first] ++;
		for(int v = 1; v <= n; v ++) offsets[v] += offsets[v-1];
		for(int e = 0; e < m; e ++)
			tos[-- offsets[edges[e].first]].to = edges[e].second;
	}

	inline const To *edgesBegin(int v) const { return &tos[offsets[v]]; }
	inline const To *edgesEnd(int v) const { return &tos[offsets[v+1]]; }

	inline const int outDegree(int v) const { return offsets[v+1] - offsets[v]; }

private:
	std::vector<To> tos;
	std::vector<int> offsets;
};

class SchieberVishkinLCA {
public:
	typedef unsigned Word;
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
		assert(g.m == g.n - 1);

		ancestorHeights.resize(g.n);
		std::vector<Vertex> parents(g.n);
		maxHIndices.resize(g.n);
		std::vector<Vertex> vertices; vertices.reserve(g.n);
		indices.resize(g.n);

		//euler tour
		Word currentIndex = 1;
		parents[root] = root;	//
		vertices.push_back(root);
		while(!vertices.empty()) {
			Vertex v = vertices.back(); vertices.pop_back();
			indices[v] = currentIndex ++;
			for(const Graph::To *it = g.edgesBegin(v); it != g.edgesEnd(v); ++ it) {
				parents[it->to] = v;
				vertices.push_back(it->to);
			}
		}

		//BFS ()
		int head = 0, tail = 1;
		vertices.resize(g.n); vertices[0] = root;
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
		ancestorHeights[root] = 0;
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it) {
			Vertex v = *it;
			ancestorHeights[v] = ancestorHeights[parents[v]] | lowestOneBit(maxHIndices[v]);
		}

		pathParents.swap(parents);	//
		pathParents[indices[root]-1] = root;
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

SchieberVishkinLCA lcat;

int lca(int x, int y) {
	if(x == -1 || y == -1) return x == -1 ? y : x;
	return lcat.query(x, y);
}

struct RangeLCA {
	typedef int Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, -1);
		rep(i, nmin) d[n+i] = i;
		for(int i = n-1; i >= 0; i --)
			d[i] = lca(d[i*2], d[i*2+1]);
	}
	//[l, r)
	Val query(int l, int r) const {
		Val m = -1;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = lca(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = lca(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};

vector<pii> edges2;


template<typename Val, typename Laziness>
struct LazyPropagationSegmentTreeBase {
	vector<Val> nodes;
	vector<Laziness> laziness;
	vector<bool> islazy;
	int n;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		nodes.resize(n);
		nodes.insert(nodes.end(), u.begin(), u.end());
		nodes.resize(n * 2, Val());
		for(int i = n-1; i > 0; -- i)
			nodes[i] = nodes[i*2] + nodes[i*2+1];
		laziness.assign(n, Laziness());
		islazy.assign(n, false);
	}
	Val get(int i) {
		static int indices[128];
		int k = getIndices(indices, i, i+1);
		propagateRange(indices, k);
		return nodes[i + n];
	}
	Val getRange(int i, int j) {
		static int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Val res = Val();
		for(int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += value(l ++);
			if(r & 1) res += value(-- r);
		}
		return res;
	}
	void set(int i, const Val &x) {
		static int indices[128];
		int k = getIndices(indices, i, i+1);
		propagateRange(indices, k);
		nodes[n + i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Laziness &x) {
		if(i >= j) return;
		static int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if(l & 1) nodes[l ++] += x;
		if(r & 1) nodes[-- r] += x;
		for(l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) islazy[l] = true, laziness[l ++] += x;
			if(r & 1) laziness[-- r] += x, islazy[r] = true;
		}
		mergeRange(indices, k);
	}
	//2sum[i,right)xiright
	int rightmost_le(int right, const Val &x) {
		if(getRange(0, right) < x) return 0;
		return min(right, rightmost_le_rec(x + getRange(right, n), 1, 0, n));
	}
private:
	int getIndices(int indices[128], int i, int j) {
		int k = 0, l, r;
		if(i >= j) return 0;
		for(l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
			indices[k ++] = l;
			indices[k ++] = r;
		}
		for(; l; l >>= 1) indices[k ++] = l;
		return k;
	}
	void propagateRange(int indices[], int k) {
		for(int i = k - 1; i >= 0; -- i)
			propagate(indices[i]);
	}
	void mergeRange(int indices[], int k) {
		for(int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void propagate(int i) {
		if(i >= n || !islazy[i]) return;
		nodes[i] += laziness[i] * width(i);
		if(i * 2 < n) {
			laziness[i * 2] += laziness[i];
			laziness[i * 2 + 1] += laziness[i];
			islazy[i * 2] = true;
			islazy[i * 2 + 1] = true;
		}else {
			nodes[i * 2] += laziness[i];
			nodes[i * 2 + 1] += laziness[i];
		}
		laziness[i] = Laziness();
		islazy[i] = false;
	}
	inline void merge(int i) {
		if(i >= n) return;
		nodes[i] = value(i * 2) + value(i * 2 + 1);
	}
	inline Val value(int i) {
		propagate(i);
		return nodes[i];
	}
	inline int width(int i) {
		i |= i >> 1;
		i |= i >> 2;
		i |= i >> 4;
		i |= i >> 8;
		i |= i >> 16;
		return n / ((i + 1) >> 1);
	}
	int rightmost_le_rec(const Val &x, int i, int pos, int w) {
		if(n <= i) return pos + 1;
		propagate(i);
		int mid = pos + w / 2;
		if(value(i * 2 + 1) >= x)
			return rightmost_le_rec(x, i * 2 + 1, mid, w / 2);
		else return rightmost_le_rec(x - value(i * 2 + 1), i * 2, pos, w / 2);
	}
};

template<typename Val>
struct LazySumSegmentTree : LazyPropagationSegmentTreeBase<Val,Val> { };

int depth[100000];
vector<LazySumSegmentTree<ll> > path_sum;

RangeLCA rlca;
int currentlca;
int currenans;
int cntleft, cntright;

void dfs1(int i, int parent, int dep) {
	depth[i] = dep;
	each(j, edges[i]) if(*j != parent) {
		edges2.pb(mp(i, *j));
		dfs1(*j, i, dep+1);
	}
}


void pathaddval(int v, int x) {
	int c = cpd_color[v], p = cpd_position[v];
	while(c != -1) {
		path_sum[c].addToRange(0, p+1, x);
		p = cpd_branch[c];
		c = cpd_parent[c];
	}
}
int pathgetval(int v) {
	int c = cpd_color[v], p = cpd_position[v];
	return path_sum[c].get(p);
}
int pathgetdist(int v) {
	int c = cpd_color[v], p = cpd_position[v];
	int res = 0;
	while(c != -1) {
//		rep(j, cpd_length[c]) cerr << path_sum[c].get(j) << ",";
		int i = path_sum[c].rightmost_le(p + 1, 1) - 1;
//		cerr << "; " << p << ": " << i << endl;
		if(i != -1) {
			res += p - i;
			break;
		}
		res += p+1;
		p = cpd_branch[c];
		c = cpd_parent[c];
	}
	return res;
}

void add(int v) {
	if(pathgetval(v) == 0) {
//		if(v>=65000 && pathgetdist(v) != 0) cerr << "add1 " << v<< ": "<<pathgetdist(v)<<endl;
		currenans += pathgetdist(v);
	}
	pathaddval(v, 1);
	int new_lca = lca(currentlca, v);
	if(new_lca != currentlca && currentlca != -1) {
		currenans += depth[currentlca] - depth[new_lca];
	}
	currentlca = new_lca;
	assert(rlca.query(cntleft, cntright) == currentlca);
}

void del(int v) {
	pathaddval(v, -1);
	if(pathgetval(v) == 0) {
		currenans -= pathgetdist(v);
	}
	int new_lca = rlca.query(cntleft, cntright);
	if(new_lca != -1) {
		currenans -= depth[new_lca] - depth[currentlca];
	}
	currentlca = new_lca;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	rep(i, n-1) {
		int a, b;
		scanf("%d%d", &a, &b);
//		a = i+1, b = i+2;
		a --, b --;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	cpd_init(0);
	path_sum.resize(cpd_colors);
	rep(i, cpd_colors) path_sum[i].init(cpd_length[i]);

	dfs1(0, -1, 0);
	lcat.build(Graph(n, edges2), 0);
	rlca.init(n);
	currentlca = -1;
	currenans = 0;

	cntright = 0;
	int ans = 0;
	for(cntleft = 0; cntleft < n; cntleft ++) {
		if(cntleft != 0) del(cntleft-1);
		while(1) {
//			cerr << cntleft+1 << ".." << cntright << ": " << currenans << endl;
			if(currenans > k) break;
			ans = max(ans, cntright - cntleft);
			if(cntright == n) break;
			cntright ++;
			add(cntright-1);
		}
	}
	printf("%d\n", ans);
	return 0;
}