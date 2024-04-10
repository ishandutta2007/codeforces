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

int t, n, k, u, l[MN], r[MN];
vector<int> a[MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        for (int i = 1; i <= n; i++) l[i] = r[i] = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> u;
                if (!l[i] && !r[u]) l[i] = 1, r[u] = 1;
            }
        }
        int L = 0, R = 0;
        for (int i = 1; i <= n; i++) {
            if (!l[i]) {
                L = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!r[i]) {
                R = i;
                break;
            }
        }
        if (!L) printf("OPTIMAL\n");
        else printf("IMPROVE\n%d %d\n", L, R);
    }

    return 0;
}