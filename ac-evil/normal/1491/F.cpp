#include <bits/stdc++.h>
using std::vector;
const int N = 2005;
int T, n, F, ok[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) ok[i] = -1;
		for (int i = 2; i <= n; i++) {
			printf("? 1 %d\n%d\n", i - 1, i);
			for (int j = 1; j < i; j++) printf("%d ", j);
			puts(""); fflush(stdout);
			scanf("%d", &F);
			if (F) {
				vector<int> ans;
				for (int j = i + 1; j <= n; j++) {
					printf("? 1 1\n%d\n%d\n", i, j);
					fflush(stdout);
					scanf("%d", &F);
					if (!F) ans.push_back(j);
				}
				int l = 1, r = i - 1;
				while (l <= r) {
					int mid = l + r >> 1;
					printf("? 1 %d\n%d\n", mid, i);
					for (int j = 1; j <= mid; j++) printf("%d ", j);
					puts(""); fflush(stdout);
					scanf("%d", &F);
					if (F) r = mid - 1; else l = mid + 1;
				}
				for (int j = 1; j < i; j++)
					if (j != r + 1) ans.push_back(j);
				printf("! %d ", ans.size());
				for (int j = 0; j < ans.size(); j++) printf("%d ", ans[j]);
				puts(""); fflush(stdout); break;
			}
		}
	}
	return 0;
}