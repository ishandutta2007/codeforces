#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n;
int *a;
int *b;

int main() {
	scanf("%d", &n);
	a = new int[(n + 1)];
	b = new int[(n + 1)];
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	if (a[1] != b[1] || a[n] != b[n]) {
		puts("No");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		a[i] = a[i + 1] - a[i];
		b[i] = b[i + 1] - b[i];
	}
	sort(a + 1, a + n);
	sort(b + 1, b + n);
	for (int i = 1; i < n; i++) {
		if (a[i] ^ b[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}