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

int n, m, u, v, vis[MN], depth[MN], in[MN], SQRT, pre[MN];
vector<int> a[MN], b[MN], ans;
bool cyc = 0;

void dfs(int cur, int par, int d) {
    if (cyc) return;
    vis[cur] = 1;
    depth[cur] = d;
    pre[cur] = par;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        if (!vis[nxt]) dfs(nxt, cur, d + 1);
        else if (depth[nxt] - depth[cur] + 1 >= SQRT) {
            swap(cur, nxt);
            int cnt = 1;
            while (cur != nxt) {
                ans.push_back(cur), cur = pre[cur], cnt++;
            }
            ans.push_back(nxt);
            printf("2\n%d\n", cnt);
            for (int prt : ans) printf("%d ", prt);
            exit(0);
        }
    }
    if (cyc) return;
    if (in[cur]) return;
    for (int nxt : a[cur]) in[nxt] = 1;
}

int main() {
    boost();

    cin >> n >> m;
    SQRT = ceil(sqrt(n));
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0);
    if (cyc) return 0;
    printf("1\n");
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) printf("%d ", i), cnt++;
        if (cnt == SQRT) return 0;
    }
    assert(0);

    return 0;
}