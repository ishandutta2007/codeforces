#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) cin >> r[i];
    vector<int> c(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (r[u] > r[v]) ++c[u];
        if (r[v] > r[u]) ++c[v];
    }
    auto x = r;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        auto t = lower_bound(x.begin(), x.end(), r[i]);
        cout << t - x.begin() - c[i] << " \n"[i == n - 1];
    }
    return 0;
}