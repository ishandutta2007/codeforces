#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, x, a[MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> x;
        int sum = 0, l = n + 1, r = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        for (int i = 1; i <= n; i++) {
            if (a[i] % x) {l = i + 1; break;}
        }
        for (int i = n; i > 0; i--) {
            if (a[i] % x) {r = i - 1; break;}
        }
        //printf("sum: %d\n", sum);
        if (sum % x) printf("%d\n", n);
        else {
            int mx = max(n - l + 1, r);
            if (mx) printf("%d\n", mx);
            else printf("-1\n");
        }
    }

    return 0;
}