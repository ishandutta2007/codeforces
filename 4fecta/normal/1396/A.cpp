#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        printf("%lld %lld\n", n, n);
        printf("0\n");
    } else {
        printf("%lld %lld\n", 1, n - 1);
        for (int i = 1; i <= n - 1; i++) {
            int ex = a[i] % n;
            printf("%lld ", (n - 1) * ex);
            a[i] += (n - 1) * ex;
            assert(a[i] % n == 0);
        }
        printf("\n");
    }

    printf("%lld %lld\n", n, n);
    printf("%lld ", -a[n]);
    a[n] = 0;
    printf("\n");

    printf("%lld %lld\n", 1, n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", -a[i]);
    }
    printf("\n");

    return 0;
}