#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<long long> v1, v2;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (!x) v1.push_back(1ll * y * y);
			else v2.push_back(1ll * x * x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		double ans = 0;
		for (int i = 0; i < n; i++) ans += sqrt(v1[i] + v2[i]);
		printf("%.15lf\n", ans);
	}
	return 0;
}