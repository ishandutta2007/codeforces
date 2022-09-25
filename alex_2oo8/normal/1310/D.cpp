#include <bits/stdc++.h>

using namespace std;

const int MX = 80, MK = 11;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<> dis(0, 1);

int d[MX][MX], c[MX], dp[MK][MX];

int main() {
	int n = 80, k = 10;
	ignore = scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			ignore = scanf("%d", d[i] + j);
			//d[i][j] = rand() % 100000000;
		}
	
	int ans = 2e9;
	for (int it = 0; it < 20000; it++) {
		for (int i = 1; i < n; i++) c[i] = dis(gen);
		
		dp[0][0] = 0;
		fill(dp[0] + 1, dp[0] + n, 2e9);
		for (int i = 0; i < k; i++) {
			fill(dp[i + 1], dp[i + 1] + n, 2e9);
			for (int u = 0; u < n; u++)
				for (int v = 0; v < n; v++)
					if (c[u] != c[v])
						dp[i + 1][v] = min(dp[i + 1][v], dp[i][u] + d[u][v]);
		}
		
		ans = min(dp[k][0], ans);
	}
	
	printf("%d\n", ans);
	
	return 0;
}