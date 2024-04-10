#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int INF = 1e9;

signed main() {
    int q, n;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        cin >> n;
        vector <int> a(n);
        for (int i  = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector <bool> used(n);
        int flag = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            cout << 2 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }
}