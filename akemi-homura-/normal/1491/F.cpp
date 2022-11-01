#include <bits/stdc++.h>
using namespace std;
inline int Query(vector<int> v1, vector<int> v2) {
	printf("? %d %d\n", (int)v1.size(), (int)v2.size());
	for (int x : v1) printf("%d ", x); printf("\n");
	for (int x : v2) printf("%d ", x); printf("\n");
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}
int n;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int st = 0, rem = 0;
		for (int i = 1; i <= n; i++) {
			vector<int> v2;
			for (int j = i + 1; j <= n; j++) v2.push_back(j);
			int cur = Query({i}, v2);
			if (cur) {
				st = i;
				rem = cur;
				break;
			}
		}
		vector<int> ans;
		for (int i = st + 1; i < n; i++) {
			int cur = Query({st}, {i});
			if (!cur) ans.push_back(i);
			else rem -= cur;
		}
		if (!rem) ans.push_back(n);
		int lo = 1, hi = st;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			vector<int> v1;
			for (int j = 1; j <= mid; j++) v1.push_back(j);
			if (Query(v1, {st})) hi = mid;
			else lo = mid + 1;
		}
		for (int i = 1; i < st; i++) if (i != hi) ans.push_back(i);
		printf("! %d", (int)ans.size());
		for (int x : ans) printf(" %d", x); printf("\n");
		fflush(stdout);
	}
	return 0;
}