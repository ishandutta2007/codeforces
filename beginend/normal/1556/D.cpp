#include<bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, k, a[N];

int ask(int x, int y, char* ty) {
	printf("%s %d %d\n", ty, x, y);
	fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	int x = ask(1, 2, "and") + ask(1, 2, "or");
	int y = ask(1, 3, "and") + ask(1, 3, "or");
	int z = ask(2, 3, "and") + ask(2, 3, "or");
	a[1] = (x + y - z) / 2;
	a[2] = x - a[1];
	a[3] = y - a[1];
	for (int i = 4; i <= n; i++) {
		int w = ask(1, i, "and") + ask(1, i, "or");
		a[i] = w - a[1];
	}
	sort(a + 1, a + n + 1);
	printf("finish %d\n", a[k]);
	return 0;
}