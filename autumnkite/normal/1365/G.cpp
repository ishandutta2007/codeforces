#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

int n;
std::vector<int> mask;
long long ans[13];

void dfs(int k, int lst, int now) {
	if (k == 6) {
		mask.push_back(now);
		return;
	}
	for (int i = lst + 1; i < 13; ++i) {
		dfs(k + 1, i, now | (1 << i));
	}
}

int main() {
	scanf("%d", &n);
	dfs(0, -1, 0);
	mask.resize(n);
	for (int k = 0; k < 13; ++k) {
		std::vector<int> Q;
		for (int i = 0; i < n; ++i) {
			if (mask[i] >> k & 1) {
				Q.push_back(i + 1);
			}
		}
		if (Q.empty()) {
			ans[k] = 0;
		} else {
			printf("? %d ", (int)Q.size());
			for (int v : Q) {
				printf("%d ", v);
			}
			putchar('\n');
			fflush(stdout);
			scanf("%lld", &ans[k]);
		}
	}
	printf("! ");
	for (int i = 0; i < n; ++i) {
		long long v = 0;
		for (int k = 0; k < 13; ++k) {
			if (!(mask[i] >> k & 1)) {
				v |= ans[k];
			}
		}
		printf("%lld ", v);
	}
	putchar('\n');
	fflush(stdout);
}