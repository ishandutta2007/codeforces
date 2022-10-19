#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    for (int i = 0; i + 1 < n; i++)
        if (a[i] == 0 && a[i + 1] > 0) {
            cout << "No\n";
            return;
        }
    if (*min_element(a.begin(), a.end()) >= 0 && a.back() == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}