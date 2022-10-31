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
		vector<int> r(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &r[i]);
		vector<vi> doors(n);
		rep(i, m) {
			int x;
			scanf("%d", &x);
			rep(j, x) {
				int t;
				scanf("%d", &t), -- t;
				doors[t].push_back(i);
			}
		}
		rep(i, n)
			assert(doors[i].size() == 2);
		UnionFind uf;
		uf.init(m * 2);
		rep(i, n) {
			int x = doors[i][0], y = doors[i][1];
			if (r[i] == 1) {
				uf.unionSet(x * 2 + 0, y * 2 + 0);
				uf.unionSet(x * 2 + 1, y * 2 + 1);
			} else {
				uf.unionSet(x * 2 + 0, y * 2 + 1);
				uf.unionSet(x * 2 + 1, y * 2 + 0);
			}
		}
		bool ans = true;
		rep(x, m)
			ans &= !uf.findSet(x * 2 + 0, x * 2 + 1);
		puts(ans ? "YES" : "NO");
	}
	return 0;
}