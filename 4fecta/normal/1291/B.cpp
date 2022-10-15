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

const int MN = 300005;

int t, n, a[MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int lft = n, rit = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] >= i - 1) rit++;
            else break;
        }
        for (int i = n - 1; i > 0; i--) {
            if (a[i] >= n - i) lft--;
            else break;
        }
        if (lft <= rit) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}