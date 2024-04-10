#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, a[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int ss = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ss += a[i];
		if (ss % n) {
			puts("-1");
			continue;
		}
		vector<tuple<int, int, int> > ans;
		for (int i = 2; i <= n; i++) {
			int r = a[i] % i;
			if (r) {
				ans.emplace_back(1, i, i - r);
				a[i] += (i - r);
				a[1] -= (i - r);
			}
			ans.emplace_back(i, 1, a[i] / i);
			a[1] += a[i];
			a[i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			ans.emplace_back(1, i, ss / n);
		}
		printf("%d\n", (int)ans.size());
		for (auto &P : ans) printf("%d %d %d\n", get<0>(P), get<1>(P), get<2>(P));
	}
	return 0;
}