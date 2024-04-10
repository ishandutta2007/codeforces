#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100005;

vector<pair<int, int>> G[Nmax];
vector<pair<int, int>>::iterator steps[Nmax];
vector<int> order;
vector<bool> usedEdge;

void dfs(const int node) {
    for (auto& it = steps[node]; it != G[node].end(); ) {
        if (usedEdge[it->second]) {
            ++it;
            continue;
        }
        usedEdge[it->second] = true;
        dfs(it->first);
    }
    order.push_back(node);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int countEdges = 0;
    while (M-- > 0) {
        int x, y;
        cin >> x >> y;

        G[x].push_back({y, countEdges});
        G[y].push_back({x, countEdges});
        countEdges++;
    }
    
    int last = 0;
    for (int i = 1; i <= N; ++i) {
        if (G[i].size() % 2) {
            if (last == 0) last = i;
            else {
                G[i].push_back({last, countEdges});
                G[last].push_back({i, countEdges});
                countEdges++;
                last = 0;
            }
        }
    }

    if (countEdges & 1) {
        G[1].push_back({1, countEdges});
        G[1].push_back({1, countEdges});
        countEdges++;
    }

    usedEdge = vector<bool>(countEdges, false);
    for (int i = 1; i <= N; ++i) steps[i] = G[i].begin();
    dfs(1);

    cout << countEdges << '\n';

    for (int i = 0; i < int(order.size() - 1); ++i) {
        if ((i & 1) == 0)
            cout << order[i] << ' ' << order[i + 1] << '\n';
        else
            cout << order[i + 1] << ' ' << order[i] << '\n';
    }
}