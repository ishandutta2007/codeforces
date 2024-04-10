#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ng, ps;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ng.clear();
		ps.clear();
		int zr = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (!x) zr = 1;
			else if (x < 0) ng.push_back(x);
			else ps.push_back(x);
		}
		sort(ng.begin(), ng.end());
		sort(ps.begin(), ps.end());
		long long ans = (zr) ? 0 : (-1e18);
		for (int x = 0; x <= 5; x++) {
			int y = 5 - x;
			if ((int)ng.size() >= x && (int)ps.size() >= y) {
				long long prd = 1;
				if (x % 2 == 0) {
					for (int i = 0; i < x; i++) prd *= ng[i];
					for (int i = (int)ps.size() - 1; i >= (int)ps.size() - y; i--) prd *= ps[i];
				} else {
					for (int i = (int)ng.size() - 1; i >= (int)ng.size() - x; i--) prd *= ng[i];
					for (int i = 0; i < y; i++) prd *= ps[i];
				}
				ans = max(ans, prd);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}