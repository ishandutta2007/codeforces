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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct HeavyLightDecomposition {
	vector<int> colors, positions;	//Vertex -> Color, Vertex -> Offset
	vector<int> lengths, parents, branches;	//Color -> Int, Color -> Color, Color -> Offset
	vector<int> parentnodes, depths;	//Vertex -> Vertex, Vertex -> Int
										//vector<FenwickTree>1
										//sortednodes[lefts[v], rights[v])vsubtree
	vector<int> sortednodes, offsets;	//Index -> Vertex, Color -> Index
	vector<int> lefts, rights;	//Vertex -> Index

	struct BuildDFSState {
		int i, len, parent;
		BuildDFSState() {}
		BuildDFSState(int i_, int l, int p) : i(i_), len(l), parent(p) {}
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
			} else {
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
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + (c + 1 == offsets.size() ? sortednodes.size() : offsets[c + 1]); }

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
			} else {
				s.push_back(i);
				each(j, g[i]) if(out_subtreesizes[*j] == -1)
					s.push_back(*j);
				out_subtreesizes[i] = -2;
			}
		}
	}
};

int level_ancestor(const HeavyLightDecomposition &hld, int x, int d) {
	int c, p;
	const int *head;
	if(d > hld.depths[x]) return -1;
	hld.get(x, c, p);
	while(d < hld.depths[*(head = hld.nodesBegin(c))])
		hld.go_up(c, p);
	return head[d - hld.depths[*head]];
}
int get_ancestor_child(const HeavyLightDecomposition &hld, int x, int y) {
	return level_ancestor(hld, y, hld.depths[x] + 1);
}

int lowest_common_ancestor(const HeavyLightDecomposition &hld, int x, int y) {
	int cx, px, cy, py;
	hld.get(x, cx, px);
	hld.get(y, cy, py);
	while(cx != cy) {
		if(hld.depths[*hld.nodesBegin(cx)] < hld.depths[*hld.nodesBegin(cy)])
			hld.go_up(cy, py);
		else
			hld.go_up(cx, px);
	}
	return hld.nodesBegin(cx)[min(px, py)];
}



int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		HeavyLightDecomposition hld;
		hld.build(g, 0);
		vi t_ord = hld.sortednodes, t_parent = hld.parentnodes;
		vi depth(n), subtsize(n, 1);
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}
		vector<ll> depthsum(all(depth));
		for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
			depthsum[p] += depthsum[i];
		}
		vector<ll> sumdistp(n);
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			ll d = sumdistp[p];
			d += n - subtsize[p];
			d += depthsum[p] - (ll)depth[p] * subtsize[p];
			d -= depthsum[i] - (ll)(depth[i] - 1) * subtsize[i];
			sumdistp[i] = d;
		}
		rep(ii, m) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			int w = lowest_common_ancestor(hld, u, v);
			int pathlen = depth[u] + depth[v] - depth[w] * 2;
			double ans = pathlen + 1;
			rep(uv, 2) {
				ll sumdist; int den;
				if(u != w) {
					sumdist = depthsum[u] - (ll)depth[u] * subtsize[u];
					den = subtsize[u];
				} else {
					int c = get_ancestor_child(hld, u, v);
					sumdist = sumdistp[c];
					den = n - subtsize[c];
				}
				ans += (double)sumdist / den;
				swap(u, v);
			}
			printf("%.10f\n", ans);
		}
	}
	return 0;
}