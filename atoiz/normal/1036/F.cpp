#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <limits>

#define double long double

using namespace std;

long long powll(long long x, long long p)
{
    if (pow(x, p) > 8223372036854775800ll) return 8223372036854775800ll;
    long long ans = 1;
	while (p > 0) {
        if (p & 1) ans *= x;
        p >>= 1;
        x *= x;
	}
	return ans;
}

int main()
{
	vector<long long> mu = {0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1, -1};
    int tests; scanf("%d", &tests);
    while (tests--) {
        long long n; scanf("%I64d", &n);
        long long cnt;
        long long ans = 0;
        for (int i = 1; i < 1000; ++i) {
            cnt = pow(n, 1.0 / i);
            while (powll(cnt+1, i) <= n) ++cnt;
            while (powll(cnt, i) > n) --cnt;
            ans += mu[i] * max(0ll, cnt - 1);
            if (cnt < 2) break;
        }
        printf("%I64d\n", ans);
    }
}