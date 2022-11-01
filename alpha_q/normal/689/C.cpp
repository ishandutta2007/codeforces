#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    long long m; cin >> m;
    long long lo = 1, hi = 1e18, ans = hi;
    int it = 70;

    while (it--) {
        long long n = (lo + hi) >> 1;
        long long way = 0;
        for (long long k = 2; k * k * k <= n; ++k) {
            way += n/(k * k * k);
        }
        if (way < m) lo = n + 1;
        else if (way == m) ans = min(ans, n), hi = n - 1;
        else hi = n - 1;
    }

    long long n = ans;
    long long way = 0;
    for (long long k = 2; k * k * k <= n; ++k) {
        way += n/(k * k * k);
    }

    if (way == m) printf("%I64d\n", n);
    else printf("-1\n");
    return 0;
}