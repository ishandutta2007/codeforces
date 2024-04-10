#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
const int INF = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
	int n; int m; int K;
	while (~scanf("%d%d%d", &n, &m, &K)) {
		vector<bool> blocked(n);
		for (int i = 0; i < m; ++ i) {
			int x;
			scanf("%d", &x);
			blocked[x] = true;
		}
		vector<int> prevUnblocked(n + 1, -INF);
		for (int i = 0; i < n; ++ i)
			prevUnblocked[i + 1] = !blocked[i] ? i : prevUnblocked[i];
		vector<int> cost(K + 1);
		for (int i = 0; i < K; ++ i)
			scanf("%d", &cost[i + 1]);
		long long ans = INFL;
		for (int k = 1; k <= K; ++ k) {
			int num = 0;
			for (int i = 0; i < n; ++ num) {
				int j = prevUnblocked[i + 1] + k;
				if (j <= i) {
					num = INF;
					break;
				}
				i = j;
			}
			if (num != INF)
				amin(ans, (long long)num * cost[k]);
		}
		printf("%lld\n", ans == INFL ? -1 : ans);
	}
}