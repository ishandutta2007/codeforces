#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int ans = 0;
		for (int x : {100, 20, 10, 5, 1})
			ans += n / x, n %= x;
		printf("%d\n", ans);
	}
}