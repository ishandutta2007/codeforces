#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN], bad[MN];

int32_t main() {
    boost();

    cin >> n;
    /*int len = 0;
    for (int msk = 1; msk < 1 << (n - 1); msk++) {
        int prod = 1;
        for (int i = 0; i < n - 1; i++) if (msk & (1 << i)) prod = prod * (i + 1) % n;
        if (prod == 1) len = max(len, (int) __builtin_popcount(msk));
    }
    printf("%d\n", len);
    for (int msk = 1; msk < 1 << (n - 1); msk++) {
        int prod = 1;
        for (int i = 0; i < n - 1; i++) if (msk & (1 << i)) prod = prod * (i + 1) % n;
        if (prod == 1 && __builtin_popcount(msk) == len) {
            for (int i = 0; i < n - 1; i++) if (msk & (1 << i)) printf("%d ", i + 1);
            printf("\n");
        }
    }*/
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            for (int j = i; j <= n; j += i) bad[j] = 1;
        }
    }
    int prod = 1;
    for (int i = 1; i <= n - 1; i++) if (!bad[i]) ans++, prod = prod * i % n;
    if (prod == 1) {
        printf("%lld\n", ans);
        for (int i = 1; i <= n - 1; i++) if (!bad[i]) printf("%lld ", i);
    } else {
        printf("%lld\n", ans - 1);
        for (int i = 1; i < n - 1; i++) if (!bad[i]) printf("%lld ", i);
    }

    return 0;
}