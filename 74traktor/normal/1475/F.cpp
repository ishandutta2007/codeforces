#include<bits/stdc++.h>

using namespace std;

int const maxn = 1005;
string a[maxn], b[maxn];
int c[maxn][maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] = "#" + a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            b[i] = "#" + b[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == b[i][j]) c[i][j] = 0;
                else c[i][j] = 1;
            }
        }
        int flag = 1, lst = 0;
        int f0 = -1, f1 = -1;
        /*for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << c[i][j];
            }
            cout << '\n';
        }*/
        for (int j = 1; j <= n; ++j) {
            if (c[1][j] == 0) {
                f0 = j;
                if (lst != 0) {
                    for (int i = 1; i <= n; ++i) {
                        if (c[i][j] != c[i][lst]) flag = 0;
                    }
                }
                lst = j;
            }
        }
        lst = 0;
        for (int j = 1; j <= n; ++j) {
            if (c[1][j] == 1) {
                f1 = j;
                if (lst != 0) {
                    for (int i = 1; i <= n; ++i) {
                        if (c[i][j] != c[i][lst]) flag = 0;
                    }
                }
                lst = j;
            }
        }
        if (f0 != -1 && f1 != -1) {
            for (int i = 1; i <= n; ++i) {
                if (c[i][f0] == c[i][f1]) flag = 0;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}