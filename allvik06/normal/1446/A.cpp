#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector <int> a;
    while (t--) {
        int n, w;
        cin >> n >> w;
        a.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (2 * a[i] >= w && a[i] <= w) ans = i;
        }
        if (ans != -1) cout << 1 << "\n" << ans + 1 << "\n";
        else {
            int cur = 0;
            vector <int> flex;
            for (int i = 0; i < n; ++i) {
                if (a[i] > w) continue;
                cur += a[i];
                flex.push_back(i);
                if (cur * 2 >= w) break;
            }
            if (cur * 2 >= w) {
                cout << flex.size() << "\n";
                for (int i : flex) cout << i + 1 << " ";
                cout << "\n";
            } else cout << "-1\n";
        }
    }
}