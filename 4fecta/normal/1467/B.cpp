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

int n, a[300005];

int shit(int i) {
    return (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0, del = 0;
        for (int i = 2; i < n; i++) ans += shit(i);
        for (int i = 2; i < n; i++) {
            int old = 0, A = a[i];
            if (i > 2) old += shit(i - 1);
            if (i < n - 1) old += shit(i + 1);
            old += shit(i);
            a[i] = a[i - 1];
            int nw = 0;
            if (i > 2) nw += shit(i - 1);
            if (i < n - 1) nw += shit(i + 1);
            nw += shit(i);
            del = max(del, old - nw);
            a[i] = a[i + 1];
            nw = 0;
            if (i > 2) nw += shit(i - 1);
            if (i < n - 1) nw += shit(i + 1);
            nw += shit(i);
            del = max(del, old - nw);
            a[i] = A;
        }
        printf("%d\n", ans - del);
    }

    return 0;
}