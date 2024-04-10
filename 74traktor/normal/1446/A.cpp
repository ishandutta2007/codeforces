#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, w;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        vector < pair < int, int > > a;
        vector < int > ans;
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            a.push_back({x, i});
        }
        sort(a.rbegin(), a.rend());
        for (auto key : a) {
            if (s + key.first <= w) s += key.first, ans.push_back(key.second);
        }
        if (s >= (w + 1) / 2) {
            cout << ans.size() << '\n';
            for (auto key : ans) cout << key << " ";
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}