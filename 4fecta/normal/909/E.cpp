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

int n, m, u, v, col[MN], deg[MN], ans = 0;
vector<int> a[MN];
queue<int> qw, qb;

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        u++; v++;
        a[v].push_back(u);
        deg[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i]) continue;
        if (col[i]) qb.push(i);
        else qw.push(i);
    }
    while (1) {
        while (qw.size()) {
            int cur = qw.front(); qw.pop();
            for (int nxt : a[cur]) {
                if (--deg[nxt] == 0) {
                    if (col[nxt]) qb.push(nxt);
                    else qw.push(nxt);
                }
            }
        }
        if (qw.empty() && qb.empty()) break;
        ans++;
        while (qb.size()) {
            int cur = qb.front(); qb.pop();
            for (int nxt : a[cur]) {
                if (--deg[nxt] == 0) {
                    if (col[nxt]) qb.push(nxt);
                    else qw.push(nxt);
                }
            }
        }
        if (qw.empty() && qb.empty()) break;
    }
    printf("%d\n", ans);

    return 0;
}