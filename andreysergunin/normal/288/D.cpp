#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

vector< vector<int> > edge;
vector<long long> a, b, c, w;

long long sqr(long long a) {
    return a * a;
}

void dfs(int v, int p) {
    for (int i = 0; i < edge[v].size(); i++)
        if (edge[v][i] != p)
            dfs(edge[v][i], v);
    long long w1 = 0, w2 = 0, w3 = 0, w4 = 0;
    for (int i = 0; i < edge[v].size(); i++)
        if (edge[v][i] != p) {
            int u = edge[v][i];
            w1 += w[u];
            w2 += sqr(w[u]);
            w3 += w[u] * (w[u] - 1) / 2;
            w4 += sqr(w[u] * (w[u] - 1) / 2);
        }
    w[v] = 1;
    a[v] = (sqr(w3) - w4) / 2;
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] != p) {
            int u = edge[v][i];
            w[v] += w[u];
            c[v] += w[u] * (w[u] - 1) / 2;
            b[v] += (w[u] * (w[u] - 1) / 2) * (w1 - w[u]);
            b[v] += b[u] + c[u];
            a[v] += (w[u] * (w[edge[v][i]] - 1) / 2)
                            * ((w1 * w1 - w2) / 2 - w1 * w[u] + sqr(w[u]));
            a[v] += (b[u] + c[u]) * (w1 - w[u]);
            a[v] += a[u];
        }
    }
    a[v] += b[v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    edge.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    a.resize(n);
    b.resize(n);
    c.resize(n);
    w.resize(n);
    dfs(0, - 1);
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " " << b[i] << " " << c[i] << " " << w[i] << endl;
    cout << a[0] * 2 << endl;
    return 0;
}