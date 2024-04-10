#include <bits/stdc++.h>

using namespace std;

int ans[1005][1005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < vector < int > > T = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
    int n, add = 0;
    cin >> n;
    for (int i = 1; i <= n; i += 4) {
        for (int j = 1; j <= n; j += 4) {
            for (int go1 = 0; go1 < 4; ++go1) {
                for (int go2 = 0; go2 < 4; ++go2) ans[i + go1][j + go2] = T[go1][go2] + add;
            }
            add += 16;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << ans[i][j] << " ";
        cout << '\n';
    }
    /*cout << '\n';
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        for (int j = 1; j <= n; ++j) x = (x^ans[j][i]);
        cout << x << '\n';
    }*/
    return 0;
}