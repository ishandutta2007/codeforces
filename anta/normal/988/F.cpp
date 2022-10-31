#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	const int INF = 0x3f3f3f3f;
	int X; int n; int m;
	while (~scanf("%d%d%d", &X, &n, &m)) {
		vector<bool> rain(X);
		for (int i = 0; i < n; ++ i) {
			int l; int r;
			scanf("%d%d", &l, &r);
			for (int i = l; i < r; ++ i)
				rain[i] = true;
		}
		vector<int> weight(X + 1, INF);
		for (int i = 0; i < m; ++ i) {
			int x; int p;
			scanf("%d%d", &x, &p);
			amin(weight[x], p);
		}
		vector<int> dp, ndp(X + 2, INF);
		ndp[X + 1] = 0;
		for (int i = 0; i < X; ++ i) {
			dp.swap(ndp);
			ndp.assign(X + 2, INF);
			for (int j = 0; j < X + 2; ++ j) {
				int x = dp[j];
				if (x == INF) continue;
				for (int nj : {j, i, X + 1}) {
					if (rain[i] && nj == X + 1) continue;
					if (nj != X + 1 && weight[nj] == INF) continue;
					amin(ndp[nj], x + (nj == X + 1 ? 0 : weight[nj]));
				}
			}
		}
		int ans = *min_element(ndp.begin(), ndp.end());
		printf("%d\n", ans == INF ? -1 : ans);
	}
}