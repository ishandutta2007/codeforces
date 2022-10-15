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

const int MN = 200005;

int n, a[MN]; ll dist[MN][2]; int vis[MN][2];

ll dfs(int cur, int d, int id) {
    if (cur <= 0 || cur > n) return 0;
    if (vis[cur][d] == id) return 1e17;
    vis[cur][d] = id;
    if (dist[cur][d] != -1) return dist[cur][d];
    if (d) return dist[cur][d] = dfs(cur + a[cur], 0, id) + a[cur];
    else return dist[cur][d] = dfs(cur - a[cur], 1, id) + a[cur];
}

void mark(int cur, int d) {
    if (dist[cur][d] >= 1e17) return;
    dist[cur][d] = 1e17;
    if (d) mark(cur + a[cur], 0);
    else mark(cur - a[cur], 1);
}

int main() {
    boost();

    memset(dist, -1, sizeof(dist));
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        ll dis = dfs(i + 1, 0, i);
        if (dis >= 1e17) {
            printf("-1\n");
            mark(i + 1, 0);
        } else {
            printf("%lld\n", dis + i);
        }
    }

    return 0;
}