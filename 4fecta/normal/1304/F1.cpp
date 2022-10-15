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

const int MN = 55, MM = 20005;

int n, m, k, a[MN][MM], psa[MN][MM], dp[MN][MM], st[MN][4 * MM];
multiset<int> best[MN];

void upd(int l, int r, int x, int val, int idx, int t) {
    if (l == r) {st[t][idx] = val; return;}
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, val, idx * 2, t);
    else upd(mid + 1, r, x, val, idx * 2 + 1, t);
    st[t][idx] = max(st[t][idx * 2], st[t][idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx, int t) {
    if (r < x || l > y || l > r) return -0x3f3f3f3f;
    if (r <= y && l >= x) return st[t][idx];
    int mid = (l + r) >> 1;
    return max(qry(l, mid, x, y, idx * 2, t), qry(mid + 1, r, x, y, idx * 2 + 1, t));
}

int main() {
    boost();

    memset(st, -0x3f, sizeof(st));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            psa[i][j] = a[i][j] + psa[i][j - 1];
        }
    }
    n++;
    for (int i = 1; i <= m; i++) best[1].insert(0);
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            int r = l + k - 1;
            if (r > m) break;
            for (int pl = max(1, l - k + 1); pl <= r; pl++) {
                int pr = pl + k - 1;
                if (pr > m) break;
                //best[i - 1].erase(best[i - 1].find(dp[i - 1][pl]));
                int over = pr > r ? psa[i - 1][r] - psa[i - 1][pl - 1] : psa[i - 1][pr] - psa[i - 1][l - 1];
                if (i == 2) over = 0;
                dp[i][l] = max(dp[i][l], dp[i - 1][pl] + psa[i][r] - psa[i][l - 1] + psa[i - 1][r] - psa[i - 1][l - 1] - over);
            }
            int bst = max(qry(0, m, 0, max(1, l - k + 1) - 1, 1, i - 1), qry(0, m, r + 1, m, 1, i - 1));
            dp[i][l] = max(dp[i][l], bst + psa[i][r] - psa[i][l - 1] + psa[i - 1][r] - psa[i - 1][l - 1]);
            upd(0, m, l, dp[i][l], 1, i);
            //best[i].insert(dp[i][l]);
            /*for (int pl = max(1, l - k + 1); pl <= r; pl++) {
                int pr = pl + k - 1;
                if (pr > m) break;
                best[i - 1].insert(dp[i - 1][pl]);
            }*/
        }
    }
    printf("%d\n", qry(0, m, 0, m, 1, n));

    return 0;
}