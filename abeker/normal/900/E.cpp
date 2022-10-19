#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
char s[MAXN];
int dp[MAXN], opt[MAXN];
int pref[MAXN];
int cnt[MAXN][2];

void load() {
	scanf("%d%s%d", &N, s + 1, &M);
}

bool match(int x) {
	return cnt[x - M][(x - M) % 2] == cnt[x][(x - M) % 2];
}

int get(int lo, int hi) {
	return pref[hi] - pref[lo - 1];
}

int solve() {
	for (int i = 1; i <= N; i++)
		pref[i] = pref[i - 1] + (s[i] == '?');
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++)
			cnt[i][j] = cnt[i - 1][j];
		if (s[i] != '?')
			cnt[i][(s[i] - 'a') ^ (i % 2)]++;
	}
	
	for (int i = M; i <= N; i++) {
		dp[i] = dp[i - 1];
		opt[i] = opt[i - 1];
		if (match(i)) {
			int cand = dp[i - M] + 1;
			int tmp = opt[i - M] + get(i - M + 1, i);
			if (cand >= dp[i]) {
				opt[i] = cand > dp[i] ? tmp : min(tmp, opt[i]);
				dp[i] = cand;
			}
		}
	}
	
	return opt[N];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}