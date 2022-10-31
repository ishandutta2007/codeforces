#include<bits/stdc++.h>

using namespace std;

char ans[55][55];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b;
        if (n * a != b * m) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        set < pair < int, int > > Q;
        for (int i = 1; i <= m; ++i) {
            Q.insert({b, i});
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) ans[i][j] = '0';
        }
        for (int i = 1; i <= n; ++i) {
            vector < pair < int, int > > add;
            for (int j = 1; j <= a; ++j) {
                auto p = (*Q.rbegin());
                Q.erase(p);
                ans[i][p.second] = '1';
                add.push_back(p);
            }
            for (auto key : add) Q.insert({key.first - 1, key.second});
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}