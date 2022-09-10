#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n, m, a, b;
bool block[N];

bool vis[N];
vector <int> G[N];

int cnt = 0;
void dfs(int u)
{
    ++cnt;
    vis[u] = true;

    for (auto v: G[u]) {
        if (!block[v] && !vis[v]) {
            dfs(v);
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            block[i] = vis[i] = false;
        }

        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);

            G[u].push_back(v);
            G[v].push_back(u);
        }

        cnt = 0;
        block[a] = true;
        dfs(b);

        long long ans = n - cnt - 1;
        
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
        }

        block[a] = false;
        block[b] = true;
        dfs(a);

        ans *= n - cnt - 1;
        printf("%lld\n", ans);
    }

    return 0;
}