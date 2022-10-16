#include <iostream>
#include <algorithm>
#include <vector>

#define NMAX 1000015
using namespace std;

int n;
int h[NMAX];

vector <int> graph[NMAX];

int pos, parc[2 * NMAX];
int first[NMAX];

void dfs (int node) {
    parc[++ pos] = node;
    first[node] = pos;

    for (auto it: graph[node]) {
        h[it] = 1 + h[node];
        dfs(it);

        parc[++ pos] = node;
    }
}

int logar[2 * NMAX];
int dp[22][2 * NMAX];

inline void rmq () {
    for (int i = 2; i <= 2 * n; i++)
        logar[i] = 1 + logar[i >> 1];

    for (int i = 1; i <= pos; i++)
        dp[0][i] = parc[i];

    int j;
    for (int i = 1; (1 << i) <= pos; i++)
        for (j = 1; j + (1 << i) - 1 <= pos; j++)
            if (h[dp[i - 1][j]] < h[dp[i - 1][j + (1 << (i - 1))]])
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
    if (h[dp[l][a]] < h[dp[l][b - (1 << l) + 1]])
        return dp[l][a];
    return dp[l][b - (1 << l) + 1];
}

inline int dist (int a, int b) {
    int l = lca(a, b);

    return h[a] + h[b] - 2 * h[l];
}

int queries[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    n = 1;

    int q = 0;

    cin >> q; q--;

    int v;
    for (int i = 1; i <= q; i++) {
        cin >> v;

        graph[v].push_back(++ n);
        queries[i] = n;
    }

    dfs(1);
    rmq();

    int diam = 0;
    int node_a = 1;
    int node_b = 1;

    for (int i = 1; i <= q; i++) {
        if (dist(queries[i], node_a) > diam) {
            diam = dist(queries[i], node_a);
            node_b = queries[i];
        }
        else if (dist(queries[i], node_b) > diam) {
            diam = dist(queries[i], node_b);
            node_a =  queries[i];
        }

        cout << diam << ' ';
    }
    cout << endl;

    return 0;
}