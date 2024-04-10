#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 200005;
const int SQRT = 400;

int N, C;
int x[MAXN];
deque <int> dp;
int bound[MAXN];
int sum[MAXN];
int curr[MAXN];

void load() {
	scanf("%d%d", &C, &N);
	for (int i = 0; i < N; i++)
		scanf("%d", x + i);
}

void solve() {
	sort(x, x + N);
	
	int suff = C;
	for (int i = N - 1; i >= 0; i--) {
		suff = max(suff - x[i], 0);
		bound[i] = max(suff, x[i + 1] - x[i]);
	}
		
	dp.resize(C);
	dp[0] = 1;
	int it = 0;
	for (; it < N && x[it] <= min(SQRT, C - 1); it++) {
		for (int j = 0; j < x[it]; j++)
			dp.push_front(dp[x[it] - 1]);
		for (int j = 0; j < x[it]; j++)
			dp.pop_back();
	}
	
	for (; it < N; it++) {
		for (int j = 0; j < bound[it]; j++)
			curr[j] = dp[j];
		for (int j = 0; j < bound[it]; j++)
			dp[x[it] + j] = curr[j];
	}
	
	int tmp = C;
	for (int i = N - 1; i >= 0; i--) {
		if (tmp < x[i]) 
			continue;
		sum[x[i] + 1]++;
		sum[tmp + 1]--;
		tmp -= x[i];
	}
	
	for (int i = 1; i < C; i++)
		sum[i] += sum[i - 1];
	
	for (int i = 1; i < C; i++)
		if (!dp[C - i] && sum[i]) {
			printf("%d\n", i);
			return;
		}
	puts("Greed is good");
}

int main() {
	load();
	solve();
	return 0;
}