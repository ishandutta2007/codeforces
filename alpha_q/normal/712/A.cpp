#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) printf("%d ", a[i] + a[i + 1]);
	puts("");
	return 0;
}