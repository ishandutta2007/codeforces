#include <cstdio>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int N, A, B, K;

void load() {
	scanf("%d%d%d%d", &N, &A, &B, &K);
}

int dp[MAXN], nxt[MAXN];

inline void add(int &x, int y) {
	x += y;
	if (x < 0) x += MOD;
	else if (x >= MOD) x -= MOD;
}

void inc(int lo, int hi, int val) {
	if (lo < 1) lo = 1;
	if (hi > N) hi = N;
	if (lo > hi) return;
	add(nxt[lo], val);
	add(nxt[hi + 1], -val);
}

void update(int pos) {
	if (pos < B) {
		inc(2 * pos + 1 - B, pos - 1, dp[pos]);
		inc(pos + 1, B - 1, dp[pos]);
	}
	else if (pos > B) {
		inc(B + 1, pos - 1, dp[pos]);
		inc(pos + 1, 2 * pos - 1 - B, dp[pos]);  
	}
}

int solve() {
	dp[A] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) 
			update(j);
		for (int j = 1; j <= N; j++) {
			dp[j] = dp[j - 1];
			add(dp[j], nxt[j]);
			nxt[j] = 0;
		}
	}
	int sol = 0;
	for (int i = 1; i <= N; i++) 
		add(sol, dp[i]);
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}