#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300005;
const int LOG = 19;

int N, M;
int a[MAXN];
int cnt[LOG][2 * MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

int get(int k, int val) {
	int res = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (k >> i & 1)
			res += cnt[i][(k ^ val ^ (1 << i)) >> i];
	res += cnt[0][k ^ val];
	return res;
}

int query(int val) {
	int lo = 0, hi = N + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (get(mid, val) <= mid)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

void solve() {
	sort(a, a + N);
	N = unique(a, a + N) - a;
		
	for (int i = 0; i < N; i++)
		for (int j = LOG - 1; j >= 0; j--)
			cnt[j][a[i] >> j]++;
			
	int curr = 0;
	while (M--) {
		int x;
		scanf("%d", &x);
		curr ^= x;
		printf("%d\n", query(curr));
	}
}

int main() {
	load();
	solve();
	return 0;
}