#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 12;
const int MAXM = 2005;
const int INF = 2e9;

int N, M;
int a[MAXN][MAXM];
int sum[MAXN * MAXN + 5][1 << MAXN];
int dp[MAXN * MAXN + 5][1 << MAXN];
vector <int> imp;
int col[MAXM];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", a[i] + j);
}

inline int rot(int mask, int k) {
	return (mask >> k) | ((mask & ((1 << k) - 1)) << N - k);
}

int rec(int x, int mask) {
	int &ref = dp[x][mask];
	if (ref != -1)
		return ref;
	if (!x)
		return ref = mask ? -INF : 0;
	ref = -INF;
	for (int j = 0; j < N; j++) {
		int tmp = rot(col[imp[x - 1]], j) & mask;
		for (int sub = tmp; ; sub = (sub - 1) & tmp) {
			ref = max(ref, rec(x - 1, mask ^ sub) + sum[x - 1][rot(sub, N - j)]);
			if (!sub)
				break;
		}
	}
	return ref;
}

int solve() {
	memset(col, 0, sizeof col);
	memset(sum, 0, sizeof sum);
	memset(dp, -1, sizeof dp);
	imp.clear();
	
	vector <pair <int, pii>> all;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			all.push_back({a[i][j], {i, j}});
	
	sort(all.begin(), all.end(), greater <pair <int, pii>> ());

	//all.resize(min((int)all.size(), N * N + 1));
	
	for (auto it : all)
		col[it.second.second] |= 1 << it.second.first;
	
	for (int i = 0; i < M; i++)
		if (col[i])
			imp.push_back(i);
	
	int sz = imp.size();
	for (int i = 0; i < sz; i++)
		for (int sub = 0; sub < 1 << N; sub++) 
			for (int j = 0; j < N; j++)
				if (sub >> j & 1)
					sum[i][sub] += a[j][i];
	
	return rec(sz, (1 << N) - 1);
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