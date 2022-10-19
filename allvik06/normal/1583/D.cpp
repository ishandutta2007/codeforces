#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector<int> p(n);
    p[n - 1] = n;
    for (int i = 1; i < n; ++i) {
        cout << "? ";
        for (int j = 0; j < n - 1; ++j) {
            cout << 1 << " ";
        }
        cout << n - i + 1 << endl;
        int x;
        cin >> x;
        if (x != 0) {
            p.back() = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == p.back()) continue;
        if (i < p.back()) {
            cout << "? ";
            for (int j = 0; j < n - 1; ++j) {
                cout << p.back() - i + 1 << " ";
            }
            cout << 1 << endl;
            int x;
            cin >> x;
            p[x - 1] = i;
        } else {
            cout << "? ";
            for (int j = 0; j < n - 1; ++j) {
                cout << 1 << " ";
            }
            cout << i - p.back() + 1 << endl;
            int x;
            cin >> x;
            p[x - 1] = i;
        }
    }
    cout << "! ";
    for (int i : p) cout << i << " ";
    cout << endl;
}