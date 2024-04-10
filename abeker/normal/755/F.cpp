#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXN = 1000005;
const int T = 100;

int N, K;
int p[MAXN];
bool bio[MAXN];
bitset <MAXN> dp;
int need[MAXN];
int cnt[T];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

int dfs(int x) {
	if (bio[x])
		return 0;
	bio[x] = true;
	return dfs(p[x]) + 1;
}

void solve() {
	dp.set(0);
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = dfs(i);
		if (tmp < T)
			cnt[tmp]++;
		else
			dp |= dp << tmp;
		sum += tmp / 2;
	}
	
	for (int i = 1; i < T; i++) 
		for (int j = 0; j <= K; j++) {
			need[j] = MAXN;
			if (dp.test(j))
				need[j] = 0;
			else if (j >= i)
				need[j] = need[j - i] + 1;
			dp.set(j, need[j] <= cnt[i]);
		}
	
	printf("%d %d\n", K + !dp.test(K), min(N, K + min(K, sum)));
}

int main() {
	load();
	solve();
	return 0;
}