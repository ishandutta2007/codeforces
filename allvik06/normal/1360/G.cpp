#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
#define ll long long

int main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int ans[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = 0;
            }
        }
        int last = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a; ++j, last = (last + 1) % m) {
                ans[i][last] = 1;
            }
        }
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                s += ans[j][i];
            }
            if (s != b) ok = false;
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        } else cout << "NO\n";
    }
}