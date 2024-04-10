#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXK = 1e2 + 5;
const int INF = 0x3f3f3f3f;

int N, K, P;
int a[MAXN];
vector <int> pos[MAXK];
int dp[MAXK][MAXK][MAXK];
int pref[MAXK][MAXK][MAXK], suff[MAXK][MAXK][MAXK];

void load() {
	scanf("%d%d%d", &N, &K, &P);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int get_nxt(int val, int idx) {
	auto it = lower_bound(pos[val].begin(), pos[val].end(), idx + 1);
	return it == pos[val].end() ? INF : *it;
}

int solve() {
	for (int i = 1; i <= N; i++) {
		a[i] = (a[i] + a[i - 1]) % P;
		pos[a[i]].push_back(i);
	}
	
	memset(dp, INF, sizeof dp);
	memset(pref, INF, sizeof pref);
	memset(suff, INF, sizeof suff);
	for (int i = 0; i < P; i++) 
		dp[0][0][i] = pref[0][0][i] = suff[0][0][i] = 0;
		
	int sol = INF;
	for (int i = 1; i < K; i++)
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < P; j++) {
				suff[i][k][j] = pref[i][k][j] = dp[i][k][j] = get_nxt(j, min(pref[i - 1][k][j], k ? suff[i - 1][k - 1][j + 1] : INF));
				if (j)
					pref[i][k][j] = min(pref[i][k][j], pref[i][k][j - 1]);
				if (i == K - 1 && dp[i][k][j] < N)
					sol = min(sol, k + (j > a[N]));
			}
			for (int j = P - 1; j >= 0; j--)
				suff[i][k][j] = min(suff[i][k][j], suff[i][k][j + 1]);
		}
	
	return a[N] + sol * P;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}