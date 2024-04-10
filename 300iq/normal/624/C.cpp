#include <bits/stdc++.h>

using namespace std;

int n, g[501][501], ans, mark[501], was[501], bad = 0, m, kol[501];

void dfs(int v, int pr, int color) {
    if (was[v] && mark[v] != color) {
        bad = true;
        return;
    }
    else if (was[v]) {
        return;
    }
    else {
        was[v] = true, mark[v] = color;
        for (int i = 1; i <= n; i++) {
            if (!g[v][i] && v != i && i != pr) {
                dfs(i, v, (3 - color));
            }
        }
    }
}

bool good(int a, int b) {
    return abs(a - b) <= 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        kol[v]++, kol[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (kol[i] != n - 1 && !was[i]) {
            dfs(i, 0, 1);
        }
    }
    if (bad) {
        cout << "No" << endl;
        return 0;
    }
    string f = "";
    for (int i = 1; i <= n; i++) 
        f += (mark[i] == 1 ? 'a' : (mark[i] == 0 ? 'b' : 'c'));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i + 1][j + 1] != good(f[i], f[j])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << f << endl;
    return 0;
}