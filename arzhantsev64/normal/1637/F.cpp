#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

int n;
int v_max = 0;
int ans = 0;
vector<int> h;
vector<vector<int>> G;

int dfs(int v, int p = -1) {
    vector<int> sub;
    sub.push_back(0);
    if (G[v].size() == 1) {
        ans += h[v];
        sub.push_back(h[v]);
    }
    int cur_max = -1;
    for (int to : G[v])
        if (to != p)
            sub.push_back(dfs(to, v));

    int max1 = sub[0];
    int max2 = sub[1];
    if (max1 < max2)
        swap(max1, max2);
    for (int i = 2; i < sub.size(); ++i) {
        if (sub[i] >= max1) {
            max2 = max1;
            max1 = sub[i];
        } else if (sub[i] >= max2) {
            max2 = sub[i];
        }
    }

    int tmp = max1;
    if (h[v] > max1) {
        ans += h[v] - max1;
        tmp = h[v];
    }
    if (v == v_max && h[v] > max2) {
        ans += h[v] - max2;
    }
    return tmp;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    h.resize(n);
    G.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > h[v_max])
            v_max = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(v_max);
    // cout << v_max << endl;
    // for (auto i : max_subtree)
        // cout << i << ' ';
    // cout << endl;
    cout << ans << '\n';

    return 0;
}