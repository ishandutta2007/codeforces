#include <bits/stdc++.h>
using namespace std;
int main() {
	long long k;
	cin >> k;
	const char str[] = "codeforces";
	int c[10];
	long long cur = 1;
	for (int i = 0; i < 10; i++) c[i] = 1;
	while (cur < k) {
		int mn = 0x3f3f3f3f;
		for (int i = 0; i < 10; i++) mn = min(mn, c[i]);
		for (int i = 0; i < 10; i++) if (c[i] == mn) {
			cur /= c[i];
			c[i]++;
			cur *= c[i];
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < c[i]; j++) putchar(str[i]);
	}
	putchar('\n');
	return 0;
}