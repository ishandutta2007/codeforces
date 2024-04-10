#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i + 2 <= n; ++i) {
		if (a[i] + a[i + 1] > a[i + 2]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
    return 0;
}