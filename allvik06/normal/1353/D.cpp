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
        vector <int> ans(n);
        set <pair <int, int>> s;
        s.insert({n, 0});
        for (int i = 1; i <= n; ++i) {
            pair <int, int> now = *s.rbegin();
            s.erase(now);
            int l = -now.second, r = now.first - now.second - 1;
            int m = (l + r) / 2;
            ans[(l + r) / 2] = i;
            s.insert({m - l, -l});
            s.insert({r - m, -(m + 1)});
        }
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}