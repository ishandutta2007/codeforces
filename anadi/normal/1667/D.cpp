#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n;
bool dp[N][2];
vector <int> G[N];
vector <pair <int, int> > ans;

void solve_dp(int u, int p)
{
    int zeroes = 0, ones = 0, both = 0, none = 0;
    for (auto v: G[u]) {
        if (v != p) {
            solve_dp(v, u);
            if (dp[v][0] && dp[v][1]) {
                both++;
            } else if (dp[v][0]) {
                zeroes++;
            } else if (dp[v][1]) {
                ones++;
            } else {
                none++;
            }
        }
    }

    if (none) {
        return;
    }

    int deg = G[u].size();
    int need_one = (deg + 1) / 2;
    int need_zero = deg / 2;

    need_zero -= zeroes;
    need_one -= ones;

    if (need_zero < 0 || need_one < 0) {
        return;
    }

    if (u == 1) {
        dp[u][0] = dp[u][1] = true;
    }

    if (need_zero != 0) {
        dp[u][0] = true;
    }

    if (need_one != 0) {
        dp[u][1] = true;
    }

    // printf("dp[%d][0] = %d, dp[%d][1] = %d\n", u, dp[u][0], u, dp[u][1]);
}

void restore(int u, int p, int up)
{
    vector <int> zeroes, ones, both;
    for (auto v: G[u]) {
        if (v == p) {
            continue;
        }

        if (dp[v][0] && dp[v][1]) {
            both.push_back(v);
        } else if (dp[v][0]) {
            zeroes.push_back(v);
        } else if (dp[v][1]) {
            ones.push_back(v);
        }
    }

    int deg = G[u].size();
    while (deg > 0) {
        if (deg & 1) {
            if (up == 1) {
                ans.push_back({u, p});
                up = -1;
            } else if (ones.size()) {
                int v = ones.back();
                ones.pop_back();
                restore(v, u, 1);
            } else {
                int v = both.back();
                both.pop_back();
                restore(v, u, 1);
            }
        } else {
            if (up == 0) {
                ans.push_back({u, p});
                up = -1;
            } else if (zeroes.size()) {
                int v = zeroes.back();
                zeroes.pop_back();
                restore(v, u, 0);
            } else {
                int v = both.back();
                both.pop_back();
                restore(v, u, 0);
            }
        }

        deg--;
    }
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        dp[i][0] = dp[i][1] = false;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    solve_dp(1, 1);
    if (!dp[1][0]) {
        puts("NO");
        return;
    }

    puts("YES");
    ans.clear();
    restore(1, 1, -1);

    for (auto [u, v]: ans) {
        printf("%d %d\n", u, v);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}