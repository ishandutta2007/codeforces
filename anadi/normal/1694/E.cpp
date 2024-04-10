#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n, m;
int rem[N];
int dist[N];
bool vis[N];

vector <int> G[N];
priority_queue <pair <int, int> > Q;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int v, u;
        scanf("%d %d", &v, &u);

        if (v == n) {
            continue;
        }

        rem[v]++;
        G[u].push_back(v);
    }

    for (int i = 1; i < n; ++i) {
        dist[i] = n + m;
    }

    dist[n] = 0;
    Q.push({0, n});

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        if (vis[u]) {
            continue;
        }

        vis[u] = true;
        for (auto v: G[u]) {
            if (vis[v]) {
                continue;
            }

            rem[v]--;
            if (dist[v] > rem[v] + dist[u] + 1) {
                dist[v] = rem[v] + dist[u] + 1;
                Q.push({-dist[v], v});
            }
        }
    }

    printf("%d\n", dist[1]);
    return 0;
}