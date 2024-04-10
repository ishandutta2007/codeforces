#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
const int MAXM = 10000005;

int N, K;
int a[MAXN];
int dp[MAXM];
int mx;

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

bool check(int val) {
	for (int i = 1; i <= mx; i++)
		dp[i] = max((int)(i >= val), dp[i / 2] + dp[(i + 1) / 2]);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += dp[a[i]];
		if (cnt >= K)
			return true;
	}
	return false;
}

int solve() {
	mx = *max_element(a, a + N);
	int lo = 1, hi = mx;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(mid))
			lo = mid;
		else 
			hi = mid - 1;
	}
	return check(lo) ? lo : -1;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}