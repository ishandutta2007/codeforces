#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = n;
        if (n == 1) {
            cout << "FastestFinger\n";
            continue;
        }
        if (n % 2 == 1 || n == 2) {
            cout << "Ashishgup\n";
            continue;
        }
        while (x % 2 == 0)
            x /= 2;
        int k = 0;
        for (int i = 3; i * i <= n; i += 2)
            while (x % i == 0) {
                x /= i;
                k++;
            }
        if (x != 1)
            k++;
        if (n % 4 != 2 && k != 0)
            cout << "Ashishgup\n";
        else {
            if (k == 0 || k == 1)
                cout << "FastestFinger\n";
            else
                cout << "Ashishgup\n";
        }
    }
    return 0;
}