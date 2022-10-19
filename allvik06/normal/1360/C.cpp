#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        int kolc = 0, koln = 0;
        for (int &i : a) cin >> i;
        for (int i : a) {
            if (i % 2 == 0) ++kolc;
            else ++koln;
        }
        if (kolc % 2 == 0 && koln % 2 == 0) {
            cout << "YES\n";
            continue;
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(a[i] - a[j]) == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}