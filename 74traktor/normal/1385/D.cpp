#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
string s;
map < pair < int, int >, int > dp[27];
int pref[27][maxn];

inline int get_s(int l, int r, int c) {
    return pref[c][r + 1] - pref[c][l];
}

int dfs(int l, int r, int c) {
    if (dp[c].find({l, r}) != dp[c].end()) return dp[c][{l, r}];
    if (l == r) {
        if (s[l] == char('a' + c)) return 0;
        return 1;
    }
    int m = (r + l) / 2;
    dp[c][{l, r}] = min(dfs(l, m, c + 1) + get_s(m + 1, r, c), dfs(m + 1, r, c + 1) + get_s(l, m, c));
    return dp[c][{l, r}];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 27; ++i) dp[i] = {};
        cin >> n >> s;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = pref[i][j - 1];
                if (s[j - 1] != char('a' + i)) pref[i][j]++;
            }
        }
        cout << dfs(0, n - 1, 0) << '\n';
    }
    return 0;
}