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

int n, u, v, deg[MN], ans[MN], mx;
vector<int> a[MN];
pii edge[MN];

int main() {
    boost();

    memset(ans, -1, sizeof(ans));
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        edge[i] = {u, v};
        mx = max(mx, ++deg[u]);
        mx = max(mx, ++deg[v]);
    }
    if (mx < 3) {
        for (int i = 0; i < n - 1; i++) printf("%d\n", i);
        return 0;
    }
    int cen = 0;
    for (int i = 1; i <= n; i++) if (deg[i] > 2) cen = i;
    int id = 0;
    for (int i = 1; i < n; i++) {
        if (edge[i].f == cen || edge[i].s == cen) ans[i] = id++;
    }
    for (int i = 1; i < n; i++) {
        if (ans[i] != -1) printf("%d\n", ans[i]);
        else printf("%d\n", id++);
    }

    return 0;
}