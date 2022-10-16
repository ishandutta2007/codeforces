#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cassert>

#define NMAX 100005
#define WMAX 1000005
using namespace std;

struct edge {
    int a, b;
    int pos;

    edge (int a = 0, int b = 0, int pos = 0): a(a), b(b), pos(pos) {}
};

vector <edge> edges[WMAX];

int father[NMAX];
int h[NMAX];

inline void init (int n) {
    for (int i = 1; i <= n; i++)
        father[i] = i, h[i] = 1;
}

int f (int node) {
    if (father[node] != father[father[node]])
        father[node] = f(father[node]);
    return father[node];
}

inline void unite (int a, int b) {
    a = f(a);
    b = f(b);

    if (a == b)
        return ;

    if (h[a] < h[b])
        father[a] = b;
    else {
        if (h[a] == h[b])
            h[a] ++;
        father[b] = a;
    }
}

int ans[NMAX];

vector <pair <int, int> > graph[NMAX];
bitset <NMAX> vis;

int in[NMAX];
int low[NMAX];

void dfs (int node, int pos) {
    vis[node] = true;
    low[node] = in[node];

    for (auto it: graph[node])
        if (it.second != pos) {
            if (vis[it.first]) {
                if (in[it.first] < in[node]) {
                    low[node] = min(low[node], in[it.first]);
                    ans[it.second] = 1;
                }
            }
            else {
                in[it.first] = in[node] + 1;
                dfs(it.first, it.second);

                low[node] = min(low[node], low[it.first]);

                if (low[it.first] > in[node])
                    ans[it.second] = 2;
                else
                    ans[it.second] = 1;
            }
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    init(n);

    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;

        edges[c].push_back(edge(a, b, i));
    }

    int sum = 0;
    for (int i = 1; i < WMAX; i++) {
        int parcs = 0;

        for (auto &it: edges[i]) {
            it.a = f(it.a);
            it.b = f(it.b);

            if (it.a != it.b) {
                graph[it.a].push_back(make_pair(it.b, it.pos));
                graph[it.b].push_back(make_pair(it.a, it.pos));
            }
        }

        for (auto it: edges[i]) {
            if (!vis[it.a])
                dfs(it.a, 0);
            if (!vis[it.b])
                dfs(it.b, 0);
        }

        for (auto it: edges[i]) {
            graph[it.a].clear();
            graph[it.b].clear();

            vis[it.a] = vis[it.b] = 0;
            low[it.a] = low[it.b] = 0;

            unite(it.a, it.b);
        }
    }

    for (int i = 1; i <= m; i++)
        if (!ans[i])
            cout << "none\n";
        else if (ans[i] == 1)
            cout << "at least one\n";
        else
            cout << "any\n";

    return 0;
}