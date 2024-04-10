#include <bits/stdc++.h>

using namespace std;

int res(int n, int tmp) {
    int size = sqrt(n);
    for (int i = 2; i <= size; ++i) {
        if (n % i == 0 && i != tmp && n / i != tmp) {
            if (tmp != 0 && i == n / i) {
                continue;
            }
            return i;
        }
    }
    return -1;
}
signed main() {
    int t;
    cin >> t;
    ++t;
    while (--t) {
        int n;
        cin >> n;
        int a = res(n, 0);
        if (a == n || a == -1) {
            cout << "NO\n";
            continue;
        }
        int b = res(n / a, a);
        int c = n / a / b;
        if (b > 1 && c > 1) {
            cout << "YES\n" << a << " " << b << " " << c << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}