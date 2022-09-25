#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	auto get = []() {
		int a, b, c, d;
		ignore = scanf("%d %d %d %d", &a, &b, &c, &d);
		return a + b + c + d;
	};
	
	int s = get(), ans = 1;
	for (int i = 1; i < n; i++) {
		int f = get();
		if (f > s) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}