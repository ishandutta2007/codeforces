#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <bool> used(n);
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            used[b - 1] = true;
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) root = i;
        }
        for (int i = 0; i < n; ++i) {
            if (i != root) cout << root + 1 << " " << i + 1 << "\n";
        }
    }
}