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

vector<int> t_parent;
vi t_ord;

template<typename T>
void wtree_getorder(const vector<vector<pair<int, T> > > &gw, int root, vector<T> &t_weight) {
	int n = (int)gw.size();
	t_parent.assign(n, -1);
	t_ord.clear();
	t_weight.assign(n, T());

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)gw[i].size() - 1; j >= 0; j --) {
			int c = gw[i][j].first;
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				t_weight[c] = gw[i][j].second;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vi> g(n + 1);
		vector<vpii> gw(n + 1);
		rep(i, n) {
			int p; int t;
			scanf("%d%d", &p, &t), -- p;
			assert(p < i);
			if (p < 0) {
				g[n].push_back(i);
				gw[n].emplace_back(i, 2);
			} else {
				assert(t == 0 || t == 1);
				g[p].push_back(i);
				gw[p].emplace_back(i, t);
			}
		}
		vector<int> type;
		wtree_getorder(gw, n, type);
		vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			cnt1[i] = cnt1[p] + (type[i] == 0 || type[i] == 2);
			cnt2[i] = cnt2[p] + (type[i] == 1 || type[i] == 2);
		}
		SchieberVishkinLCA lca;
		lca.build(t_ord, t_parent, n);
		int q;
		scanf("%d", &q);
		for (int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				int u; int v;
				scanf("%d%d", &u, &v), -- u, -- v;
				assert(0 <= u && u < n);
				assert(0 <= v && v < n);
				int w = lca.query(u, v);
				bool ans = w == u && cnt2[v] - cnt2[u] == 0;
				ans &= u != v && w != n;
				puts(ans ? "YES" : "NO");
			} else if (ty == 2) {
				int u; int v;
				scanf("%d%d", &u, &v), -- u, -- v;
				assert(0 <= u && u < n);
				assert(0 <= v && v < n);
				int w = lca.query(u, v);
				bool ans = v != w && cnt2[u] - cnt2[w] == 0 && cnt1[v] - cnt1[w] == 0;
				ans &= u != v && w != n;
				puts(ans ? "YES" : "NO");
			} else {
				abort();
			}
		}
	}
	return 0;
}