#include <bits/stdc++.h>
const int N = 1e5 + 5;
int T, n; char str[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str + 1); n = strlen(str + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = std::max(ans, str[i] - '0');
		printf("%d\n", ans);
	}
	return 0;
}