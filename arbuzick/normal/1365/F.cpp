#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
            cout << "No\n";
            continue;
        }
        vector<pair<int, int>> a1(n / 2), b1(n / 2);
        for (int i = 0; i < n / 2; ++i) {
            a1[i] = { min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1]) };
            b1[i] = { min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]) };
        }
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());
        if (a1 == b1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}