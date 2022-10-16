#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

int n;
bool col[NMAX];
vector <int> graph[NMAX];

int dist[NMAX];
deque <int> dq;

int bfs(int node) {
    memset(dist, 0, sizeof dist);
    dq.clear();

    dist[node] = 1;
    dq.push_back(node);

    while (!dq.empty()) {
        node = dq.front();
        dq.pop_front();

        for (auto it: graph[node])
            if (!dist[it]) {
                if (col[node] != col[it]) {
                    dist[it] = 1 + dist[node];
                    dq.push_back(it);
                }
                else {
                    dist[it] = dist[node];
                    dq.push_front(it);
                }
            }
    }

    return node;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> col[i];

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int node = 1;
    node = bfs(node);
    node = bfs(node);

    int dst = dist[node];

    cout << dst / 2 << '\n';
    return 0;
}