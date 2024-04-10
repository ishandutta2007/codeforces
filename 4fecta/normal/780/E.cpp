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

int n, m, k, u, v, len, par[MN];
vector<int> a[MN], ans;

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

void dfs(int cur, int par) {
    ans.push_back(cur);
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        ans.push_back(cur);
    }
}

int main() {
    boost();

    cin >> n >> m >> k;
    len = (2 * n + k - 1) / k;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (merge(u, v)) a[u].push_back(v), a[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= k; i++) {
        if (ans.size() >= len) {
            cout << len << " ";
            for (int j = 1; j <= len; j++) cout << ans.back() << " ", ans.pop_back();
            cout << "\n";
        } else if (ans.size()) {
            cout << ans.size() << " ";
            while (ans.size()) cout << ans.back() << " ", ans.pop_back();
            cout << "\n";
        } else {
            cout << "1 1\n";
        }
    }

    return 0;
}