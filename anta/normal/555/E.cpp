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

int two_edge_connected_components(const vector<vector<int> > &g, vector<int> &color, vector<int> &ord, vector<int> &low, const vpii &multiedges) {
	int n = g.size();
	compute_lowlinks(g, ord, low);
	int colors = 0;
	color.assign(n, -1);
	UnionFind uf; uf.init(n);
	each(i, multiedges)
		uf.unionSet(i->first, i->second);
	rep(i, n) each(j, g[i]) if(!is_bridge_edge(i, *j, ord, low))
		uf.unionSet(i, *j);
	rep(i, n) if(uf.root(i) == i)
		color[i] = colors ++;
	rep(i, n)
		color[i] = color[uf.root(i)];
	return colors;
}

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

int main() {
	int nn, m, q;
	while(1) {
		if(!~scanf("%d%d%d", &nn, &m, &q)) break;
//		nn=rand()%10+2,m=rand()%20+1,q=rand()%5+1;
		vector<vi> gg(nn);
		UnionFind uf; uf.init(nn);
		set<pii> edges;
		vpii omultiedges;
		rep(i, m) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
//			do u=rand()%nn,v=rand()%nn; while(u==v);
			assert(u != v);
			if(u > v) swap(u, v);
			if(edges.count(mp(u, v))) {
				omultiedges.push_back(mp(u, v));
				continue;
			}
			edges.insert(mp(u, v));
			gg[u].push_back(v);
			gg[v].push_back(u);
			uf.unionSet(u, v);
		}
		bool ok = true;
		vpii oqueries(q);
		rep(i, q) {
			int s, d;
			scanf("%d%d", &s, &d), -- s, -- d;
//			s=rand()%nn,d=rand()%nn;
			oqueries[i] = mp(s, d);
			ok &= uf.findSet(s, d);
		}
		if(!ok) {
			puts("No");
			continue;
		}
		vector<vi> ccs(nn);
		vi idx(nn, -1);
		rep(i, nn) {
			idx[i] = ccs[uf.root(i)].size();
			ccs[uf.root(i)].push_back(i);
		}
		vector<vpii> multiedges(nn);
		each(i, omultiedges) if(idx[i->first] != -1)
			multiedges[uf.root(i->first)].push_back(mp(idx[i->first], idx[i->second]));
		vector<vpii> queries(nn);
		each(i, oqueries)
			queries[uf.root(i->first)].push_back(mp(idx[i->first], idx[i->second]));
		rep(oroot, nn) if(uf.root(oroot) == oroot) {
			const vi &cc = ccs[oroot];
			int V = cc.size();
			vector<vi> g(V);
			each(i, cc) each(j, gg[*i])
				g[idx[*j]].push_back(idx[*i]);
			vi col, ord, low;
			int C = two_edge_connected_components(g, col, ord, low, multiedges[oroot]);
			vector<vi> tree(C);
			rep(i, V) each(j, g[i]) if(col[i] != col[*j])
				tree[col[i]].push_back(col[*j]);
			CentroidPathDecomposition cpd;
			cpd.build(tree, 0);
			vi add1(C, 0), add2(C, 0);
			each(i, queries[oroot]) {
				int u = col[i->first];
				int v = col[i->second];
				int w = lowest_common_ancestor(cpd, u, v);
				++ add1[u], -- add1[w];
				++ add2[v], -- add2[w];
			}
			for(int ix = C-1; ix > 0; -- ix) {
				int i = cpd.sortednodes[ix], p = cpd.parentnodes[i];
				add1[p] += add1[i];
				add2[p] += add2[i];
			}
			rep(i, C)
				ok &= add1[i] == 0 || add2[i] == 0;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}