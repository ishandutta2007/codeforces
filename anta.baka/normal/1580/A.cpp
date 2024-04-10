#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

int to_zero(int i, int j, int i1, int j1, vector<vector<int>>& cnt) {
    return cnt[i1][j1] - (i ? cnt[i - 1][j1] : 0) - (j ? cnt[i1][j - 1] : 0) + (i && j ? cnt[i - 1][j - 1] : 0);
}

int to_one(int i, int j, int i1, int j1, vector<vector<int>>& cnt) {
    return (i1 - i + 1) * (j1 - j + 1) - to_zero(i, j, i1, j1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& s : a) {
            cin >> s;
        }
        vector<vector<int>> cnt(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[i][j] = (a[i][j] - '0') + (i > 0 ? cnt[i - 1][j] : 0) + (j > 0 ? cnt[i][j - 1] : 0) - (i > 0 && j > 0 ? cnt[i - 1][j - 1] : 0);
            }
        }
        int ans = n * m;
        for (int i = 0; i < n; i++) {
            for (int i1 = i + 4; i1 < n; i1++) {
                int low = to_one(i + 1, 0, i1 - 1, 0, cnt)
                        + to_one(i, 1, i, 2, cnt)
                        + to_one(i1, 1, i1, 2, cnt)
                        + to_zero(i + 1, 1, i1 - 1, 2, cnt);
                for (int j = 3; j < m; j++) {
                    ans = min(ans, low + to_one(i + 1, j, i1 - 1, j, cnt));
                    low += to_one(i, j, i, j, cnt)
                            + to_one(i1, j, i1, j, cnt)
                            + to_zero(i + 1, j, i1 - 1, j, cnt);
                    low = min(low,
                              to_one(i + 1, j - 2, i1 - 1, j - 2, cnt) +
                              to_one(i, j - 1, i, j, cnt) +
                              to_one(i1, j - 1, i1, j, cnt) +
                              to_zero(i + 1, j - 1, i1 - 1, j, cnt));
                }
            }
        }
        cout << ans << '\n';
    }

    cout.flush();
    return 0;
}