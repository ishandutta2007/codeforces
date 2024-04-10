#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline int dec(int x, int y) {
	return max(y - x + 1, 0);
}

void solve() {
	memset(dp, INF, sizeof dp);
	memset(pref, INF, sizeof pref);
	
	int K = (N + 1) / 2;
	for (int i = 0; i <= N; i++)
		dp[0][i] = pref[0][i] = 0;
		
	for (int k = 1; k <= K; k++)
		for (int i = 1; i <= N; i++) {
			int rig = i < N ? dec(a[i], a[i + 1]) : 0;
			int lft = 0;
			if (i == 1)
				lft = k > 1 ? INF : 0;
			else if (i == 2)
				lft = k > 1 ? INF : dec(a[i], a[i - 1]);
			else 
				lft = min(pref[k - 1][i - 3] + dec(a[i], a[i - 1]), k > 1 ? dp[k - 1][i - 2] - dec(a[i - 2], a[i - 1]) + dec(min(a[i], a[i - 2]), a[i - 1]) : INF);
			dp[k][i] = lft + rig;
			pref[k][i] = min(pref[k][i - 1], dp[k][i]);
		}
		
	for (int k = 1; k <= K; k++)
		printf("%d ", pref[k][N]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}