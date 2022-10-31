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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		UnionFind uf; uf.init(n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]), -- a[i];
			uf.unionSet(i, a[i]);
		}
		vector<bool> vis(n);
		vector<int> roots, modify;
		rep(i, n) if(uf.root(i) == i) {
			int j = i, p = i;
			while(!vis[j]) {
				vis[j] = true;
				p = j, j = a[j];
			}
			if(a[j] == j)
				roots.push_back(j);
			else
				modify.push_back(p);
		}
		int root = !roots.empty() ? roots[0] : modify[0];
		vector<int> ans = a;
		for(int i : roots) if(i != root)
			ans[i] = root;
		for(int i : modify)
			ans[i] = root;
		int diff = 0;
		rep(i, n) diff += a[i] != ans[i];
		assert(diff == (int)(modify.size() + roots.size()) - min(1, (int)roots.size()));
		printf("%d\n", diff);
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}