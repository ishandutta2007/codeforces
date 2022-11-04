#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			printf("%d%c", abs(a[i]) * ((i & 1) ? 1 : -1), " \n"[i == n]);
		}
	}
	return 0;
}