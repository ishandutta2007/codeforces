#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MOD = 998244353;

struct fenwick {
	int f[MAXN], cnt[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
		memset(cnt, 0, sizeof cnt);
	}
	void update(int x, int val) {
		cnt[x] += val;
		for (; x < MAXN; x += x & -x)
			f[x] += val;
	}
	int get(int x, int y) {
		int res = -(cnt[y] && y <= x);
		for (; x; x -= x & -x)
			res += f[x];
		return res;
	}
};

int N;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", a[i] + j);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

void init() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++)
			dp[i][j] = add(mul(i - j, dp[i - 1][j]), mul(j, dp[i - 1][j - 1]));
		if (i > 1)
			dp[i][i] = mul(i - 1, add(dp[i - 1][i - 1], dp[i - 2][i - 2]));	
	}
}

int solve() {
	int sol = 0, pot = 1;
	for (int i = N; i; i--) {
		vector <bool> lower(N + 1, false);
		vector <bool> upper(N + 1, false);
		fenwick yes, no;
		int inter = 0;
		for (int j = N; j; j--) {
			int curr = mul(no.get(a[i][j] - 1, a[i - 1][j]), dp[N - j][inter + upper[a[i][j]]]);
			curr = add(curr, mul(yes.get(a[i][j] - 1, a[i - 1][j]), dp[N - j][inter + upper[a[i][j]] - 1]));
			sol = add(sol, mul(curr, pot));
			
			if (lower[a[i - 1][j]]) {
				no.update(a[i - 1][j], -1);
				yes.update(a[i - 1][j], 1);
				inter++;
			}
			if (upper[a[i][j]]) {
				yes.update(a[i][j], 1);
				inter++;
			}
			else
				no.update(a[i][j], 1);
				
			upper[a[i - 1][j]] = true;
			lower[a[i][j]] = true;
		}
		
		pot = mul(pot, dp[N][N]);
	}
	
	return sol;
}

int main() {
	load();
	init();
	printf("%d\n", solve());
	return 0;
}