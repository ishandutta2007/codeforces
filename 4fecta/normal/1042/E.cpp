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

const int MN = 1005, MOD = 998244353;

struct node {
    int v, x, y;
    bool operator<(const node &b) const { return v < b.v; }
} a[MN * MN];

int n, m, nm, s, X, X2, Y, Y2, sum, inv[MN * MN], ans[MN][MN];

int32_t main() {
    boost();
    
    cin >> n >> m;
    nm = n * m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t;
            cin >> t;
            a[(i - 1) * m + j] = {t, i, j};
        }
    }
    sort(a + 1, a + nm + 1);
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= nm; ++i) inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1, j = 1; i <= nm; i = j = j + 1) {
        while (j < nm && a[j + 1].v == a[i].v) ++j;
        for (int k = i; k <= j; ++k) {
            ans[a[k].x][a[k].y] =
                    (1ll * s * a[k].x * a[k].x % MOD + X2 + 1ll * X * a[k].x % MOD + 1ll * s * a[k].y * a[k].y % MOD +
                     Y2 + 1ll * Y * a[k].y % MOD + sum) % MOD * inv[s] % MOD;
        }
        for (int k = i; k <= j; ++k) {
            ++s;
            X = (X - 2 * a[k].x + MOD) % MOD;
            X2 = (X2 + a[k].x * a[k].x) % MOD;
            Y = (Y - 2 * a[k].y + MOD) % MOD;
            Y2 = (Y2 + a[k].y * a[k].y) % MOD;
            sum = (sum + ans[a[k].x][a[k].y]) % MOD;
        }
    }
    int r, c;
    cin >> r >> c;
    printf("%d\n", ans[r][c]);
    return 0;
}