#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == k) a[i] = 0, flag = 1;
			else if (a[i] < k) a[i] = -1;
			else a[i] = 1;
		}
		if (!flag) {
			puts("no");
			continue;
		}
		if (n == 1) {
			puts("yes");
			continue;
		}
		int found = 0;
		for (int i = 1; i <= n; i++) if (a[i] >= 0) {
			for (int j = i + 1; j <= i + 2 && j <= n; j++) if (a[j] >= 0) {
				found = 1;
				break;
			}
			if (found) break;
		}
		if (found) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	return 0;
}