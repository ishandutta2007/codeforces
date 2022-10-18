#include <bits/stdc++.h>

using namespace std;

int a[205];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    bool f;
    for (int i = 1; i <= q; ++i) {
        cin >> n;
        int pos = -1;
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
            if (a[j] == 1) pos = j;
        }
        f = true;
        int cur = 1;
        for (int j = pos; j <= n; ++j) {
            if (a[j] != cur) f = false;
            cur++;
        }
        for (int j = 1; j < pos; ++j) {
            if (a[j] != cur) f = false;
            cur++;
        }
        if (f) {
            cout << "YES" << '\n';
            continue;
        }
        cur = 1;
        f = true;
        for (int j = pos; j >= 1; --j) {
            if (a[j] != cur) f = false;
            cur++;
        }
        for (int j = n; j > pos; --j) {
            if (a[j] != cur) f = false;
            cur++;
        }
        if (f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}