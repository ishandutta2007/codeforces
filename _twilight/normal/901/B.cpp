#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

bitset<155> f0, f1;

int n;
int main() {
	scanf("%d", &n);
	f1.set(0);
	for (int i = 1; i <= n; i++) {
		f0 = (f1 << 1) ^ f0;
		swap(f0, f1);
	}
	printf("%d\n", n);
	for (int i = 0; i <= n; i++)
		printf("%d%c", f1.test(i), (i == n) ? ('\n') : (' '));
	printf("%d\n", n - 1);
	for (int i = 0; i < n; i++)
		printf("%d%c", f0.test(i), (i == n - 1) ? ('\n') : (' '));
	return 0;
}