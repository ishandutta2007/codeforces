#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[300005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %s", &n, &k, s + 1);
		int bad = 0, cc[2] = {0, 0};
		for (int i = 1; i <= k; i++) {
			int op[2] = {0, 0};
			for (int j = i; j <= n; j += k) {
				if (s[j] != '?') {
					op[s[j] - '0'] = 1;
				}
			}
			if (op[0] && op[1]) {
				bad = 1;
				break;
			}
			if (op[0]) cc[0]++;
			else if (op[1]) cc[1]++;
		}
		if (bad || (cc[0] > k / 2 || cc[1] > k / 2)) {
			puts("NO");
		} else puts("YES");
	}
	return 0;
}