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

const int MN = 1000005, LOG = 21;

int q, u, n = 5, bl[MN][LOG], depth[MN], d1 = 2, d2 = 4, dia = 2;

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    }
    return bl[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    boost();

    bl[2][0] = bl[3][0] = bl[4][0] = 1;
    depth[2] = depth[3] = depth[4] = 1;
    cin >> q;
    while (q--) {
        cin >> u;
        bl[n][0] = u;
        depth[n] = depth[u] + 1;
        for (int i = 1; i < LOG; i++) {
            bl[n][i] = bl[bl[n][i - 1]][i - 1];
        }
        if (max(dist(n, d1), dist(n, d2)) > dia) {
            if (dist(n, d1) > dist(n, d2)) {
                d2 = n;
                dia = dist(d1, d2);
            } else {
                d1 = n;
                dia = dist(d1, d2);
            }
        }
        n++;
        bl[n][0] = u;
        depth[n] = depth[u] + 1;
        for (int i = 1; i < LOG; i++) {
            bl[n][i] = bl[bl[n][i - 1]][i - 1];
        }
        n++;
        if (max(dist(n, d1), dist(n, d2)) > dia) {
            if (dist(n, d1) > dist(n, d2)) {
                d2 = n;
                dia = dist(d1, d2);
            } else {
                d1 = n;
                dia = dist(d1, d2);
            }
        }
        printf("%d\n", dia);
    }

    return 0;
}