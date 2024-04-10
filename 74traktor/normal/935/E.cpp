#include<bits/stdc++.h>

using namespace std;

int const maxn = 10005, maxk = 102;
vector < int > g[maxn], topsort;
pair < int, int > dp[maxn][maxk];
int used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) dfs(u);
    }
    topsort.push_back(v);
}

inline void upd(pair < int, int > &cur, pair < int, int > f) {
    cur.first = min(cur.first, f.first);
    cur.second = max(cur.second, f.second);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size(), p, m;
    cin >> p >> m;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxk; j++) dp[i][j] = {maxn * maxn, -maxn * maxn};
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            int bal = 0, j = i + 1;
            g[i].push_back(i + 1);
            while (1) {
                if (s[j] == '(') bal++;
                else if (s[j] == ')') bal--;
                if (bal == 0 && s[j] == '?') {
                    g[i].push_back(j + 1);
                    break;
                }
                j++;
            }
        } else if ('0' <= s[i] && s[i] <= '9') {
            dp[i][0] = {s[i] - '0', s[i] - '0'};
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i);
    }
    for (auto key : topsort) {
        if ((int)g[key].size() == 0) continue;
        for (int cntL = 0; cntL <= min(p, m); ++cntL) {
            for (int cntR = 0; cntR + cntL <= min(p, m); ++cntR) {
                if (p <= m) {
                    upd(dp[key][cntL + cntR + 1], {dp[g[key][0]][cntL].first + dp[g[key][1]][cntR].first, dp[g[key][0]][cntL].second + dp[g[key][1]][cntR].second});
                    upd(dp[key][cntL + cntR], {dp[g[key][0]][cntL].first - dp[g[key][1]][cntR].second, dp[g[key][0]][cntL].second - dp[g[key][1]][cntR].first});
                } else {
                    upd(dp[key][cntL + cntR], {dp[g[key][0]][cntL].first + dp[g[key][1]][cntR].first, dp[g[key][0]][cntL].second + dp[g[key][1]][cntR].second});
                    upd(dp[key][cntL + cntR + 1], {dp[g[key][0]][cntL].first - dp[g[key][1]][cntR].second, dp[g[key][0]][cntL].second - dp[g[key][1]][cntR].first});
                }
            }
        }
    }
    cout << dp[0][min(p, m)].second;
    return 0;
}