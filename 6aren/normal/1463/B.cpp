#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }
        long long sumOdd = 0, sumEven = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) sumOdd += a[i];
            else sumEven += a[i];
        }
        vector<int> b(n, 1);
        if (sumOdd >= sumEven) {
            for (int i = 1; i < n; i += 2) {
                b[i] = a[i];
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                b[i] = a[i];
            }
        }
        for (int i = 0; i < n ;i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0; 
}