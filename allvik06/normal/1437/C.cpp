#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <set>

using namespace std;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        sort(a.begin(), a.end());
        vector <vector <int>> dp(n, vector <int> (2 * n, INF));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = abs(i - a[0]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                for (int k = 0; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - j));
                }
            }
        }
        cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
    }
}