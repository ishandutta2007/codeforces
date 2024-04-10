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

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		UnionFind uf, uf2;
		uf.init(n * 2);
		uf2.init(n);
		rep(i, m) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			uf.unionSet(u, n + v);
			uf.unionSet(v, n + u);
			uf2.unionSet(u, v);
		}
		bool ok = true;
		rep(i, n)
			ok &= !uf.findSet(i, n + i);
		if(!ok) {
			puts("-1");
			continue;
		}
		vi v[2];
		rep(i, n)
			v[!uf.findSet(i, uf2.root(i))].push_back(i);
		rep(k, 2) {
			printf("%d\n", (int)v[k].size());
			for(int i = 0; i < (int)v[k].size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", v[k][i] + 1);
			}
			puts("");
		}
	}
	return 0;
}