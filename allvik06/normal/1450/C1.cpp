#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <char>> a(n, vector <char> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int kol1 = 0, kol2 = 0, kol3 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '.') continue;
                if ((i + j) % 3 == 0) ++kol1;
                else if ((i + j) % 3 == 1) ++kol2;
                else if ((i + j) % 3 == 2) ++kol3;
            }
        }
        int maxx = min(kol1, min(kol2, kol3)), ans;
        if (kol1 == maxx) ans = 0;
        else if (kol2 == maxx) ans = 1;
        else ans = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 'X' && (i + j) % 3 == ans) cout << "O";
                else cout << a[i][j];
            }
            cout << "\n";
        }
    }
}