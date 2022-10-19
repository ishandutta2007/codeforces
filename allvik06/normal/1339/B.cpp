#include <bits/stdc++.h>

using namespace std;

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
        sort(a.begin(), a.end());
        vector <int> ans(n);
        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if ((n - i) % 2 == 1) {
                ans[i] = a[r];
                --r;
            }
            else {
                ans[i] = a[l];
                ++l;
            }
        }
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}