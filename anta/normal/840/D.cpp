#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct KMajority {
	static const int K = 5;
	int d = 0;
	array<pair<int, int>, K> b;
	void add(int x, int cnt) {
		assert(cnt > 0);
		rep(i, d) if (b[i].first == x) {
			b[i].second += cnt;
			return;
		}
		b[d ++] = { x, cnt };
		if (d == K) {
			int mincnt = cnt;
			rep(i, d - 1)
				amin(mincnt, b[i].second);
			for(int i = 0; i < d; ) {
				if ((b[i].second -= mincnt) == 0)
					swap(b[i], b[-- d]);
				else
					++ i;
			}
			assert(d < K);
		}
	}
	void merge(const KMajority &that) {
		rep(j, that.d)
			add(that.b[j].first, that.b[j].second);
	}
};

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		int nNodes = 1;
		while (nNodes < n) nNodes *= 2;
		vector<KMajority> nodes(nNodes * 2);
		rep(i, n)
			nodes[nNodes + i].add(a[i], 1);
		for (int i = nNodes - 1; i > 0; -- i) {
			nodes[i] = nodes[i * 2];
			nodes[i].merge(nodes[i * 2 + 1]);
		}
		vector<vi> indices(*max_element(a.begin(), a.end()) + 1);
		rep(i, n)
			indices[a[i]].push_back(i);
		ll sum = 0;
		rep(ii, q) {
			int L; int R; int K;
			scanf("%d%d%d", &L, &R, &K), -- L;
			KMajority km;
			for (int l = L + nNodes, r = R + nNodes; l < r; l >>= 1, r >>= 1) {
				if (l & 1) km.merge(nodes[l ++]);
				if (r & 1) km.merge(nodes[-- r]);
			}
			int ans = INF;
			rep(j, km.d) {
				int x = km.b[j].first;
				const auto &v = indices[x];
				int cnt = (int)(lower_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L));
				if (cnt * K > R - L)
					amin(ans, x);
			}
			printf("%d\n", ans == INF ? -1 : ans);
		}
	}
	return 0;
}