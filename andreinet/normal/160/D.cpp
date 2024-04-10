#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

const int Nmax = 100005;

struct Edge {
    int from, to, cost, pos;

    Edge() {}
    Edge(const int x, const int y, const int _cost, const int _pos):
        from(x), to(y), cost(_cost), pos(_pos) {}

    bool operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

Edge edges[Nmax];
int Father[Nmax], Ans[Nmax];

vector<pair<int, int>> G[Nmax];

int Find(int x) {
    int y, p;
    for (y = Father[x]; Father[y] != y; y = Father[y]);
    for (; x != y; x = p) {
        p = Father[x];
        Father[x] = y;
    }
    return y;
}

void Union(int x, int y) {
    Father[Find(x)] = Find(y);
}

int Lvl[Nmax], Lvlmin[Nmax];
bool used[Nmax];

void Dfs(const int node, const int father) {
    Lvlmin[node] = Lvl[node];
    used[node] = true;

    for (auto& edge: G[node]) {
        int p = edge.first, ind = edge.second;

        if (p == father) continue;

        if (used[p]) {
            Lvlmin[node] = min(Lvlmin[node], Lvl[p]);
            if (Lvl[p] > Lvl[node]) Ans[ind] = 2;
        } else {
            Lvl[p] = Lvl[node] + 1;
            Dfs(p, node);
            Lvlmin[node] = min(Lvlmin[node], Lvlmin[p]);
            if (Lvlmin[p] > Lvl[node]) Ans[ind] = 1;
            else Ans[ind] = 2;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y, cost;
        cin >> x >> y >> cost;

        edges[i] = Edge(x, y, cost, i);
    }
    sort(edges, edges + M);

    for (int i = 1; i <= N; ++i)
        Father[i] = i;

    for (int from = 0, to = 1; from < M; from = to) {
        while (to < M && edges[to].cost == edges[from].cost) ++to;
        int root = 0;
        for (int i = from; i < to; ++i) {
            if (Find(edges[i].from) == Find(edges[i].to)) continue;
            int x = Find(edges[i].from), y = Find(edges[i].to);
            G[x].push_back({y, edges[i].pos});
            G[y].push_back({x, edges[i].pos});
            root = x;
        }
        if (root > 0) {
            Lvl[root] = 0;
            Dfs(root, 0);
        }
        for (int i = from; i < to; ++i) {
            if (Find(edges[i].from) == Find(edges[i].to)) continue;
            int x = Find(edges[i].from), y = Find(edges[i].to);
            if (used[x]) {
                used[x] = false;
                sort(G[x].begin(), G[x].end());
                for (int i = 1; i < int(G[x].size()); ++i)
                    if (G[x][i].first == G[x][i - 1].first)
                        Ans[G[x][i].second] = Ans[G[x][i - 1].second] = 2;
                G[x].clear();
            }
            x = y;
            if (used[x]) {
                used[x] = false;
                sort(G[x].begin(), G[x].end());
                for (int i = 1; i < int(G[x].size()); ++i)
                    if (G[x][i].first == G[x][i - 1].first)
                        Ans[G[x][i].second] = Ans[G[x][i - 1].second] = 2;
                G[x].clear();
            }
        }
        for (int i = from; i < to; ++i)
            Union(edges[i].from, edges[i].to);
    }

    for (int i = 0; i < M; ++i)
        puts(Ans[i] == 0 ? "none": (Ans[i] == 1 ? "any": "at least one"));
}