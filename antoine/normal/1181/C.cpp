#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
char grid[MxN + 9][MxN + 9];
int dp[MxN + 9][MxN + 9];
int sz[MxN + 9][MxN + 9];

void f(const int i, const int j) {
    sz[i][j] = 1;
    for (int k = 0; k < dp[i][j]; ++k)
        if (grid[i + k][j] != grid[i + k][j - 1])
            return;
    sz[i][j] += sz[i][j-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (grid[i] + 1);

    ll ans = 0;
    for (int j = 1; j <= m; ++j) {
        static int cnt[MxN + 9];
        for (int i = n; i >= 1; --i) {
            cnt[i] = 1 + (grid[i][j] == grid[i + 1][j] ? cnt[i + 1] : 0);
            if (cnt[i + cnt[i]] == cnt[i] && cnt[i + 2 * cnt[i]] >= cnt[i]) {
                dp[i][j] = 3 * cnt[i];
                f(i, j);
                ans += sz[i][j];
               // cerr << i << ' ' << j << ' ' << sz[i][j] << endl;
            }
        }
    }
    cout << ans;
    return 0;
}