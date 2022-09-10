#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

struct Matching {
    int n; vector < int > *G, match, vis;
    bool dfs(int v) {
        vis[v] = 1;
        for(auto u: G[v]) if(!match[u] || (!vis[match[u]] && dfs(match[u]))) {
                match[v] = u; match[u] = v; return true;
        }
        return false;
    }
    Matching(int N, vector < int > *g) : n(N), G(g) {
        match.resize(n + 1, 0), vis.resize(n + 1, 0); bool ok = 1;
        while(ok) {
            ok = 0;
            for(int i = 1; i <= n; i++) if(!match[i] && dfs(i)) ok = 1;
            for(int i = 1; i <= n; i++) vis[i] = 0;
        }
    }
};

const int N = 1'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

int n, m;
int in[N];
vector <int> G[N];

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        if (2 * in[i] >= m) {
            puts("-1");
            exit(0);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (3 * in[i] <= m) {
            continue;
        }

        for (int j = 1; j <= n; ++j) {
            if (2 * in[i] + in[j] <= m && in[i] % in[j] == 0) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    Matching M(n, G);
    vector <pair <int, int> > ans;

    for (int i = 1; i <= n; ++i) {
        if (3 * in[i] <= m) {
            if (!M.match[i]) {
                ans.push_back({3 * in[i], 2 * in[i]});
            }

            continue;
        }

        if (M.match[i]) {
            int j = M.match[i];
            ans.push_back({2 * in[i] + in[j], in[i] + in[j]});
        } else {
            puts("-1");
            exit(0);
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto [l, r]: ans) {
        printf("%d %d\n", l, r);
    }
}

int main()
{
    int cases = 1;
//    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}