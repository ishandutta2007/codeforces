#include <bits/stdc++.h>
using namespace std;
const int MN = 100005;
int n, deg[MN];
vector<int> a[MN];
void dfs(int cur, int par, int node) {
    if (deg[cur] == 1 && cur != node) printf("%d %d\n", node, cur);
    for (int nxt : a[cur]) if (nxt != par) dfs(nxt, cur, node);
}
int main() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        deg[u]++; deg[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int cnt = 0, node = 1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) cnt++, node = i;
    }
    if (cnt > 1) return 0 * printf("No\n");
    else printf("Yes\n%d\n", deg[node]);
    dfs(node, 0, node);
}