#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> ans;
		set<int> used;
		for (int i = 0; i < n; ++ i) if (ans.size() < k) {
			if (used.emplace(a[i]).second)
				ans.push_back(i);
		}
		if (ans.size() == k) {
			puts("YES");
			for (int i = 0; i < (int)ans.size(); ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");
		} else {
			puts("NO");
		}
	}
}