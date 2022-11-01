#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
bool f[1005][1005];
vector<int> ans[1005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (i == 1) ans[i] = {1};
			else {
				ans[i] = ans[i - 1];
				if (a[i] == 1) ans[i].push_back(1);
				else {
					while (a[i] != ans[i].back() + 1) ans[i].pop_back();
					ans[i].back()++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d", ans[i][0]);
			for (int j = 1; j < (int)ans[i].size(); j++) {
				printf(".%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}