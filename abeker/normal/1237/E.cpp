#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, D;

int dfs(int x, int dep, int parity) {
	if (dep == D)
		return x % 2 && parity ? -INF : parity;
	if (x % 2) 
		return dfs(2 * x, dep + 1, 1) + dfs(2 * x + 1, dep + 1, parity) + 1;
	return dfs(2 * x + 1, dep + 1, 0) + dfs(2 * x, dep + 1, parity ^ 1) + 1;
}

int main() {
	scanf("%d", &N);

	if (N <= 2) {
		puts("1");
		return 0;
	}
	
	while ((1 << D + 1) <= N + 1)
		D++;
	
	int ans = 0;
	for (int l = 0; l < 2; l++)
		for (int r = 0; r < 2; r++)
			if (dfs(2, 1, l) + dfs(3, 1, r) == N - 1)
				ans++;
	
	printf("%d\n", ans);
	
	return 0;
}