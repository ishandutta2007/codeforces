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

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<int> depth(t_ord.size());
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}
		vector<int> subtsize(t_ord.size(), 1);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		auto calc = [](int x) {
			return (ll)x * (x - 1);
		};
		vector<ll> childrenCalcSum(n, 0);
		ll curSum = 0;
		rep(i, n) {
			for (int j : g[i]) if(j != t_parent[i])
				childrenCalcSum[i] += calc(subtsize[j]);
			curSum += childrenCalcSum[i];
			curSum += calc(n - subtsize[i]);
		}
		vector<int> parent = t_parent;
		UnionFind uf; uf.init(n);
		int Q;
		scanf("%d", &Q);
		for(int ii = 0; ; ++ ii) {
			{
				ll ans = (ll)n * (n - 1) * (n - 2);
				ans -= curSum;
				printf("%lld\n", ans);
			}
			if (ii == Q) break;
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;

			int x = uf.root(u);
			int y = uf.root(v);
			while (x != y) {
				if (depth[x] < depth[y])
					swap(x, y);
				int p = uf.root(parent[x]);
				int xsize = uf.size(x);
				int psize = uf.size(p);
				int subtsizex = subtsize[x];
				int subtsizep = subtsize[p];
				ll childrenCalcSumx = childrenCalcSum[x];
				ll childrenCalcSump = childrenCalcSum[p];

				curSum -= xsize * calc(n - subtsizex);
				curSum -= psize * calc(n - subtsizep);
				curSum += (xsize + psize) * calc(n - subtsizep);

				curSum -= psize * calc(subtsizex);
				curSum += psize * childrenCalcSumx;
				curSum += xsize * (childrenCalcSump - calc(subtsizex));

				uf.unionSet(x, p);
				x = uf.root(x);

				parent[x] = parent[p];
				depth[x] = depth[p];
				subtsize[x] = subtsize[p];
				childrenCalcSum[x] = childrenCalcSumx + childrenCalcSump - calc(subtsizex);

				y = uf.root(y);
			}
		}
	}
	return 0;
}