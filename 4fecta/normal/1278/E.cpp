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

const int MN = 500005;

int n, u, v, deg[MN];
vector<int> a[MN];
set<int> open;
pii ans[MN];

void dfs(int cur, int par) {
    int rit = *open.begin() + deg[cur] - 1; open.erase(rit);
    ans[cur].s = rit;
    int id = rit - 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        ans[nxt].f = id; open.erase(id--);
    }
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
    }
}

int main() {
    boost();

    cin >> n;
    ans[1].f = 1;
    for (int i = 2; i <= 2 * n; i++) open.insert(i);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        deg[u]++; deg[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    deg[1]++;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].f, ans[i].s);

    return 0;
}