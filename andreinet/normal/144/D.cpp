#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 100005, Inf = 0x3f3f3f3f;

struct Edge {
    int x, y, cost;
    Edge(int _x, int _y, int _cost):
        x(_x), y(_y), cost(_cost) {};
};

vector<pair<int, int>> G[Nmax];
vector<Edge> edges;

int dist[Nmax];

void dijkstra(const int S) {
    memset(dist, Inf, sizeof dist);
    dist[S] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push({0, S});

    while (!Q.empty()) {
        int node = Q.top().second, cost = -Q.top().first;
        Q.pop();

        if (cost != dist[node]) continue;

        for (const pair<int, int>& p: G[node]) {
            if (dist[p.first] > cost + p.second) {
                dist[p.first] = cost + p.second;
                Q.push({-dist[p.first], p.first});
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M, S;
    cin >> N >> M >> S;

    while (M-- > 0) {
        int x, y, cost;
        cin >> x >> y >> cost;

        G[x].push_back({y, cost});
        G[y].push_back({x, cost});
        edges.push_back(Edge(x, y, cost));
    }
    int L;
    cin >> L;

    dijkstra(S);

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        if (dist[i] == L)
            ++ans;

    for (const Edge& p: edges) {
        int d1 = Inf, d2 = -Inf;
        if (dist[p.x] < L && dist[p.x] + p.cost > L)  {
            int ot = dist[p.y] + p.cost - (L - dist[p.x]);
            if (ot >= L) {
                d1 = L - dist[p.x];
                ++ans;
            }
        }
        if (dist[p.y] < L && dist[p.y] + p.cost > L) {
            int ot = dist[p.x] + p.cost - (L - dist[p.y]);
            if (ot >= L) {
                d2 = p.cost - (L - dist[p.y]);
                ++ans;
            }
        }
        if (d1 == d2) --ans;
    }
    cout << ans << '\n';
}