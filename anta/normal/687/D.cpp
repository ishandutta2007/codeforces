#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


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

struct Edge {
	int i;
	int u, v;
};

int main() {
	int n; int m; int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		vpii weights(m), pairs(m);
		rep(i, m) {
			int u; int v; int w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			weights[i] = make_pair(w, i);
			pairs[i] = make_pair(u, v);
		}
		sort(weights.begin(), weights.end());
		vector<Edge> edges(m);
		rep(i, m) {
			int ei = weights[m - 1 - i].second;
			edges[i] = Edge{ ei, pairs[ei].first, pairs[ei].second };
		}
		vector<vi> ccs(n);
		vector<int> root(n), color(n);
		rep(i, n)
			ccs[i].reserve(n);
		rep(ii, q) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l;
			rep(i, n) {
				ccs[i].assign(1, i);
				root[i] = i;
				color[i] = 0;
			}
			int ans = -1;
			rep(ix, m) {
				const Edge &e = edges[ix];
				if(e.i < l || r <= e.i) continue;
				bool samecol = color[e.u] == color[e.v];
				int x = root[e.u], y = root[e.v];
				if(x != y) {
					vi &v = ccs[x], &w = ccs[y];
					if(v.size() < w.size()) {
						swap(x, y);
						v.swap(w);
					}
					for(int a : w) {
						root[a] = x;
						color[a] ^= samecol ? 1 : 0;
					}
					v.insert(v.end(), w.begin(), w.end());
					w.clear();
					ccs[x].swap(v);
				} else if(samecol) {
					ans = weights[m - 1 - ix].first;
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}