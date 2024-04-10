#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	int p = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == n) {
			p = i;
		}
	}
	for (int i = p; i > 1; i--) {
		if (a[i] < a[i - 1]) {
			puts("NO");
			return 0;
		}
	}
	for (int i = p; i < n; i++) {
		if (a[i] < a[i + 1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}