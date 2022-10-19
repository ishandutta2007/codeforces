#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

#define long long long
#define M 100100

long n, m, k, ans = -1;

long Ans(long a, long b) {
    if (a <= 0 || b <= 0)
        return -1;
    if (n < a || m < b)
        return -1;
    return (n / a) * (m / b);
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin >> n >> m >> k;
    k += 2;
    for (long i = 1; i * i <= n; ++i) {
        ans = max(ans, Ans(i, k - i));
        int l = n / i;
        if (l >= k)
            l = k - 1;
        ans = max(ans, Ans(l, k - l));
    }

    cout << ans << "\n";

    return 0;
}