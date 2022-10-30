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
	int n; int m; int W;
	while(~scanf("%d%d%d", &n, &m, &W)) {
		vector<int> w(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &w[i]);
		vector<int> b(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &b[i]);
		UnionFind uf; uf.init(n);
		rep(i, m) {
			int x; int y;
			scanf("%d%d", &x, &y), -- x, -- y;
			uf.unionSet(x, y);
		}
		vector<vi> ccs(n);
		rep(i, n)
			ccs[uf.root(i)].push_back(i);
		vector<int> dp(W + 1), ndp;
		rep(i, n) if(uf.root(i) == i) {
			auto &&v = ccs[i];
			int totalw = 0, totalb = 0;
			for(int j : v) {
				totalw += w[j];
				totalb += b[j];
			}
			ndp = dp;
			for(int k = W - totalw; k >= 0; -- k)
				amax(ndp[k + totalw], dp[k] + totalb);
			for(int j : v) {
				for(int k = W - w[j]; k >= 0; -- k)
					amax(ndp[k + w[j]], dp[k] + b[j]);
			}
			dp.swap(ndp);
		}
		int ans = *max_element(dp.begin(), dp.end());
		printf("%d\n", ans);
	}
	return 0;
}