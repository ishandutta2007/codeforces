#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e14 + 10;

int n, tot = 0;
long long c, t, last = INF;

int main (int argc, char const *argv[]) {
	scanf("%d %lld", &n, &c);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &t);
		if (t - last > c) tot = 0;
		++tot, last = t;
	}
	printf("%d\n", tot);
	return 0;
}