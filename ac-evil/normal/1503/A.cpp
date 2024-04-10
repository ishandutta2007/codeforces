#include <bits/stdc++.h>
const int N = 200005;
int T, n; char str[N], a[N], b[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, str);
		n = strlen(str);
		int one = 0, cnt0 = 0, cnt1 = 0, ok = 1;
		for (int i = 0; i < n; i++)
			if (str[i] == '1') one++;
		if (n & 1 || one & 1) ok = 0;
		int v0 = 0, v1 = 0;
		for (int i = 0; ok && i < n; i++) {
			if (str[i] == '1') {
				cnt1++;
				if (cnt1 <= one / 2) a[i] = b[i] = '(', v0++, v1++;
				else a[i] = b[i] = ')', v0--, v1--;
			} else {
				if (cnt0 & 1) a[i] = '(', b[i] = ')', v0++, v1--;
				else a[i] = ')', b[i] = '(', v0--, v1++;
				cnt0++;
			}
			if (v0 < 0 || v1 < 0) ok = 0;
		}
		if (v0 || v1) ok = 0;
		if (!ok) { puts("NO"); continue; }
		a[n] = b[n] = '\0';
		printf("YES\n%s\n%s\n", a, b);
	}
	return 0;
}