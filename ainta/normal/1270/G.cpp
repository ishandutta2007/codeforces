#include<cstdio>
int n, w[1010000], vis[1010000];
void Solve() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		vis[i] = 0;
		w[i] = i - w[i];
	}
	int a = 1;
	for (i = 1; i <= n; i++)a = w[a];
	int st = a;
	int c = 0;
	while (1) {
		c++;
		vis[a] = 1;
		a = w[a];
		if (a == st)break;
	}
	printf("%d\n", c);
	for (i = 1; i <= n; i++)if (vis[i])printf("%d ", i);
	puts("");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}