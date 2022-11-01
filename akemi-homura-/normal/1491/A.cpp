#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q, a[N], c[2];
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[a[i]]++;
	while (q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			c[a[x]]--;
			a[x] ^= 1;
			c[a[x]]++;
		} else {
			if (x <= c[1]) puts("1");
			else puts("0");
		}
	}
	return 0;
}