#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		pair<pair<int, int>, pair<int, int>> ans;
		bool ok = false;
		map<int, pair<int, int>> m;
		for (int i = 0; i < n; ++ i) {
			int len;
			scanf("%d", &len);
			vector<int> a(len);
			for (int i = 0; i < len; ++ i)
				scanf("%d", &a[i]);
			int sum = accumulate(a.begin(), a.end(), 0);
			for (int j = 0; j < len; ++ j) {
				auto it = m.find(sum - a[j]);
				if (it != m.end()) {
					ok = true;
					ans = make_pair(it->second, make_pair(i, j));
				}
			}
			for (int j = 0; j < len; ++ j)
				m[sum - a[j]] = make_pair(i, j);
		}
		puts(ok ? "YES" : "NO");
		if (ok) {
			printf("%d %d\n", ans.first.first + 1, ans.first.second + 1);
			printf("%d %d\n", ans.second.first + 1, ans.second.second + 1);
		}
	}
}