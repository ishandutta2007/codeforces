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

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};


vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n; int m; int q;
	mt19937 re;
	while (~scanf("%d%d%d", &n, &m, &q)) {
		vector<vector<int> > g(n + 1);
		UnionFind uf; uf.init(n);
		for (int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
			uf.unionSet(u, v);
		}
		rep(i, n) if (uf.root(i) == i) {
			g[n].push_back(i);
			g[i].push_back(n);
		}
		tree_getorder(g, n);
		SchieberVishkinLCA lca;
		lca.build(t_ord, t_parent, n);
		vector<int> depth(t_ord.size());
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}
		auto dist = [&](int i, int j) {
			return depth[i] + depth[j] - depth[lca.query(i, j)] * 2;
		};
		vector<vi> ccs(n);
		rep(i, n)
			ccs[uf.root(i)].push_back(i);
		vector<int> diam(n);
		vector<int> ecc(n);
		vector<vi> sorted(n);
		vector<vector<ll>> sums(n);
		rep(u, n) if(!ccs[u].empty()) {
			pii p(0, u);
			for (int j : ccs[u])
				amax(p, make_pair(dist(u, j), j));
			pii q(0, p.second);
			for (int j : ccs[u])
				amax(q, make_pair(dist(p.second, j), j));
			diam[u] = q.first;
			sorted[u].reserve(ccs[u].size());
			for (int j : ccs[u]) {
				ecc[j] = max(dist(j, p.second), dist(j, q.second));
				sorted[u].push_back(ecc[j]);
			}
			sort(sorted[u].begin(), sorted[u].end());
			sums[u].resize(sorted[u].size() + 1);
			for(int k = (int)sorted[u].size() - 1; k >= 0; -- k)
				sums[u][k] = sums[u][k + 1] + sorted[u][k];
		}
		map<pair<int, int>, double> memo;
		rep(ii, q) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			u = uf.root(u);
			v = uf.root(v);
			if (make_pair(ccs[u].size(), u) > make_pair(ccs[v].size(), v)) swap(u, v);
			if (u == v) {
				memo[{u, v}] = -1;
			} else if (!memo.count(make_pair(u, v))) {
				int base = max(diam[u], diam[v]);
				long long sum = 0;
				for (int x : sorted[u]) {
					int k = (int)(lower_bound(sorted[v].begin(), sorted[v].end(), base - 1 - x) - sorted[v].begin());
					sum += (ll)k * base;
					sum += sums[v][k];
					sum += (ll)(sorted[v].size() - k) * (x + 1);
				}
				double ans = (double)sum / ccs[u].size() / ccs[v].size();
				memo[{u, v}] = ans;
			}
			printf("%.10f\n", memo[{u, v}]);
		}
	}
	return 0;
}