#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
int n, dist[N];

void bfs (void) {
    memset(dist, -1, sizeof dist);
    queue <int> Q; Q.push(1); dist[1] = 0;
    while (not Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", dist[i]);
    printf("\n");
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int j; scanf("%d", &j);
        if (j != i) g[i].push_back(j);
        if (i != n) {
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
        }
    }
    bfs();
    return 0;
}