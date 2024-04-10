#include<bits/stdc++.h>

using namespace std;

vector < vector < char > > a;
vector < vector < int > > pref, val, dp;
int n, m;

inline int get_sum(int lx, int ly, int rx, int ry) {
    if (lx <= 0 || ly <= 0 || rx > n || ry > m) return 0;
    return (pref[rx][ry] - pref[rx][ly - 1] - pref[lx - 1][ry] + pref[lx - 1][ly - 1]) == (rx - lx + 1) * (ry - ly + 1);
}

inline void add(int lx, int ly, int rx, int ry) {
    val[lx][ly]++;
    val[lx][ry + 1]--;
    val[rx + 1][ly]--;
    val[rx + 1][ry + 1]++;
}

inline int oks(int x) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) val[i][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (get_sum(i - x, j - x, i + x, j + x)) {
                add(i - x, j - x, i + x, j + x);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + val[i][j];
            assert(dp[i][j] >= 0);
            if (a[i][j] == 'X' && dp[i][j] == 0) return 0;
        }
    }
    return 1;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        a.emplace_back();
        pref.emplace_back();
        val.emplace_back();
        dp.emplace_back();
        for (int j = 0; j <= m + 1; ++j) {
            a.back().push_back('a');
            pref.back().push_back(0);
            val.back().push_back(0);
            dp.back().push_back(0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (a[i][j] == 'X') pref[i][j]++;
        }
    }
    int lef = -1, righ = max(n, m) + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (oks(mid)) lef = mid;
        else righ = mid;
    }
    cout << lef << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (get_sum(i - lef, j - lef, i + lef, j + lef)) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}