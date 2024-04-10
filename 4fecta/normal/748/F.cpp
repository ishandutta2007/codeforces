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

const int MN = 400005;

int n, ch[MN], sz[MN], k;
vector<int> a[MN], v;

void dfs(int cur, int par) {
    sz[cur] = ch[cur];
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        sz[cur] += sz[nxt];
    }
}

int find(int cur, int par) {
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        if (sz[nxt] > k) return find(nxt, cur);
    }
    return cur;
}

void dfs1(int cur, int par) {
    if (ch[cur]) v.push_back(cur);
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs1(nxt, cur);
    }
}

int main() {
    boost();

    cin >> n >> k;
    for (int i = 1, u, x; i < n; i++) {
        cin >> u >> x;
        a[u].push_back(x);
        a[x].push_back(u);
    }
    for (int i = 1, u; i <= 2 * k; i++) cin >> u, ch[u] = 1;
    dfs(1, 0);
    int cent = find(1, 0);
    for (int nxt : a[cent]) {
        dfs1(nxt, cent);
    }
    if (ch[cent]) v.push_back(cent);
    printf("%d\n%d\n", 1, cent);
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", v[i], v[i + k], cent);
    }

    return 0;
}