#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

long long a[3];

long long Max() {
	return *std::max_element(a, a + 3);
}

void solve() {
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	long long y = 3 * Max() - a[0] - a[1] - a[2];
	puts("First"), fflush(stdout);
	printf("%lld\n", y), fflush(stdout);
	int x;
	scanf("%d", &x), --x;
	if (a[x] == Max()) {
		a[x] += y;
		y = 3 * Max() - a[0] - a[1] - a[2];
		printf("%lld\n", y), fflush(stdout);
		scanf("%d", &x), --x;
	}
	long long mx = Max();
	a[x] += y;
	printf("%lld\n", a[x] - mx), fflush(stdout);
	scanf("%d", &x);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}