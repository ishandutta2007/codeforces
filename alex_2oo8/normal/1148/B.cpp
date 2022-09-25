#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX], b[MX], x[MX];

int main() {
	int n, m, ta, tb, k;
	ignore = scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	for (int i = 0; i < m; i++) ignore = scanf("%d", b + i);
	
	if (k >= min(n, m)) {
		printf("%d\n", -1);
		return 0;
	}
	
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && b[j] < a[i] + ta) j++;
		x[i] = j;
	}
	
	int ans = 0;
	for (int p = 0, q = k; p <= k; p++, q--) {
		int j = x[p] + q;
		if (j >= m) ans = -1;
		else if (ans != -1) ans = max(b[j] + tb, ans);
	}
	
	printf("%d\n", ans);
	
	return 0;
}