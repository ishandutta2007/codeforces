#include <bits/stdc++.h>

using namespace std;
#define ll long long
inline int min(const int &a, const int &b) {
    if (a < b) return a;
    else return b;
}

const ll mod = 1e9 + 7;
const int INF = 1e9;
inline int solve1(int n, int m, vector <vector <int>> &b) {
    if (n > 3 && m > 3) return -1;
    if (n == 1 || m == 1) return 0;
    vector <vector <int>> a;
    if (n > m) {
        swap(n, m);
        a.assign(n, vector <int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = b[j][i];
            }
        }
    }
    else a = b;
    vector <int> dp(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][0] != ((i >> j) & 1)) ++cur;
        }
        dp[i] = cur;
    }
    vector <vector <int>> sov(1 << n);
    for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
            int cur = ((mask1 >> 0) & 1) + ((mask1 >> 1) & 1) + ((mask2 >> 0) & 1) + ((mask2 >> 1) & 1);
            if (cur % 2 == 0) continue;
            if (n == 2) {
                sov[mask1].push_back(mask2);
                continue;
            }
            cur = ((mask1 >> 2) & 1) + ((mask1 >> 1) & 1) + ((mask2 >> 2) & 1) + ((mask2 >> 1) & 1);
            if (cur % 2 == 0) continue;
            sov[mask1].push_back(mask2);
        }
    }
    vector <int> dp1((1 << n), INF);
    for (int i = 0; i < m - 1; ++i) {
        dp1.assign((1 << n), INF);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int tmp = 0;
            for (int j = 0; j < n; ++j) {
                if (((mask >> j) & 1) != a[j][i + 1]) ++tmp;
            }
            for (int mask1 : sov[mask]) dp1[mask] = min(dp1[mask], dp[mask1] + tmp);
        }
        dp.swap(dp1);
    }
    int minn = INF;
    for (int i = 0; i < (1 << n); ++i) {
        minn = min(minn, dp[i]);
    }
    if (minn == INF) return -1;
    else return minn;
}

inline void solve2(int n) {

}

signed main() {
    srand(time(0));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> a(n, vector <int> (m));
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j < m; ++j) {
                a[i][j] = s[j] - '0';
            }
        }
        cout << solve1(n, m, a);
    }
    else {

    }
}