#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];

bool check(int i, int j, int k) {
	if (a[i] <= a[j] && a[j] <= a[k] || a[i] >= a[j] && a[j] >= a[k]) return 1;
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = n * 2 - 1;
		for (int i = 1; i <= n - 2; i++) {
			if (check(i, i + 1, i + 2)) continue;
			ans++;
		}
		for (int i = 1; i <= n - 3; i++) {
			if (check(i, i + 1, i + 2) || check(i, i + 1, i + 3)) continue;
			if (check(i, i + 2, i + 3) || check(i + 1, i + 2, i + 3)) continue;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}