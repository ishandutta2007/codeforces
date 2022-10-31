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

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		UnionFind uf; uf.init(n);
		vpii edges(m);
		vi deg(n, 0);
		int loops = 0;
		rep(i, m) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			uf.unionSet(u, v);
			edges[i] = { u, v };
			if (u != v) {
				++ deg[u];
				++ deg[v];
			} else {
				++ loops;
			}
		}
		bool ok = true;
		for(auto e : edges)
			ok &= uf.findSet(e.first, edges[0].first);
		ll ans = 0;
		if (ok) {
			rep(i, n) {
				int x = deg[i];
				ans += (ll)x * (x - 1) / 2;
			}
			ans += (ll)loops * (m - loops);
			ans += (ll)loops * (loops - 1) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}