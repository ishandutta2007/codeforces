#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int NMAX = 100005;

vector <int> graph[NMAX];

bool vis[NMAX];
int dist[NMAX];
int father[NMAX];

void dfs(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it]) {
            dist[it] = 1 + dist[node];
            father[it] = node;
            dfs(it);
        }

    int best_node;
    int best_dist = NMAX;
    for (auto it: graph[node])
        if (dist[it] < best_dist) {
            best_dist = dist[it];
            best_node = it;
        }

    cout << dist[node] - best_dist + 1 << '\n';
    while (node != best_node) {
        cout << node << ' ';
        node = father[node];
    }
    cout << node << endl;

    exit(0);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    while (m --) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    return 0;
}