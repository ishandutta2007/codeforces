#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int &e : w)
        cin >> e;
    int res = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        res += min(w[u], w[v]);
    }
    cout << res << '\n';

    return 0;
}