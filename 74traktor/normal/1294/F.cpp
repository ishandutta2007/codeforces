#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn];
int dp[maxn][4];
int best[4];
vector < int > good[4];
vector < int > what[maxn][4];

void dfs(int v, int p) {
    dp[v][1] = 0;
    what[v][1] = {v};
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        for (int j = 0; j <= 3; ++j) best[j] = 0, good[j] = {};
        for (int cnt = 1; cnt <= 2; ++cnt) {
            for (int was = 0; was <= 2; ++was) {
                if (was + cnt > 3) continue;
                if (dp[v][was] + dp[u][cnt] + 1 > best[was + cnt]) {
                    good[was + cnt] = what[v][was];
                    for (auto key : what[u][cnt]) good[was + cnt].push_back(key);
                }
                best[was + cnt] = max(best[was + cnt], dp[v][was] + dp[u][cnt] + 1);
            }
        }
        for (int j = 0; j <= 3; ++j) {
            if (best[j] > dp[v][j]) what[v][j] = good[j];
            dp[v][j] = max(dp[v][j], best[j]);
        }
    }
    dp[v][3] = max(dp[v][3], dp[v][2]);
    if (dp[v][3] == dp[v][2]) {
        what[v][3] = what[v][2];
        what[v][3].push_back(v);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int answer = 1;
    //cout << dp[4][2] << '\n';
    for (int i = 1; i <= n; ++i) {
        if (dp[i][3] > dp[answer][3]) answer = i;
    }
    cout << dp[answer][3] << '\n';
    set < int > Q;
    for (auto key : what[answer][3]) Q.insert(key);
    while ((int)Q.size() < 3) {
        for (int i = 1; i <= min(n, 15); ++i) {
            if (Q.find(i) == Q.end()) {
                Q.insert(i);
                break;
            }
        }
    }
    for (auto key : Q) cout << key << " ";
    return 0;
}