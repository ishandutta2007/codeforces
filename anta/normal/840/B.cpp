#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<int> d(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &d[i]);
		vector<pair<int, int> > edges(m);
		map<pii, int> eindex;
		for (int i = 0; i < m; ++ i) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			edges[i] = { u,v };
			eindex[minmax(u, v)] = i;
		}
		int arb = -1;
		vector<int> odd;
		rep(i, n) {
			if (d[i] == -1 && arb == -1)
				arb = i;
			if (d[i] == 1)
				odd.push_back(i);
		}
		if (odd.size() % 2 != 0) {
			if (arb == -1) {
				puts("-1");
				continue;
			}
			d[arb] = 1;
			odd.push_back(arb);
		}
		vector<vi> g(n);
		UnionFind uf; uf.init(n);
		for (auto e : edges) if (uf.unionSet(e.first, e.second)) {
			g[e.first].push_back(e.second);
			g[e.second].push_back(e.first);
		}
		tree_getorder(g, 0);
		vector<int> add(n);
		rep(k, odd.size() / 2) {
			int a = odd[k * 2], b = odd[k * 2 + 1];
			add[a] ^= 1;
			add[b] ^= 1;
		}
		vector<int> sum(add.begin(), add.end());
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			sum[p] ^= sum[i];
		}
		vi ans;
		reu(i, 1, n) if (sum[i] % 2 != 0) {
			ans.push_back(eindex[minmax(t_parent[i], i)]);
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}