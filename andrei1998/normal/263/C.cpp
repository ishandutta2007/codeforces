#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;

vector <pair <int, int> > edges;
set <pair <int, int> > edges_Set;
vector <int> graph[NMAX];

bool vecini(int node1, int node2) {
    vector <int> commons;

    for (auto it1: graph[node1])
        for (auto it2: graph[node2])
            if (it1 == it2)
                commons.push_back(it1);

    return (commons.size() == 2);
}

vector <int> real_graph[NMAX];

bool vis[NMAX];
vector <int> dfs_order;
void dfs(int node) {
    dfs_order.push_back(node);
    vis[node] = true;
    for (auto it: real_graph[node])
        if (!vis[it])
            dfs(it);
}

vector <pair <int, int> > real_edges;

set <pair <int, int> > inserts;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int a, b;
    for (int i = 1; i <= 2 * n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

        if (b < a)
            swap(a, b);
        edges.push_back(make_pair(a, b));
        edges_Set.insert(make_pair(a, b));
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; ++ i)
        if (graph[i].size() != 4) {
            cout << "-1\n";
            return 0;
        }

    if (n == 5) {
        for (int i = 1; i <= n; ++ i)
            cout << i << " \n"[i == n];
        return 0;
    }
    else if (n == 6) {
        bool used[10] = {0};
        vector <pair <int, int> > non_edges;
        for (int i = 1; i <= 6; ++ i)
            for (int j = i + 1; j <= 6; ++ j)
                if (!edges_Set.count(make_pair(i, j))) {
                    non_edges.push_back(make_pair(i, j));
                    if (used[i] || used[j]) {
                        cout << "-1\n";
                        return 0;
                    }
                    used[i] = true;
                    used[j] = true;
                }

        for (int i = 0; i < 3; ++ i)
            cout << non_edges[i].first << ' ';
        for (int i = 0; i < 3; ++ i)
            cout << non_edges[i].second << " \n"[i == 2];
        return 0;
    }

    pair <int, int> y;
    for (int i = 1; i <= n; ++ i) {
        for (auto it: graph[i]) {
            if (vecini(i, it)) {
                real_graph[i].push_back(it);

                if (i > it)
                    inserts.insert(make_pair(it, i));
                else
                    inserts.insert(make_pair(i, it));
            }
        }
    }

    if (inserts.size() != n) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
        if (real_graph[i].size() != 2) {
            cout << "-1\n";
            return 0;
        }

    dfs(1);
    if (dfs_order.size() != n) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; ++ i) {
        for (auto it: real_graph[i]) {
            a = i;
            b = it;

            if (b < a)
                swap(a, b);
            real_edges.push_back(make_pair(a, b));
        }

        a = real_graph[i][0];
        b = real_graph[i][1];

        if (b < a)
            swap(a, b);
        real_edges.push_back(make_pair(a, b));
    }

    sort(real_edges.begin(), real_edges.end());
    real_edges.resize(unique(real_edges.begin(), real_edges.end()) - real_edges.begin());

    if (real_edges != edges) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < dfs_order.size(); ++ i)
        cout << dfs_order[i] << " \n"[i + 1 == dfs_order.size()];
    return 0;
}