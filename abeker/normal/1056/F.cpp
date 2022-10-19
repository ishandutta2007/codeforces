#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> pii;

const int MAXN = 105;
const ld INF = 1e18;

int N;
ld C, T;
pii p[MAXN];
ld dp[MAXN][MAXN][10 * MAXN];
ld pot[MAXN];

void load() {
	scanf("%d%Lf%Lf", &N, &C, &T);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
}

bool check(int k, ld sum) {
	if (sum * C > 1)
		sum = 2 * sqrt(sum / C) - 1 / C;
	return sum + 10 * k <= T;
}

int solve() {
	sort(p + 1, p + N + 1, greater <pii> ());
	
	pot[0] = 1;
	for (int i = 1; i <= N; i++)
		pot[i] = pot[i - 1] * 10 / 9;
		
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= 10 * j; k++) {
				dp[i][j][k] = j < i ? dp[i - 1][j][k] : INF;
				int rem = k - p[i].second;
				if (j && rem >= 0 && rem <= 10 * (j - 1))
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][rem] + pot[j] * p[i].first);
			}
	
	int sol = 0;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= 10 * i; j++)
			if (check(i, dp[N][i][j])) 
				sol = max(sol, j);
	
	return sol;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		printf("%d\n", solve());
	}
	return 0;
}