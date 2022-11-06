#include <bits/stdc++.h>
const int N = 105;
int T, n, a[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		std::sort(a + 1, a + n + 1);
		int N = n;
		for (int i = 2; i <= N; )
			if (a[i] == a[i - 1]) {
				for (int j = i + 1; j <= n; j++)
					std::swap(a[j], a[j - 1]);
				N--;
			} else i++;
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}