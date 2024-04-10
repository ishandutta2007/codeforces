#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> a(n, vector <int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            int mx = 0;
            for (int j = 0; j < m; ++j) {
                if (mx > a[i][j]) {
                    x = j;
                }
                mx = max(mx, a[i][j]);
            }
            if (x != -1) {
                for (int j = 0; j < x; ++j) {
                    if (a[i][j] > a[i][x]) {
                        y = j;
                        break;
                    }
                }
                break;
            }
        }
        if (x == -1 && y == -1) cout << "1 1\n";
        else {
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                swap(a[i][x], a[i][y]);
                for (int j = 0; j < m - 1; ++j) {
                    if (a[i][j] > a[i][j + 1]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) cout << x + 1 << " " << y + 1 << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}