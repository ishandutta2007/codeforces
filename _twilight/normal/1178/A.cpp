#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

int n;
vector<int> ans;

int main() {
	scanf("%d", &n);
	int sum = 0, x, y;
	scanf("%d", &x);
	sum = x;
	ans.push_back(1);
	for (int i = 2; i <= n; i++) {	
		scanf("%d", &y);
		if ((y << 1) <= x) {
			sum += y;
			ans.push_back(i);
		} else {
			sum -= y;
		}
	}
	if (sum > 0) {
		printf("%d\n", (signed) ans.size());
		for (auto x : ans) {
			printf("%d ", x);
		}
	} else {
		puts("0");
	}
	return 0;
}