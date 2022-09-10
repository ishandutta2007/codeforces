#include <bits/stdc++.h>

using namespace std;

const int N = 407;
const int MOD = 998'244'353;

int n, m;
int ans[N][N];
int dist[N][N];
vector <int> G[N];

bool good[N];
int par[N], can[N];

bool is_par[N];
int tmp_can[N];
int tmp_dist[N];
vector <int> T[N];

void bfs(int s)
{
    for (int i = 1; i <= n; ++i)
        dist[s][i] = -1;
    dist[s][s] = 0;

    queue <int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (auto v: G[u]) {
            if (dist[s][v] == -1) {
                dist[s][v] = dist[s][u] + 1;
                Q.push(v);
            }
        }
    }
}

void prepare(int s)
{
    for (int i = 1; i <= n; ++i) {
        T[i].clear();
        par[i] = -1;
        good[i] = false;
        can[i] = 0;
    }

//    printf("prepares %d\n", s);
    for (int i = 1; i <= n; ++i) {
        for (auto v: G[i]) {
            if (dist[s][v] == dist[s][i] + 1) {
                T[i].push_back(v);
//                printf("%d -> %d\n", i, v);
            }

            if (dist[s][v] == dist[s][i] - 1) {
                par[i] = v;
                can[i]++;
            }
        }
    }

    queue <int> Q;
    Q.push(s);
    good[s] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (auto v: T[u]) {
            if (can[v] == 1) {
                good[v] = true;
                Q.push(v);
            }
        }
    }
}

int bfs2(int s, int src)
{
    for (int i = 1; i <= n; ++i) {
        tmp_dist[i] = -1;
        tmp_can[i] = 0;
        is_par[i] = false;
    }

    queue <int> Q;
    Q.push(src);

    int ret = 1;
    tmp_can[src] = 1;
    tmp_dist[src] = 0;
    is_par[src] = true;

    auto add = [&](int u, int v) {
        if (tmp_dist[v] == -1) {
            tmp_dist[v] = tmp_dist[u] + 1;
            Q.push(v);
        }

        if (tmp_dist[v] == tmp_dist[u] + 1) {
            tmp_can[v]++;
        }
    };

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

//        printf("%d :: %d %d\n", u, tmp_dist[u], tmp_can[u]);
        
        ret = 1LL * ret * tmp_can[u] % MOD;
        if (tmp_dist[u] != dist[src][u]) {
            return 0;
        }

        if (par[u] != -1 && is_par[u]) {
            is_par[par[u]] = true;
            add(u, par[u]);
        }

        for (auto v: T[u]) {
            add(u, v);
        }
    }

    return ret;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        bfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        prepare(i);
        for (int j = 1; j <= n; ++j) {
            ans[i][j] = good[j] ? bfs2(i, j) : 0;
            printf("%d%c", ans[i][j], " \n"[j == n]);
        }
    }
    
    return 0;
}