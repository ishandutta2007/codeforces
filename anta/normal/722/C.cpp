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
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		vector<ll> sum(n, 0);
		vector<bool> isd(n, true);
		UnionFind uf; uf.init(n);
		ll cur = 0;
		auto merge = [&](int i, int j) {
			if(isd[i] || isd[j]) return;
			int x = uf.root(i), y = uf.root(j);
			if(x == y) return;
			uf.unionSet(x, y);
			int z = uf.root(x);
			sum[z] = sum[x] + sum[y];
			amax(cur, sum[z]);
		};
		vector<ll> ans(n);
		for(int i = n - 1; i >= 0; -- i) {
			ans[i] = cur;
			int j = p[i];
			isd[j] = false;
			sum[j] = a[j];
			amax(cur, a[j]);
			if(j + 1 < n)
				merge(j, j + 1);
			if(j > 0)
				merge(j, j - 1);
		}
		for(int i = 0; i < n; ++ i)
			printf("%lld\n", ans[i]);
	}
	return 0;
}