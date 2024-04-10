#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int K;
	while (~scanf("%d%d", &n, &K)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		int ans = 0;
		int preva = 0, prevn = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			for (; j < n && a[j] == a[i]; ++ j);
			if (preva < a[i] - K)
				ans += prevn;
			preva = a[i];
			prevn = j - i;
		}
		ans += prevn;
		printf("%d\n", ans);
	}
}