#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn];
int used[maxn], flag, ans[maxn];
vector < int > topsort;
int val[maxn];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 1) flag = 1;
        else if (used[u] == 0) dfs(u);
    }
    used[v] = 2;
    topsort.push_back(v);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k, x;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> k;
            g[i] = {};
            val[i] = 0;
            used[i] = 0;
            for (int j = 1; j <= k; ++j) {
                cin >> x;
                g[i].push_back(x);
            }
        }
        topsort = {};
        flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }
        if (flag) {
            cout << -1 << '\n';
            continue;
        }
        //reverse(topsort.begin(), topsort.end());
        int ans = 0;
        for (auto key : topsort) {
            for (auto elem : g[key]) {
                if (key < elem) val[key] = max(val[key], val[elem] + 1);
                else val[key] = max(val[key], val[elem]);
            }
            ans = max(ans, val[key]);
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}