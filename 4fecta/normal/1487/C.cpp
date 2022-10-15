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

const int MN = 105;

int t, n, a[MN][MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int cur = 0; cur < n; cur++) {
            for (int d = 1; d <= (n - 1) / 2; d++) {
                int nxt = (cur + d) % n;
                a[cur][nxt] = 1;
                a[nxt][cur] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}