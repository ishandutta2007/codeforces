#include <bits/stdc++.h>

using namespace std;

const int N = 3'007;
const int MOD = 1'000'000'007;

int n, m;
int balance[N];
vector <int> G[N];

int sz[N];
pair <int, long long> tmp[N];
pair <int, long long> dp[N][N];

void merge(int u, int v)
{
    for (int i = 1; i <= sz[u] + sz[v]; ++i) {
        tmp[i] = {-N, 0};
    }

    for (int i = 1; i <= sz[u]; ++i) {
        for (int j = 1; j <= sz[v]; ++j) {
            int comps = dp[u][i].first + dp[v][j].first + (dp[v][j].second > 0);
            tmp[i + j] = max(tmp[i + j], make_pair(comps, dp[u][i].second));

            comps = dp[u][i].first + dp[v][j].first;
            tmp[i + j - 1] = max(tmp[i + j - 1], make_pair(comps, dp[u][i].second + dp[v][j].second));
        }
    }

    sz[u] += sz[v];
    for (int i = 1; i <= sz[u]; ++i) {
        dp[u][i] = tmp[i];
    }
}

void dfs(int u, int p)
{
    sz[u] = 1;
    dp[u][1] = {0, balance[u]};

    for (auto v: G[u]) {
        if (v == p) {
            continue;
        }
        
        dfs(v, u);
        merge(u, v);
    }

/*    printf("%d -> ", u);
    for (int i = 1; i <= sz[u]; ++i) {
        printf("[%d %lld] ", dp[u][i].first, dp[u][i].second);
    }

    puts("");*/
}

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &balance[i]);
        balance[i] *= -1;
    }

    for (int i = 1; i <= n; ++i) {
        int w;
        scanf("%d", &w);
        balance[i] += w;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 1);
    printf("%d\n", dp[1][m].first + (dp[1][m].second > 0));
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