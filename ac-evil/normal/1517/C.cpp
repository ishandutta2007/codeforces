#include <bits/stdc++.h>
typedef long long LL;
const int N = 505;
int n, a[N], b[N][N];
int main() {
	// freopen("ques.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++)
			if (a[j] >= i) b[p + i][p + 1] = a[j], p++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			printf("%d%c", b[i][j], " \n"[j == i]);
	return 0;
}