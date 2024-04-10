#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

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
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                if ((i + j) % 2 == 0) {
                    a[2 * i + 1][2 * j] = a[2 * i][2 * j + 1] = 1;
                } else {
                    a[2 * i][2 * j] = a[2 * i + 1][2 * j + 1] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

/*

 */