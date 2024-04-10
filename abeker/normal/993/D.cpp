#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int MAXN = 55;
const ld INF = 1e18;
const ld eps = 1e-9;

int N;
pii task[MAXN];
ld dp[MAXN][MAXN][MAXN];
int gap[MAXN];
ld val[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &task[i].first);
	for (int i = 1; i <= N; i++)
		scanf("%d", &task[i].second);
}

ld rec(int pos, int sum, int curr) {
	ld &ref = dp[pos][sum][curr];
	if (ref < INF || curr > sum)	
		return ref;
	if (gap[pos]) {
		ref = rec(pos - 1, sum + gap[pos] - 2 * curr, 0) + val[pos];
		if (curr < sum)
			ref = min(ref, rec(pos - 1, sum + gap[pos] - 2 * (curr + 1), 0));
	}
	else {
		ref = rec(pos - 1, sum, curr) + val[pos]; 
		ref = min(ref, rec(pos - 1, sum, curr + 1));
	}
	return ref;
}

bool check(ld threshold) {
	for (int i = 1; i <= N; i++)
		val[i] = task[i].first - threshold * task[i].second;
	
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= N; k++)
				dp[i][j][k] = i || k ? INF : 0;
	
	return rec(N, 0, 0) < eps;
}

ll solve() {
	sort(task + 1, task + N + 1);
	
	int last = N + 1;
	for (int i = N; i; i--)
		if (task[i].first != task[i - 1].first) {
			gap[i] = last - i;
			last = i;
		}
		
	ld lo = 0, hi = 1e8;
	for (int i = 0; i < 100; i++) {
		ld mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	
	return ceil(lo * 1000);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}