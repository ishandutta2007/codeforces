#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int l = (n - k) >> 1;
	for (int i = 1; i <= n; i++) {
		putchar('0' + (i % (l + 1) > 0));
	}
	return 0;
}