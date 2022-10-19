#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> w(k);
        for (int i = 0; i < k; ++i)
            cin >> w[i];
        sort(a.begin(), a.end());
        sort(w.rbegin(), w.rend());
        int ans = 0;
        int ind = 0;
        for (int i = n - 1; i >= n - k; --i) {
            ans += a[i];
            if (w[w.size() - (n - i - 1) - 1] == 1)
                ans += a[i];
        }
        for (int i = 0; i < k; ++i) {
            if (w[i] == 1)
                break;
            ans += a[ind];
            ind += w[i] - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}