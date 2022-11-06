#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
string grid[MxN + 9];
int dp[MxN + 9][MxN + 9];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    memset(dp, -1, sizeof dp);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];


    queue<pair<int, int>> cells;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            bool ok = false;
            for (int x = max(0, i - 1); x <= min(n - 1, i + 1); ++x)
                for (int y = max(0, j - 1); y <= min(m - 1, j + 1); ++y) {
                    if (abs(i - x) + abs(j - y) != 1) continue;
                    if (grid[i][j] != grid[x][y]) continue;
                    ok = true;
                }
            if (ok) {
                dp[i][j] = 0;
                cells.emplace(i, j);
            }
        }

    DBG(cells.size())
    while (!cells.empty()) {
        int i = cells.front().first;
        int j = cells.front().second;
        cells.pop();
        for (int x = max(0, i - 1); x <= min(n - 1, i + 1); ++x)
            for (int y = max(0, j - 1); y <= min(m - 1, j + 1); ++y) {
                if (abs(i - x) + abs(j - y) != 1) continue;
                if (dp[x][y] != -1) continue;
                dp[x][y] = dp[i][j] + 1;
                cells.emplace(x, y);
            }
    }

    while (q--) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        --i, --j;
        int ans = dp[i][j] == -1 || dp[i][j] >= p ? 0 : (p - dp[i][j]) & 1;
        ans ^= grid[i][j] - '0';
        cout << ans << '\n';
    }

    return 0;
}