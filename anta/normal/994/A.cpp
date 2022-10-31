#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<int> xs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &xs[i]);
		vector<int> ys(m);
		for (int i = 0; i < m; ++ i)
			scanf("%d", &ys[i]);
		set<int> S(ys.begin(), ys.end());
		vector<int> ans;
		for (int x : xs) if (S.count(x))
			ans.push_back(x);
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
}