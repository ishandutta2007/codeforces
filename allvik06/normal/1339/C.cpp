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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int maxx = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) continue;
            int tmp = a[i - 1] - a[i];
            maxx = max(maxx, (int)log2(tmp) + 1);
            a[i] = a[i - 1];
        }
        cout << maxx << "\n";
    }
    return 0;
}