#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i) {
			int a;
			scanf("%d", &a);
			as[i] = a;
		}
		int ans = 0;
		while (1) {
			if ((accumulate(as.begin(), as.end(), 0) * 2 + n) / (n * 2) == 5) break;
			sort(as.begin(), as.end());
			as[0] = 5;
			++ ans;
		}
		printf("%d\n", ans);
	}
}