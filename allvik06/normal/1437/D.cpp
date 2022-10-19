#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0, kol = 1;
        for (int i = 1; i < n;) {
            ++ans;
            int newkol = 0;
            for (int j = 0; j < kol; ++j) {
                if (i == n) break;
                ++newkol;
                int cur = a[i];
                ++i;
                while (i < n && a[i] > cur) {
                    cur = a[i];
                    ++i;
                    ++newkol;
                }
            }
            swap(newkol, kol);
        }
        cout << ans << "\n";
    }
}