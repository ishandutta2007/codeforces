#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g;

vector<int> isLeaf, hasNeighborLeaf;
vector<int> par;
set<int> s;

void dfs(int v, int p, int depth) {
    par[v] = p;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, depth + 1);
        }
    }
    isLeaf[v] = g[v].size() == 1;
    if (isLeaf[v]) {
        s.insert(depth % 2);
    }
}

signed main() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    isLeaf.resize(n);
    hasNeighborLeaf.resize(n);
    par.resize(n);
    dfs(0, -1, 0);
    if (s.size() == 1) {
        cout << 1;
    } else {
        cout << 3;
    }
    cout << " ";
    int cntLeafs = 0;
    int cntHasNeighbor = 0;
    if (g[0].size() == 1)
        isLeaf[0] = 1;
    for (int el : isLeaf) {
        cntLeafs += el;
    }
    for (int i = 0; i < n; i++) {
        if (isLeaf[i])
            continue;
        int good = 0;
        for (int u : g[i]) {
            if (isLeaf[u]) {
                good = 1;
            }
        }
        hasNeighborLeaf[i] = good;
    }
    for (int el : hasNeighborLeaf) {
        cntHasNeighbor += el;
    }
    cout << n - 1 - cntLeafs + cntHasNeighbor;
}