#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		int L = 0;
		for (; L < n && a[L] <= k; ++ L);
		int R = n;
		for (; L < R && a[R - 1] <= k; -- R);
		int ans = L + (n - R);
		printf("%d\n", ans);
	}
}