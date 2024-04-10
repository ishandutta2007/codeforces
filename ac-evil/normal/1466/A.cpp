#include <bits/stdc++.h>
const int N = 55;
int T, n, x[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
		std::set<int> S;
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				S.insert(x[j] - x[i]);
		printf("%d\n", S.size());
	}
	return 0;
}