#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n = nxt(), k = nxt();
    int d = n / k;
    if (n % k == 0) {
        --d;
    }
    if (n - d * k == 1) {
        cout << 2 * d << "\n";
        for (int i = 2; i <= k + 1; ++i) {
            cout << 1 << " " << i << "\n";
        }
        for (int i = k + 2; i <= n; ++i) {
            cout << i - k << " " << i << "\n";
        }
    } else if (k == 2) {
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; ++i) {
            cout << i - 1 << " " << i << "\n";
        }
    } else if (n - d * k == 2) {
        cout << 2 * d + 1 << "\n";
        cout << "1 2\n";
        for (int i = 3; i < k + 2; ++i) {
            cout << 1 << " " << i << "\n";
        }
        cout << 2 << " " << k + 2 << "\n";
        for (int i = k + 3; i <= n; ++i) {
            cout << i - k << " " << i << "\n";
        }
    } else {
        cout << 2 * d + 2 << "\n";
        for (int i = 1; i < n - d * k; ++i) {
            cout << 1 << " " << i + 1 << "\n";
        }
        for (int i = 1; i <= n - d * k; ++i) {
            cout << i << " " << i + n - d * k << "\n";
        }
        for (int i = n - d * k + 1; i <= k; ++i) {
            cout << n - d * k << " " << i + n - d * k << "\n";
        }
        for (int i = k + n - d * k + 1; i <= n; ++i) {
            cout << i - k << " " << i << "\n";
        }
    }
    
    return 0;
}