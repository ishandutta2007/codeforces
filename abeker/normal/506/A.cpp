#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30001;
const int MAXL = 605;

int N, D;
int cnt[MAXN];
int dp[MAXN][MAXL];

void load() {
	scanf("%d%d", &N, &D);
	while (N--) {
		int p;
		scanf("%d", &p);
		cnt[p]++;
	}
}

int rec(int pos, int jump) {
	int &ref = dp[pos][jump];
	if (ref != -1)
		return ref;
	ref = 0;
	for (int i = -1; i <= 1; i++) 
		if (jump + D + i > 0 && pos + jump + D + i < MAXN)
			ref = max(ref, rec(pos + jump + D + i, jump + i));
	ref += cnt[pos];
	return ref;
}

int solve() {
	memset(dp, -1, sizeof dp);
	return rec(D, 0);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}