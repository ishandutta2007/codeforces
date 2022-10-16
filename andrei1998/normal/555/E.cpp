#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define NMAX 200005
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

void dfs2 (int node, int cul) {
    culs[node] = cul;
    for (auto it: graph[node])
        if (!edges[it].critical && !culs[edges[it].other(node)])
            dfs2(edges[it].other(node), cul);
}

vector <int> new_graph[NMAX];

int parc[2 * NMAX];
int first[NMAX];
int h2[NMAX];
int pos;

void dfs3 (int node) {
    //cout << "dfs3 " << node << endl;
    parc[++ pos] = node;
    first[node] = pos;
    vis[node] = true;

    for (auto it: new_graph[node])
        if (!vis[it]) {
            h2[it] = 1 + h2[node];

            dfs3(it);
            parc[++ pos] = node;
        }
}

int logar[2 * NMAX];
int dp[19][2 * NMAX];

inline void rmq () {
    for (int i = 2; i <= pos + 1; i++)
        logar[i] = logar[i >> 1] + 1;

    for (int i = 1; i <= pos; i++)
        dp[0][i] = parc[i];

    int j;
    for (int i = 1; (1 << i) <= pos; i++)
        for (j = 1; j + (1 << i) - 1 <= pos; j++)
            if (h2[dp[i - 1][j]] < h2[dp[i - 1][j + (1 << (i - 1))]])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j + (1 << (i - 1))];
}

inline int lca (int a, int b) {
    a = first[a];
    b = first[b];

    if (b < a)
        swap(a, b);

    int l = logar[b - a + 1];

    if (h2[dp[l][a]] < h2[dp[l][b - (1 << l) + 1]])
        return dp[l][a];
    return dp[l][b - (1 << l) + 1];
}

int sus[NMAX];
int jos[NMAX];

void dfs4 (int node) {
    vis[node] = true;
    for (auto it: new_graph[node])
        if (!vis[it]) {
            dfs4(it);

            sus[node] += sus[it];
            jos[node] += jos[it];
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].a >> edges[i].b;

        graph[edges[i].a].push_back(i);
        graph[edges[i].b].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(1, 0);

    int cul = 0;
    for (int i = 1; i <= n; i++)
        if (!culs[i])
            dfs2(i, ++ cul);

    //for (int i = 1; i <= n; i++)
    //    cout << i << ' ' << culs[i] << endl;

    for (int i = 1; i <= m; i++) {
        edges[i].a = culs[edges[i].a], edges[i].b = culs[edges[i].b];

        if (edges[i].a == edges[i].b)
            continue;

        new_graph[edges[i].a].push_back(edges[i].b);
        new_graph[edges[i].b].push_back(edges[i].a);
//        cout << "noua muchie " << edges[i].a << ' ' << edges[i].b << endl;
    }

    n = cul;

    for (int i = 1; i <= n; i++)
        new_graph[0].push_back(i);

    memset(vis, 0, sizeof(vis));
    dfs3(0);

    /*cout << "pos = " << pos << endl;
    for (int i = 1; i <= pos; i++)
        cout << i << ' ' << parc[i] << endl;

    cout << "noduri  " << endl;
    for (int i = 0; i <= n; i++)
        cout << i << ' ' << first[i] << ' ' << h2[i] << endl;*/

    rmq();

    //for (int i = 0; i <= n; i++)
    //    for (int j = 0; j <= n; j++)
    //        cout << i << ' ' << j << ' ' << lca(i, j) << endl;

    int a, b, l;
    bool ok = true;
    while (q--) {
        cin >> a >> b;

        if (a == b)
            continue ;
        a = culs[a];
        b = culs[b];

        l = lca(a, b);

        if (!l) {
            ok = false;
            break;
        }

        sus[a] ++;
        sus[l] --;

        jos[b] ++;
        jos[l] --;
    }

    if (!ok) {
        cout << "No\n";
        return 0;
    }

    memset(vis, 0, sizeof(vis));
    dfs4(0);

    for (int i = 1; i <= n; i++)
        if (sus[i] && jos[i]) {
            cout << "No\n";
            return 0;
        }


    cout << "Yes\n";
    return 0;
}