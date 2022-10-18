#include<bits/stdc++.h>

using namespace std;

char a[10][10];

vector < pair < int, int > > Q = {{1, 1}, {2, 4}, {3, 7}, {4, 2}, {5, 5}, {6, 8}, {7, 3}, {8, 6}, {9, 9}};

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; ++j) cin >> a[i][j];
        }
        for (auto key : Q) {
            int f = a[key.first][key.second] - '0';
            f++;
            if (f > 9) f -= 9;
            a[key.first][key.second] = char('0' + f);
        }
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; ++j) cout << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}