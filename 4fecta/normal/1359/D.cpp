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

int n, a[MN], ans;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int lim = 30; lim >= -30; lim--) {
        int mx = 0, hi = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > lim) {
                ans = max(ans, mx - hi);
                mx = 0, hi = 0;
            } else {
                if (a[i] > mx + a[i]) hi = a[i];
                else hi = max(hi, a[i]);
                mx = max(mx + a[i], a[i]);
            }
            ans = max(ans, mx - hi);
        }
    }
    printf("%lld\n", ans);

    return 0;
}