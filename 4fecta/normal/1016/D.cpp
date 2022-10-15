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

int n, m, a[MN], b[MN], ans[MN][MN], cnt[MN];

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int s = 0; s < 32; s++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int p = a[i] & (1 << s);
            if (p) ans[i][m] |= (1 << s);
        }
        for (int i = 1; i <= m; i++) {
            int p = b[i] & (1 << s);
            if (p) ans[n][i] |= (1 << s);
        }
        for (int i = 1; i <= m; i++) {
            if (ans[n][i] & (1 << s)) cnt++;
        }
        bool req = a[n] & (1 << s);
        if (req != cnt % 2) ans[n][m] ^= (1 << s);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i][m] & (1 << s)) cnt++;
        }
        req = b[m] & (1 << s);
        if (req != cnt % 2) return 0 * printf("NO\n");
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}