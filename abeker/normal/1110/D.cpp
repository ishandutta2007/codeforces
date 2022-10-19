#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int N, M;
int cnt[MAXN];
int dp[MAXN][5][3];

int rec(int pos, int a, int b) {
	int &ref = dp[pos][a][b];
	if (ref != -INF)
		return ref;
	
	int bound = min(min(cnt[pos] - a, cnt[pos + 1] - b), 2);
	if (pos >= M - 1)
		bound = min(bound, 0);
		
	for (int i = 0; i <= bound; i++)
		ref = max(ref, (cnt[pos] - a - i) / 3 + i + rec(pos + 1, b + i, i));
	
	return ref;
}

int main() {
	scanf("%d%d", &N, &M);
	while (N--) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -INF;
				
	dp[M + 1][0][0] = 0;
	
	printf("%d\n", rec(1, 0, 0));
		
	return 0;
}