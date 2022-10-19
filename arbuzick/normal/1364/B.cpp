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
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        vector<int> used(n, 1);
        int pr = p.back();
        int ans = n;
        for (int i = n - 2; i > 0; --i) {
            if (p[i] > p[i - 1] && p[i] < pr) {
                used[i] = 0;
                ans--;
            }
            else if (p[i] < p[i - 1] && p[i] > pr) {
                used[i] = 0;
                ans--;
            }
            else
                pr = p[i];
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i)
            if (used[i])
                cout << p[i] << ' ';
        cout << "\n";
    }
    return 0;
}