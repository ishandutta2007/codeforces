#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		vector<tuple<int, int, int> > ans;
		for (int i = 1; i <= n / 2; i++) {
			int x = i, y = n + 1 - i;
			ans.emplace_back(1, x, y);
			ans.emplace_back(2, x, y);
			ans.emplace_back(1, x, y);
			ans.emplace_back(1, x, y);
			ans.emplace_back(2, x, y);
			ans.emplace_back(1, x, y);
		}
		printf("%d\n", (int)ans.size());
		for (auto &P: ans) printf("%d %d %d\n", get<0>(P), get<1>(P), get<2>(P));
	}
	return 0;
}