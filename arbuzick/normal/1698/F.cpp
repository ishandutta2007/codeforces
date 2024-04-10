#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i]--;
    }
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }
        auto rev = [&](int l, int r) {
            ans.emplace_back(l, r);
            reverse(a.begin() + l, a.begin() + r + 1);
        };
        for (int j = i + 1; j + 1 < n; ++j) {
            if (a[j] == b[i] && a[j + 1] == a[i - 1]) {
                rev(i - 1, j + 1);
                break;
            }
        }
        if (a[i] == b[i]) {
            continue;
        }
        bool change = false;
        for (int j = i; j + 1 < n && !change; ++j) {
            if (a[j] == a[i - 1] && a[j + 1] == b[i]) {
                vector<int> used(n, -1);
                for (int k = i - 1; k <= j; ++k) {
                    used[a[k]] = k;
                }
                for (int k = j + 1; k < n && !change; ++k) {
                    if (used[a[k]] != -1) {
                        change = true;
                        rev(used[a[k]], k);
                    }
                }
            }
        }
        if (!change) {
            cout << "NO\n";
            return;
        }
        if (a[i] == b[i]) {
            continue;
        }
        for (int j = i + 1; j + 1 < n; ++j) {
            if (a[j] == b[i] && a[j + 1] == a[i - 1]) {
                rev(i - 1, j + 1);
                break;
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}