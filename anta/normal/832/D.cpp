#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


class SchieberVishkinLCA {
public:
	typedef unsigned Word;
	typedef int Vertex;
private:

	static inline Word lowestOneBit(Word v) {
		return v & (~v + 1);
	}
	static inline Word highestOneBitMask(Word v) {
		v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16;
		return v >> 1;
	}

	std::vector<Word> indices;			//Vertex -> index
	std::vector<Word> maxHIndices;		//Vertex -> index
	std::vector<Word> ancestorHeights;	//Vertex -> Word
	std::vector<Vertex> pathParents;	//index-1 -> Vertex
public:

	void build(const std::vector<Vertex> &preorder, const std::vector<Vertex> &parents, Vertex root) {
		Vertex N = static_cast<Vertex>(preorder.size());

		ancestorHeights.resize(N);
		maxHIndices.resize(N);
		indices.resize(N);
		pathParents.resize(N);

		for (Vertex ix = 0; ix < N; ++ ix)
			indices[preorder[ix]] = ix + 1;

		for (Vertex i = 0; i < N; ++ i)
			maxHIndices[i] = indices[i];
		for (Vertex ix = N - 1; ix > 0; -- ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if (lowestOneBit(maxHIndices[parent]) < lowestOneBit(maxHIndices[v]))
				maxHIndices[parent] = maxHIndices[v];
		}

		ancestorHeights[root] = 0;
		for (Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			ancestorHeights[v] = ancestorHeights[parent] | lowestOneBit(maxHIndices[v]);
		}

		pathParents[0] = root;
		for (Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if (maxHIndices[v] != maxHIndices[parent])
				pathParents[indices[v] - 1] = parent;
			else
				pathParents[indices[v] - 1] = pathParents[indices[parent] - 1];
		}
	}

	Vertex query(Vertex v, Vertex u) const {
		Word Iv = maxHIndices[v], Iu = maxHIndices[u];
		Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
		Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
		Word j = lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
		Vertex x, y;
		if (j == hIv) x = v;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[v] & (j - 1));
			x = pathParents[(indices[v] & ~kMask | (kMask + 1)) - 1];
		}
		if (j == hIu) y = u;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[u] & (j - 1));
			y = pathParents[(indices[u] & ~kMask | (kMask + 1)) - 1];
		}
		return indices[x] < indices[y] ? x : y;
	}
};

struct HLD {
	vector<vi> paths;
	vector<pair<int, int> > pathParent;
	vector<pair<int, int> > nodePos;
	vector<int> nodeDepth;
	vector<int> offsets;
	SchieberVishkinLCA lca;

	void build(const vector<vi> &g, int root) {
		int N = g.size();
		vector<int> t_ord, t_parent(N, -1);
		nodeDepth.assign(N, 0);
		{
			vector<int> stk;
			stk.push_back(root);
			while (!stk.empty()) {
				int i = stk.back();
				stk.pop_back();
				t_ord.push_back(i);
				for (int j : g[i]) if (j != root && t_parent[j] == -1) {
					t_parent[j] = i;
					nodeDepth[j] = nodeDepth[i] + 1;
					stk.push_back(j);
				}
			}
		}
		vector<int> subtsize(N, 1);
		for (int ix = N - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		paths.clear();
		paths.push_back(vi());
		pathParent.emplace_back(-1, 0);
		dfs(root, -1, g, subtsize);
		assert(paths.back().empty());
		paths.pop_back();
		assert(paths.size() == pathParent.size());

		nodePos.assign(N, { -1, -1 });
		rep(c, paths.size()) rep(p, paths[c].size())
			nodePos[paths[c][p]] = { c, p };

		lca.build(t_ord, t_parent, root);

		offsets.assign(paths.size() + 1, 0);
		rep(c, paths.size())
			offsets[c + 1] = offsets[c] + paths[c].size();
	}

	void get(int u, int &c, int &p) const {
		tie(c, p) = nodePos[u];
	}

	void go_up(int &c, int &p) const {
		tie(c, p) = pathParent[c];
	}

	void addPathVertices(int u, int v, int label, vector<pii> &path) const {
		int w = lca.query(u, v);
		int uc, up, vc, vp, wc, wp;
		get(u, uc, up);
		get(v, vc, vp);
		get(w, wc, wp);
		while (uc != wc) {
			int o = offsets[uc];
			path.emplace_back(o + 0, +label);
			path.emplace_back(o + (up + 1), -label);
			go_up(uc, up);
		}
		while (vc != wc) {
			int o = offsets[vc];
			path.emplace_back(o + 0, +label);
			path.emplace_back(o + (vp + 1), -label);
			go_up(vc, vp);
		}
		{
			int o = offsets[wc];
			path.emplace_back(o + wp, +label);
			path.emplace_back(o + (max(vp, up) + 1), -label);
		}
	}

private:
	void dfs(int i, int p, const vector<vi> &g, const vector<int> &subtsize) {
		int color = (int)paths.size() - 1;
		int pos = paths.back().size();
		paths.back().push_back(i);

		int c = -1;
		for (int j : g[i]) if (j != p) {
			if (c == -1 || subtsize[c] < subtsize[j])
				c = j;
		}

		if (c == -1) {
			paths.push_back(vi());
			return;
		}

		dfs(c, i, g, subtsize);

		for (int j : g[i]) if (j != p && j != c) {
			pathParent.emplace_back(color, pos);
			dfs(j, i, g, subtsize);
		}
	}
};


int main() {
	int n; int Q;
	while (~scanf("%d%d", &n, &Q)) {
		vector<vi> g(n);
		rep(i, n - 1) {
			int p;
			scanf("%d", &p), -- p;
			g[i + 1].push_back(p);
			g[p].push_back(i + 1);
		}
		HLD hld;
		hld.build(g, 0);
		vpii intervals;
		rep(ii, Q) {
			int a; int b; int c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b, -- c;
			intervals.clear();
			hld.addPathVertices(a, b, 1, intervals);
			hld.addPathVertices(a, c, 2, intervals);
			hld.addPathVertices(b, c, 3, intervals);
			sort(intervals.begin(), intervals.end());
			int cnts[1 << 3] = {};
			int curMask = 0, left = 0;
			for (auto p : intervals) {
				cnts[curMask] += p.first - left;
				if (p.second > 0) {
					curMask |= 1 << (p.second - 1);
				} else {
					curMask &= ~(1 << (-p.second - 1));
				}
				left = p.first;
			}
			int ans = max({ cnts[3], cnts[5], cnts[6] }) + cnts[7];
			printf("%d\n", ans);
		}
	}
	return 0;
}