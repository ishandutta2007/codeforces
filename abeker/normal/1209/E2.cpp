#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 12;
const int MAXM = 2005;
const int INF = 2e9;

int N, M;
int a[MAXN][MAXM];
int dp[MAXN * MAXN + 5][1 << MAXN];
vector <pii> trans[MAXN * MAXN + 5][1 << MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", a[i] + j);
}

int rec(int x, int mask) {
	int &ref = dp[x][mask];
	if (ref != -1)
		return ref;
	if (!x)
		return ref = mask ? -INF : 0;
	ref = -INF;
	for (auto it : trans[x - 1][mask])
		ref = max(ref, rec(x - 1, mask ^ it.first) + it.second);
	return ref;
}

int solve() {
	memset(dp, -1, sizeof dp);
	
	vector <pair <int, pii>> all;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			all.push_back({a[i][j], {i, j}});
	
	sort(all.begin(), all.end(), greater <pair <int, pii>> ());

	all.resize(min((int)all.size(), N * N + 1));
	
	vector <int> col(M, 0);
	for (auto it : all)
		col[it.second.second] |= 1 << it.second.first;
	
	vector <int> imp;
	for (int i = 0; i < M; i++)
		if (col[i])
			imp.push_back(i);
	
	int sz = imp.size();
	for (int i = 0; i < sz; i++) {
		vector <int> opt(1 << N, -1);
		for (int sub = col[imp[i]]; ; sub = (sub - 1) & col[imp[i]]) {
			int sum = 0;
			for (int j = 0; j < N; j++)
				if (sub >> j & 1)
					sum += a[j][imp[i]];
			for (int j = 0; j < N; j++) {
				opt[sub] = max(opt[sub], sum);
				sub = (sub >> 1) | ((sub & 1) << N - 1);
			}
			if (!sub)
				break;
		}
		for (int j = 0; j < 1 << N; j++)
			trans[i][j].clear();
		for (int j = 0; j < 1 << N; j++) {
			if (opt[j] == -1)
				continue;
			int comp = j ^ (1 << N) - 1;
			for (int sub = comp; ; sub = (sub - 1) & comp) {
				trans[i][j ^ sub].push_back({j, opt[j]});
				if (!sub)
					break;
			}
		}
	}
	
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