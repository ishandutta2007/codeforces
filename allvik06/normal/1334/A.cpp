#include <bits/stdc++.h>

using namespace std;
//#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        bool flag = true;
        if (a[0].first < a[0].second) {
            flag = false;
        }
        for (int i = 1; i < n; ++i) {
            if (a[i].first - a[i - 1].first < a[i].second - a[i - 1].second) {
                flag = false;
                break;
            }
            if (a[i].first < a[i - 1].first || a[i].second < a[i - 1].second) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}