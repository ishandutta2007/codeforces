#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename VertexAttr, typename EdgeAttr>
class CentroidDecomposition {
public:
	struct Vertex : VertexAttr {
		int id;

		Vertex() {}
		Vertex(int id, VertexAttr attr) : id(id), VertexAttr(attr) {}
	};

	struct VertexAndEdge : Vertex, EdgeAttr {
		VertexAndEdge() {}
		VertexAndEdge(Vertex vertex, EdgeAttr edgeAttr) : Vertex(vertex), EdgeAttr(edgeAttr) {}
	};

	struct TourEntry : VertexAndEdge {
		unsigned f;

		TourEntry() {}
		TourEntry(Vertex to, EdgeAttr edgeAttr, unsigned f) :
			VertexAndEdge(to, edgeAttr), f(f) {
		}
	};

	struct DfsEntry : VertexAndEdge {
		int px;
		DfsEntry() {}
		DfsEntry(VertexAndEdge vertexAndEdge, int px) :
			VertexAndEdge(vertexAndEdge), px(px) {
		}
	};

	void init(
		const vector<int> &t_ord, const vector<int> &t_parent,
		const vector<VertexAttr> &vertexAttrs,
		const vector<EdgeAttr> &upEdgeAttrs,
		const vector<EdgeAttr> &downEdgeAttrs) {
		int n = (int)t_ord.size();
		vector<unsigned> a(n), b(n), f(n);
		unsigned maxf = 0;
		for(int ix = n - 1; ix >= 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			unsigned m = b[i];
			m |= m >> 1;
			m |= m >> 2;
			m |= m >> 4;
			m |= m >> 8;
			m |= m >> 16;
			unsigned fi = ~(a[i] | m);
			fi &= ~fi + 1;
			f[i] = fi;
			if(maxf < fi)
				maxf = fi;
			unsigned S = (a[i] & ~(fi - 1)) | fi;
			if(p != -1) {
				b[p] |= a[p] & S;
				a[p] |= S;
			}
		}
		eulerTour(t_ord, t_parent, vertexAttrs, upEdgeAttrs, downEdgeAttrs, f, _tour);
		_currentLevel = 0;
		while(maxf >> 1 >> _currentLevel) ++ _currentLevel;
		_subtrees.assign(_currentLevel + 1, vector<pair<int, int> >());
		if(_currentLevel != 0) {
			int middle = 1;
			while(_tour[middle].f != maxf) ++ middle;
			std::rotate(_tour.begin() + 1, _tour.begin() + (middle + 1), _tour.end());
		}
		_subtrees[_currentLevel].assign(1, make_pair(1, (n - 1) * 2 + 1));
	}

	bool makeNextLevel() {
		if(_currentLevel == 0) return false;
		unsigned lv = 1U << (_currentLevel - 1);
		const vector<pair<int, int> > &currentSubtrees = _subtrees[_currentLevel];
		for(int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			int nextL = L + 1;
			unsigned nextLevel = 0;
			int nextMiddle = -1;
			for(int ix = L; ix < R; ++ ix) {
				unsigned f = _tour[ix].f;
				if(f > lv) {
					std::rotate(_tour.begin() + nextL, _tour.begin() + nextMiddle, _tour.begin() + ix);
					int k = _currentLevel;
					while(nextLevel != (1U << k)) -- k;
					_subtrees[k].push_back(make_pair(nextL, ix));
					nextL = ix + 2;
					nextLevel = 0;
					nextMiddle = -1;
				} else if(nextLevel < f) {
					nextLevel = f;
					nextMiddle = ix + 1;
				}
			}
		}
		-- _currentLevel;
		return true;
	}

	int currentLevel() const { return _currentLevel; }
	int numCurrentSubtrees() const { return (int)_subtrees[_currentLevel].size(); }

	void getDfsOrder(int si, vector<DfsEntry> &ord, vector<pair<int, int> > &tmpStack) const {
		assert(0 <= si && si < numCurrentSubtrees());
		tmpStack.resize(_tour.size() / 2 + 2);
		pair<int, int> subtree = _subtrees[_currentLevel][si];
		int L = subtree.first, R = subtree.second;
		ord.clear();
		ord.push_back(DfsEntry(VertexAndEdge((Vertex)(VertexAndEdge)_tour[R - 1], EdgeAttr()), -1));
		int sp = 1;
		tmpStack[0] = make_pair(-1, -1);
		tmpStack[sp ++] = make_pair(_tour[R - 1].id, 0);
		for(int tx = L; tx < R - 1; ++ tx) {
			int id = _tour[tx].id;
			if(id == tmpStack[sp - 2].first) {
				-- sp;
			} else {
				int px = tmpStack[sp - 1].second;
				int ix = (int)ord.size();
				tmpStack[sp ++] = make_pair(id, ix);
				ord.push_back(DfsEntry(_tour[tx], px));
			}
		}
	}

	void debugShow() const {
		cerr << "level " << _currentLevel << ":\n";
		const vector<pair<int, int> > &currentSubtrees = _subtrees[_currentLevel];
		for(int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			if(L == R)
				cerr << "[" << (L == 0 ? 0 : _tour[L - 1].id) << "]";
			for(int ix = L; ix < R; ++ ix) {
				cerr << _tour[ix].id << ", ";
			}
			cerr << '\n';
		}
	}

private:
	static void eulerTour(
		const vector<int> &t_ord, const vector<int> &t_parent,
		const vector<VertexAttr> &vertexAttrs,
		const vector<EdgeAttr> &upEdgeAttrs,
		const vector<EdgeAttr> &downEdgeAttrs,
		const vector<unsigned> &f, vector<TourEntry> &tour) {
		int n = (int)t_ord.size();
		tour.clear(); tour.reserve((n - 1) * 2 + 1);
		int root = t_ord[0], i = root;
		//a kind of sentinel
		tour.push_back(TourEntry(Vertex(root, vertexAttrs[root]), EdgeAttr(), f[root]));
		for(int ix = 1; ix <= n; ++ ix) {
			int p = ix < n ? t_parent[t_ord[ix]] : root;
			while(i != p) {
				EdgeAttr w = upEdgeAttrs[i];
				i = t_parent[i];
				tour.push_back(TourEntry(Vertex(i, vertexAttrs[i]), w, f[i]));
			}
			if(ix < n) {
				i = t_ord[ix];
				EdgeAttr w = downEdgeAttrs[i];
				tour.push_back(TourEntry(Vertex(i, vertexAttrs[i]), w, f[i]));
			}
		}
		assert(tour.size() == (n - 1) * 2 + 1);
	}

private:
	int _currentLevel;
	vector<TourEntry> _tour;
	vector<vector<pair<int, int> > > _subtrees;
};

class NearestMarkedNeighborOnTree {
	typedef int Weight;
	typedef int Dist;
	struct VertexAttr {};
	struct EdgeAttr {
		Weight weight;
		EdgeAttr() {}
		EdgeAttr(Weight weight) : weight(weight) {}
	};
	typedef CentroidDecomposition<VertexAttr, EdgeAttr> CD;

	struct NodeInfo {
		int root;
		Dist depth;
	};

public:
	void init(const vector<int> &t_ord, const vector<int> &t_parent, const vector<Weight> &t_weight) {
		int n = (int)t_parent.size();
		vector<EdgeAttr> edgeAttrs(t_weight.begin(), t_weight.end());
		cd.init(t_ord, t_parent, vector<VertexAttr>(n), edgeAttrs, edgeAttrs);
		vector<CD::DfsEntry> ord;
		vector<pair<int, int>> tmpStack;
		vector<Dist> depth;
		nodes.assign(cd.currentLevel() + 1, vector<NodeInfo>(n, NodeInfo{-1, 0}));
		do {
			int lv = cd.currentLevel();
			rep(si, cd.numCurrentSubtrees()) {
				cd.getDfsOrder(si, ord, tmpStack);
				depth.resize(ord.size());
				int root = ord[0].id;
				for(int ix = 0; ix != ord.size(); ++ ix) {
					const auto &entry = ord[ix];
					if(ix == 0)
						depth[ix] = 0;
					else
						depth[ix] = depth[entry.px] + entry.weight;
					nodes[lv][entry.id] = { root, depth[ix] };
				}
			}
		} while(cd.makeNextLevel());
		minDist.assign(n, numeric_limits<Dist>::max());
	}

	void mark(int u) {
		rep(lv, nodes.size()) {
			const NodeInfo &x = nodes[lv][u];
			if(x.root != -1)
				amin(minDist[x.root], x.depth);
		}
	}

	Dist query(int u) const {
		Dist res = numeric_limits<Dist>::max();
		rep(lv, nodes.size()) {
			const NodeInfo &x = nodes[lv][u];
			if(x.root != -1) {
				Dist d = minDist[x.root];
				if(d != numeric_limits<Dist>::max())
					amin(res, x.depth + d);
			}
		}
		return res;
	}

private:
	CD cd;
	vector<vector<NodeInfo>> nodes;
	vector<Dist> minDist;
};


vector<int> t_parent;
vi t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> weight(n);
		reu(i, 1, n) weight[i] = 1;
		tree_getorder(g, 0);
		NearestMarkedNeighborOnTree nmnot;
		nmnot.init(t_ord, t_parent, weight);
		nmnot.mark(0);
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int u;
				scanf("%d", &u), -- u;
				nmnot.mark(u);
			} else if(ty == 2) {
				int u;
				scanf("%d", &u), -- u;
				int ans = nmnot.query(u);
				printf("%d\n", ans);
			} else abort();
		}
	}
	return 0;
}