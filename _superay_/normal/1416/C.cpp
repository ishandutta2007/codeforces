#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], go[N * 35][2], sz[N * 35];
long long cnt[35][2];
int main() {
	scanf("%d", &n);
	int tot = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int p = 1;
		sz[p]++;
		for (int j = 29; j >= 0; j--) {
			int b = (a[i] >> j & 1);
			if (!go[p][b]) {
				go[p][b] = ++tot;
			}
			if (go[p][b ^ 1]) cnt[j][b] += sz[go[p][b ^ 1]];
			p = go[p][b];
			sz[p]++;
		}
	}
	long long mn = 0;
	int x = 0;
	for (int j = 29; j >= 0; j--) {
		if (cnt[j][0] <= cnt[j][1]) {
			mn += cnt[j][0];
		} else {
			mn += cnt[j][1];
			x |= (1 << j);
		}
	}
	printf("%lld %d\n", mn, x);
	return 0;
}