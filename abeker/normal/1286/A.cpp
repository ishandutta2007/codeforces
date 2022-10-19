#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N;
int perm[MAXN];
int dp[MAXN][MAXN][MAXN][2];

int rec(int pos, int even, int odd, int parity) {
	int &ref = dp[pos][even][odd][parity];
	if (ref != -1)
		return ref;
	if (!pos)
		return ref = 0;
	ref = MAXN;
	if (perm[pos] && perm[pos] % 2 != parity)
		return ref;
	int e = !perm[pos] && !parity;
	int o = !perm[pos] && parity;
	if (even < e || odd < o)
		return ref;
	for (int i = 0; i < 2; i++)
		ref = min(ref, rec(pos - 1, even - e, odd - o, i) + (i != parity));
	return ref;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", perm + i);
		
	int cnt[2] = {0};
	for (int i = 1; i <= N; i++)
		cnt[i % 2]++;
	for (int i = 1; i <= N; i++)
		if (perm[i])
			cnt[perm[i] % 2]--;
	
	memset(dp, -1, sizeof dp);
	
	int ans = MAXN;
	for (int i = 0; i < 2; i++)
		ans = min(ans, rec(N, cnt[0], cnt[1], i));
		
	printf("%d\n", ans);
	
	return 0;
}