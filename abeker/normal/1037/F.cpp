#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, K;
pii p[MAXN];
int dad[MAXN], sz[MAXN];
bool bio[MAXN];
int dp[MAXN];
int cnt;

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)	
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	cnt = add(cnt, add(dp[sz[x] + sz[y]], -add(dp[sz[x]], dp[sz[y]])));
	if (sz[x] > sz[y])
		swap(x, y);
	dad[x] = y;
	sz[y] += sz[x];
}

int solve() {
	for (int i = 1; i <= N; i++)  {
		dp[i] = dp[i - 1];
		if (i >= K)
			dp[i] = add(dp[i], (i - K) / (K - 1) + 1);
	}
		
	sort(p + 1, p + N + 1);
	
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		sz[i] = 1;
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		int old = cnt;
		int pos = p[i].second;
		if (bio[pos - 1])
			join(pos - 1, pos);
		if (bio[pos + 1])
			join(pos, pos + 1);
		sol = add(sol, mul(add(cnt, -old), p[i].first));
		bio[pos] = true;
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}