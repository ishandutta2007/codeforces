#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

long long n, l, r;

long long fn (int lvl, long long pos) {
	if (lvl == 1) return n;
	if (pos & 1) {
		if (pos % 4 == 1) return fn(lvl - 1, (pos + 1LL) >> 1LL) >> 1LL;
		else return fn(lvl - 1, (pos - 1LL) >> 1LL) >> 1LL;
	} else {
		return fn(lvl - 1, pos >> 1LL) & 1LL;
	}
}

int main (int argc, char const *argv[]) {
	scanf("%lld %lld %lld", &n, &l, &r);
	if (n == 0) {
		puts("0");
		return 0;
	}
	int sum = 0, lg = 0;
	while ((1LL << lg) <= n) ++lg;
	// cout << lg << endl;
	for (long long i = l; i <= r; ++i) {
		sum += fn(lg, i);
	}
	printf("%d\n", sum);
    return 0;
}