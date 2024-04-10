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
        int n, kol = 0;
        cin >> n;
        vector <vector <char>> a(n, vector <char> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] != '.') ++kol;
            }
        }
        vector <int> x(3), o(3);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '.') continue;
                if (a[i][j] == 'X') {
                    ++x[(i + j) % 3];
                } else {
                    ++o[(i + j) % 3];
                }
            }
        }
        bool f = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j || f) continue;
                if ((x[i] + o[j]) <= kol / 3) {
                    f = true;
                    for (int k = 0; k < n; ++k) {
                        for (int g = 0; g < n; ++g) {
                            if (a[k][g] == 'X') {
                                if ((k + g) % 3 == i) cout << 'O';
                                else cout << 'X';
                            } else if (a[k][g] == 'O') {
                                if ((k + g) % 3 == j) cout << 'X';
                                else cout << 'O';
                            } else cout << '.';
                        }
                        cout << "\n";
                    }
                }
            }
        }
        assert(f);
    }
}