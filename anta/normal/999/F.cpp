#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }
int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> cs(n * k);
		for (int i = 0; i < n * k; ++ i)
			scanf("%d", &cs[i]);
		vector<int> fs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &fs[i]);
		vector<int> hs(k + 1);
		for (int i = 1; i <= k; ++ i)
			scanf("%d", &hs[i]);
		map<int, int> cardCount;
		map<int, int> playerCount;
		for (int c : cs) ++ cardCount[c];
		for (int f : fs) ++ playerCount[f];
		int ans = 0;
		for(auto cc : cardCount) {
			int m = cc.second, p = playerCount[cc.first];
			vector<int> dp(m + 1, 0);
			for (int t = 0; t < p; ++ t) {
				for (int i = m; i >= 0; -- i) {
					int x = dp[i];
					for (int j = 0; j <= k; ++ j) if(i + j <= m)
						amax(dp[i + j], x + hs[j]);
				}
			}
			ans += dp[m];
		}
		printf("%d\n", ans);
	}
}