#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> used;
vector<int> d;
vector<pair<int, int>> backEdges;

void dfs(int v) {
    used[v] = 1;
    for (size_t i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i].first]) {
            d[g[v][i].first] = d[v] ^ g[v][i].second;
            dfs(g[v][i].first);
        } else {
            backEdges.push_back({v, i});
        }
    }
}

vector<int> basis;

void gauss() {
    for (size_t i = 0; i < basis.size(); i++) {
        for (size_t j = i; j < basis.size(); j++) {
            if (basis[i] < basis[j])
                swap(basis[i], basis[j]);
        }
        for (size_t j = i + 1; j < basis.size(); j++) {
            basis[j] = min(basis[j], basis[i] ^ basis[j]);
        }
    }
}

bool isIndependentWith(int x) {
    for (int el : basis)  {
        x = min(x, x ^ el);
    }
    return x > 0;
}

int main() {
    cin >> n;
    g.resize(n);
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    used.resize(n);
    d.resize(n);
    dfs(0);
    for (auto &el : backEdges) {
        int a = el.first;
        int b = g[a][el.second].first;
        int c = g[a][el.second].second ^ d[a] ^ d[b];
        if (isIndependentWith(c)) {
            basis.push_back(c);
            gauss();
        }
    }
    int cur = d[n - 1];
    for (int el : basis) {
        cur = min(cur, cur ^ el);
    }
    cout << cur << endl;
}