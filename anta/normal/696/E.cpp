#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)

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

void get_route(const HeavyLightDecomposition &hld, int u, int v, vector<pair<int, pii> > &route) {
	route.clear();
	int w = lowest_common_ancestor(hld, u, v), wc, wp;
	hld.get(w, wc, wp);
	rep(uv, 2) {
		int c, p;
		hld.get(uv == 0 ? u : v, c, p);
		int sz = route.size();
		while(1) {
			int top = c == wc ? wp + uv : 0;
			pii q = uv == 0 ? make_pair(p + 1, top) : make_pair(top, p + 1);
			if(q.first != q.second) {
				if(uv == 1 && c == wc) {	//c
					assert(route[sz - 1].first == c);
					assert(route[sz - 1].second.first - route[sz - 1].second.second == 1);
					assert(route[sz - 1].second.first == q.first);
					route[sz - 1].second = make_pair(route[sz - 1].second.second, q.second);
				} else {
					route.push_back(make_pair(c, q));
				}
			}
			if(c == wc) break;
			hld.go_up(c, p);
		}
		if(uv == 1)
			reverse(route.begin() + sz, route.end());
	}
}


struct Sum {
	ll weight;
	int c;
	int i;
	Sum() : weight(INFL), c(-1), i(-1) {}
	Sum(ll w, int c, int i) : weight(w), c(c), i(i) {}
	Sum(const Sum &val, int pos) : Sum(val) {}
	bool operator<(const Sum &that) const {
		if(weight != that.weight)
			return weight < that.weight;
		else
			return c < that.c;
	}
	Sum &operator+=(const Sum &that) {
		amin(*this, that);
		return *this;
	}
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
typedef Sum Val;
struct Add {
	long long k;
	Add(long long k = 0) : k(k) {}
	Add &operator+=(const Add &that) { k += that.k; return *this; }
	void addToVal(Val &val, int pos) const { addToSum(val, pos, pos + 1); }
	void addToSum(Sum &sum, int left, int right) const {
		if(sum.weight != INFL)
			sum.weight += k;
	}
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<Add> add;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for(int i = n - 1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i * 2 - n], i * 2 - n) + Sum(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		for(int i = n2 - 1; i > 0; -- i)
			nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
		add.assign(n, Add());

		leftpos.resize(n); rightpos.resize(n);
		for(int i = n - 1; i >= n2; -- i) {
			leftpos[i] = i * 2 - n;
			rightpos[i] = (i * 2 + 1 - n) + 1;
		}
		for(int i = n2 - 1; i > 0; -- i) {
			leftpos[i] = leftpos[i * 2];
			rightpos[i] = rightpos[i * 2 + 1];
		}
	}
	Val get(int i) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for(int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += sum(l ++);
			if(r & 1) res += sum(-- r);
		}
		return res;
	}
	Sum getRange(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for(; i && i + (i&-i) <= j; i += i&-i)
			res += sum((n + i) / (i&-i));
		for(k = 0; i < j; j -= j&-j)
			indices[k ++] = (n + j) / (j&-j) - 1;
		while(-- k >= 0) res += sum(indices[k]);
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		leafs[i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Add &x) {
		if(i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if(l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if(r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for(l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) add[l ++] += x;
			if(r & 1) add[-- r] += x;
		}
		mergeRange(indices, k);
	}
private:
	int getIndices(int indices[], int i, int j) const {
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
		if(i >= n) return;
		add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if(i * 2 < n) {
			add[i * 2] += add[i];
			add[i * 2 + 1] += add[i];
		} else {
			add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		}
		add[i] = Add();
	}
	inline void merge(int i) {
		if(i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		propagate(i);
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};

int main() {
	int n; int m; int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		HeavyLightDecomposition hld;
		hld.build(g, 0);
		vector<pair<int, Val>> girls(m);
		rep(i, m) {
			int c;
			scanf("%d", &c), -- c;
			girls[i] = { hld.lefts[c], Val{i + 1, c + 1, i} };
		}
		sort(girls.begin(), girls.end());
		vector<int> indices(m);
		rep(i, m)
			indices[girls[i].second.i] = i;
		vector<int> offsets(n + 1);
		rep(i, n + 1) {
			offsets[i] = lower_bound(girls.begin(), girls.end(),
				make_pair(i, Val{-1, -1, -1})) - girls.begin();
		}
		SegmentTree segt;
		vector<Val> initValues(m);
		rep(i, m)
			initValues[i] = girls[i].second;
		segt.init(initValues);
		vector<pair<int, pii>> route;
		vi ans;
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int u; int v; int k;
				scanf("%d%d%d", &u, &v, &k), -- u, -- v;
				ans.clear();
				get_route(hld, u, v, route);
				for(; k > 0; -- k) {
					Sum sum;
					for(auto p : route) {
						int c = p.first, l = p.second.first, r = p.second.second;
						if(l > r) swap(l, r);
						int o = hld.offsets[c];
						int L = offsets[o + l], R = offsets[o + r];
						sum += segt.getRangeCommutative(L, R);
					}
					if(sum.weight == INFL)
						break;
					int i = sum.i;
					ans.push_back(i);
					segt.set(indices[i], Val());
				}
				printf("%d", (int)ans.size());
				rep(i, ans.size())
					printf(" %d", ans[i] + 1);
				puts("");
			} else if(ty == 2) {
				int u; int k;
				scanf("%d%d", &u, &k), -- u, -- k;
				int L = offsets[hld.lefts[u]], R = offsets[hld.rights[u]];
				segt.addToRange(L, R, Add(k));
			} else abort();
		}
	}
	return 0;
}
//