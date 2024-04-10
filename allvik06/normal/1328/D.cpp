#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        bool is = true;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i != 0 && a[i] != a[i - 1]) {
                is = false;
            }
        }
        if (is) {
            cout << 1 << "\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << "\n";
            continue;
        }
        if (n % 2 == 0) {
            cout << 2 << "\n";
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    cout << 1 << " ";
                }
                else {
                    cout << 2 << " ";
                }
            }
            cout << "\n";
            continue;
        }
        bool flag = false;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i != n - 1 && a[i] == a[i + 1]) {
                j = i;
                flag = true;
            }
        }
        if (flag) {
            cout << 2 << "\n";
            int last = 2;
            for (int i = 0; i < n; ++i) {
                if (i == j) {
                    if (last == 1) {
                        cout << 2 << " " << 2 << " ";
                        last = 2;
                    }
                    else {
                        cout << 1 << " " << 1 << " ";
                        last = 1;
                    }
                    ++i;
                }
                else {
                    if (last == 1) {
                        cout << 2 << " ";
                        last = 2;
                    }
                    else {
                        cout << 1 << " ";
                        last = 1;
                    }
                }
            }
            cout << "\n";
            continue;
        }
        if (a[0] == a[n - 1]) {
            cout << 2 << "\n";
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    cout << 1 << " ";
                }
                else {
                    cout << 2 << " ";
                }
            }
            cout << "\n";
            continue;
        }
        cout << 3 << "\n";
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << 3 << " ";
            }
            else if (i % 2 == 0) {
                cout << 1 << " ";
            }
            else {
                cout << 2 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}