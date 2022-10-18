#include <bits/stdc++.h>

using namespace std;

int a[105], used[105];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) used[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int pos = -1;
        for (int j = 1; j <= n; ++j) if (a[j] == i) pos = j;
        while (1) {
            if (pos == 1) break;
            if (a[pos - 1] < i) break;
            if (used[pos - 1]) break;
            swap(a[pos - 1], a[pos]);
            used[pos - 1] = 1;
            pos--;
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}