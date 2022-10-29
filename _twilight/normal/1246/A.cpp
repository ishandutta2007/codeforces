#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, p;

boolean check(int num) {
	return n - num * p >= num && __builtin_popcount(n - num * p) <= num;
}

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= 30; i++) {
		if (check(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}