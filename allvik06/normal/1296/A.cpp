#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, sum = 0, ch = -1, nech = -1;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0) {
                ch = j;
            }
            else {
                nech = j;
            }
            sum += tmp;
        }
        if (sum % 2 == 1) {
            cout << "YES\n";
        }
        else if (nech != -1 && ch != -1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}