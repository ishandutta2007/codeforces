#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1005;
const int K = 8;

int N;
int a[MAXN];
int dp[1 << K][MAXN];
vector <int> occ[K];
int idx[MAXN];
int last[MAXN][K];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
		a[i]--;
	}
}

int rec(int pos, int mask, int len) {
	int &ref = dp[mask][pos];
	if (!pos || ref != -1)
		return ref;
	for (int i = 0; i < K; i++)
		if (mask >> i & 1) {
			int tmp = last[pos][i];
			if (!tmp)
				continue;
			if (idx[tmp] >= len - 1)
				ref = max(ref, rec(occ[i][idx[tmp] - len + 1] - 1, mask ^ 1 << i, len));
			if (idx[tmp] >= len) {
				int curr = rec(occ[i][idx[tmp] - len] - 1, mask ^ 1 << i, len);
				if (curr != -1)
					ref = max(ref, curr + 1);
			}
		}
	return ref;
}

int calc(int val) {
	memset(dp, -1, sizeof dp);
	memset(dp[0], 0, sizeof dp[0]);
	return rec(N, (1 << K) - 1, val);
}

int solve() {
	for (int i = 1; i <= N; i++) {
		idx[i] = occ[a[i]].size();
		occ[a[i]].push_back(i);
		memcpy(last[i], last[i - 1], sizeof last[i]);
		last[i][a[i]] = i;
	}
		
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (calc(mid) != -1)
			lo = mid;
		else
			hi = mid - 1;
	}
	
	if (!lo) {
		set <int> S;
		for (int i = 1; i <= N; i++)
			S.insert(a[i]);
		return S.size();
	}
	
	return 8 * lo + calc(lo);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}