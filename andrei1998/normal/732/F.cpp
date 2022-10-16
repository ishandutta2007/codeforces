#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define NMAX 400005
using namespace std;

struct edge {
    int a, b;
    bool critical = false;

    inline int other (int node) {
        return a + b - node;
    }
} edges[NMAX];

vector <int> graph[NMAX];

int h[NMAX];
int low[NMAX];
bool vis[NMAX];

void dfs (int node, int edge_nr) {
    vis[node] = true;
    low[node] = h[node];

    for (auto it: graph[node])
        if (it != edge_nr) {
            if (!vis[edges[it].other(node)]) {
                h[edges[it].other(node)] = 1 + h[node];
                dfs(edges[it].other(node), it);

                if (low[edges[it].other(node)] > h[node])
                    edges[it].critical = true;
                else if (low[edges[it].other(node)] <= low[node])
                    low[node] = low[edges[it].other(node)];
            }
            else if (h[edges[it].other(node)] < low[node])
                low[node] = h[edges[it].other(node)];
        }
}

int culs[NMAX];
vector <int> culss[NMAX];

void dfs2 (int node, int cul) {
    culs[node] = cul;
    culss[cul].push_back(node);
    for (auto it: graph[node])
        if (!edges[it].critical && !culs[edges[it].other(node)])
            dfs2(edges[it].other(node), cul);
}

void dfs3(int node, int edge_nr) {
    vis[node] = true;

    for (auto it: graph[node])
        if (it != edge_nr) {
            if (!vis[edges[it].other(node)]) {
                if (edges[it].b != node)
                    swap(edges[it].a, edges[it].b);
                dfs3(edges[it].other(node), it);
            }
            else {
                if (edges[it].a != node)
                    swap(edges[it].a, edges[it].b);
            }
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].a >> edges[i].b;

        graph[edges[i].a].push_back(i);
        graph[edges[i].b].push_back(i);
    }

    dfs(1, 0);

    int cul = 0;
    for (int i = 1; i <= n; i++)
        if (!culs[i])
            dfs2(i, ++ cul);

    int root = 0;
    int sz = 0;
    for (int i = 1; i <= cul; ++ i) {
        if (culss[i].size() > sz) {
            root = culss[i].front();
            sz = culss[i].size();
        }
    }

    cout << sz << '\n';

    memset(vis, 0, sizeof vis);
    dfs3(root, 0);

    for (int i = 1; i <= m; ++ i)
        cout << edges[i].a << ' ' << edges[i].b << '\n';
    return 0;
}