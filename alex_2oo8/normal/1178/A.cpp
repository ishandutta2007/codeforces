#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p;
	ignore = scanf("%d %d", &n, &p);
	vector<int> ans = {1};
	int total = p, sum = p;
	for (int i = 2, x; i <= n; i++) {
		ignore = scanf("%d", &x);
		total += x;
		if (p >= 2 * x) {
			sum += x;
			ans.push_back(i);
		}
	}
	
	if (sum > total - sum) {
		printf("%d\n", (int)ans.size());
		for (int x : ans) printf("%d ", x);
		printf("\n");
	}
	else {
		printf("%d\n", 0);
	}
	
	return 0;
}