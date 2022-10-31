#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

vector<int> t_parent;
vi t_seq; vector<bool> t_sign;
vector<int> t_left, t_right;

void tree_signedeulertour(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_left.assign(n, -1);
	t_right.assign(n, -1);
	t_seq.assign(n * 2, -1);
	t_sign.assign(n * 2, false);
	int pos = 0;

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		if (i < 0) {
			i = -i - 1;
			t_seq[pos] = i;
			t_sign[pos] = true;
			pos ++;
			t_right[i] = pos;
			continue;
		}
		t_left[i] = pos;
		t_seq[pos] = i;
		t_sign[pos] = false;
		pos ++;

		stk.push_back(-(i + 1));
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

vector<int> sqrtSort(const vector<pair<int, int> > &q, const int S) {
	int n = q.size();
	vector<pair<pair<int, int>, int>> list(n);
	for (int i = 0; i < n; i ++) {
		int b = q[i].first / S;
		list[i] = make_pair(make_pair(b, b % 2 == 0 ? q[i].second : -q[i].second), i);
	}
	sort(list.begin(), list.end());
	vector<int> res(n);
	for (int i = 0; i < n; i ++)
		res[i] = list[i].second;
	return res;
}

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

bool naivegetpath(int i, int p, int t, const vector<vi> &g, vi &path) {
	bool r = false;
	if (i == t) {
		r = true;
	} else {
		for (int j : g[i]) if (j != p)
			r = r || naivegetpath(j, i, t, g, path);
	}
	if (r)
		path.push_back(i);
	return r;
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> ss(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &ss[i]);
		vector<int> fs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &fs[i]);
		vector<int> values = fs;
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		for (vector<int>::iterator it = fs.begin(); it != fs.end(); ++ it)
			*it = lower_bound(values.begin(), values.end(), *it) - values.begin();
		int X = (int)values.size();
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_signedeulertour(g, 0);
		SchieberVishkinLCA lca;
		vector<int> t_ord;
		rep(ix, n * 2) if (!t_sign[ix])
			t_ord.push_back(t_seq[ix]);
		lca.build(t_ord, t_parent, 0);
		int q;
		scanf("%d", &q);
		vpii queries(q);
		vector<int> addv(q, -1);
		rep(qi, q) {
			int a; int b;
			scanf("%d%d", &a, &b), -- a, -- b;
			if (t_left[a] > t_left[b]) swap(a, b);
			int c = lca.query(a, b);
			if (c == a || c == b) {
				queries[qi] = { t_left[a], t_left[b] };
				addv[qi] = -1;
			} else {
				queries[qi] = { t_right[a] - 1, t_left[b] };
				addv[qi] = c;
			}
		}
		vector<int> counts(X * 2, 0);
		long long curAns = 0;
		auto actuallyAdd = [&](int s, int f, int sign) {
			int t = counts[f * 2 + s];
			int p = counts[f * 2 + (1 - s)];
			curAns += sign * p;
			counts[f * 2 + s] = t + sign;
		};
		vector<int> dups(n, 0);
		auto add = [&dups, &ss, &fs, actuallyAdd](int ix, int sign) {
			int i = t_seq[ix];
			int d = dups[i] += sign;
			actuallyAdd(ss[i], fs[i], d % 2 != 0 ? 1 : -1);
		};
		auto ord = sqrtSort(queries, 300);
		int L = 0, R = -1;
		vector<ll> ans(q, -1);
		for (int qi : ord) {
			int qL = queries[qi].first, qR = queries[qi].second;
			while (R < qR)
				add(++ R, +1);
			while (L > qL)
				add(-- L, +1);
			while (R > qR)
				add(R --, -1);
			while (L < qL)
				add(L ++, -1);
			int c = addv[qi];
			if (c != -1)
				actuallyAdd(ss[c], fs[c], 1);
			ans[qi] = curAns;
			if (c != -1)
				actuallyAdd(ss[c], fs[c], -1);
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}