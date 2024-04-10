#include <bits/stdc++.h>
using namespace std;
int n;
char s[55], t[55];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s + 1);
		n = strlen(s + 1);
		int ans = 0;
		for (int mask = 0; mask < (1 << 3); mask++) {
			char op[10];
			for (int i = 0; i < 3; i++) op[i] = (mask >> i & 1) ? '(' : ')';
			int sum = 0, f = 1;
			for (int i = 1; i <= n; i++) {
				t[i] = op[s[i] - 'A'];
				if (t[i] == '(') {
					sum++;
				} else {
					sum--;
					if (sum < 0) f = 0;
				}
			}
			if (f && sum == 0) { ans = 1; break; }
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}