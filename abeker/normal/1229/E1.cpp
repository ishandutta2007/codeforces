#include <bits/stdc++.h>
using namespace std;

#define bc __builtin_popcount

const int MAXN = 6;
const int MAXHALVES = 20;
const int MOD = 1e9 + 7;

int N;
int prob[MAXN][MAXN];
int idx[1 << MAXN];
vector <int> adj[MAXN];
int lft[1 << MAXHALVES];
int dp[MAXHALVES + 1][1 << MAXHALVES];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int x;
			scanf("%d", &x);
			prob[i][j] = mul(x, pot(100, MOD - 2));
		}
}

void rec(int st, int pos, int en, int flip, int hood, int &mask) {
	if (bc(hood) < pos - st)
		return;
	if (pos == en) {
		if (flip)
			hood ^= (1 << N) - 1;
		mask |= 1 << idx[hood];
		return;
	}
	for (auto it : adj[pos])
		rec(st, pos + 1, en, flip, hood | 1 << it, mask);
}

void gen(int lo, int hi, int flip, int *arr) {
	for (int i = 0; i < 1 << N * (hi - lo); i++) {
		int curr = 1;
		for (int j = lo; j < hi; j++) {
			adj[j].clear();
			for (int k = 0; k < N; k++)
				if (i >> N * (j - lo) + k & 1) {
					adj[j].push_back(k);
					curr = mul(curr, prob[j][k]);
				}
				else 
					curr = mul(curr, add(1, -prob[j][k]));
		}
		int which = 0;
		rec(lo, lo, hi, flip, 0, which);
		arr[which] = add(arr[which], curr);
	}
}

int solve() {
	int half = N / 2, halves = 0;
	for (int i = 0; i < 1 << N; i++)
		if (bc(i) == half) 
			idx[i] = halves++;
	
	gen(0, half, 0, lft);
	gen(half, N, 1, dp[halves]);
	
	int all = (1 << halves) - 1;
	for (int i = halves - 1; i >= 0; i--) 
		for (int j = 0; j <= all; j++) {
			dp[i][j] = dp[i + 1][j & (all ^ 1 << i)];
			if (j >> i & 1)
				dp[i][j] = add(dp[i][j], dp[i + 1][j]);
		}
		
	int sol = 0;
	for (int i = 0; i <= all; i++)
		sol = add(sol, mul(lft[i], dp[0][i ^ all]));
	
	return add(1, -sol);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}