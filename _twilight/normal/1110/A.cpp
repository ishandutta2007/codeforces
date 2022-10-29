#include <bits/stdc++.h>
using namespace std;

int b, n;

int main() {
	scanf("%d%d", &b, &n);
	int rt = 0;
	b = b & 1;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		rt = ((rt * b) + x) & 1;
	}
	if (rt)
		puts("odd");
	else
		puts("even");
	return 0;
}