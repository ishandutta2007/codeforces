#include <bits/stdc++.h>

using namespace std;

int n, m, a[2010], cnt[2010];

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);

	int bigger = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > m) ++bigger;
		else ++cnt[a[i]];
	}

	int moves = 0, block = n/m;
	for (int j = 1; j <= m; ++j) {
		if (cnt[j] >= block) continue;
		for (int i = 1; i <= n and cnt[j] < block; ++i) {
			if (a[i] > m) a[i] = j, ++cnt[j], ++moves;
			else if (cnt[a[i]] > block) --cnt[a[i]], ++cnt[j], a[i] = j, ++moves;
		}
	}

	printf("%d %d\n", block, moves);
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
	puts("");
	return 0;
}