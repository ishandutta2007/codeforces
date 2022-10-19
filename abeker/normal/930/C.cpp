#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct fenwick {
	int f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x, int val) {
		for (x++; x < MAXN; x += x & -x)
			f[x] = max(f[x], val);
	}
	int get(int x) {
		int res = 0;
		for (x++; x; x -= x & -x)
			res = max(res, f[x]);
		return res;
	}
};

int N, M;
int cnt[MAXN];
fenwick incr, decr;
int dp[MAXN];

void load() {
	scanf("%d%d", &M, &N);
	while (M--) {
		int l, r;
		scanf("%d%d", &l, &r);
		cnt[l]++;
		cnt[r + 1]--;
	}
}

int solve() {
	for (int i = 1; i <= N; i++)
		cnt[i] += cnt[i - 1];
	
	for (int i = 1; i <= N; i++) {
		dp[i] = incr.get(cnt[i]) + 1;
		incr.update(cnt[i], dp[i]);
	}
	
	int sol = 0;
	for (int i = N; i; i--) {
		int tmp = decr.get(cnt[i]) + 1;
		decr.update(cnt[i], tmp);
		sol = max(sol, dp[i] + tmp - 1);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}