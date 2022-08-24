#include <bits/stdc++.h>

using namespace std;

vector <int> g[(1 << 16)];
int deg[(1 << 16)];
int x_or[(1 << 16)];
set <pair <int, int> > e;
stack <int> q;

int main() {
    int n, d, s;
    cin >> n;
    for (int v = 0; v < n; v++) {
        cin >> d >> s;
        deg[v] = d;
        x_or[v] = s;
        if (deg[v] == 1) {
            q.push(v);
        }
    }
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        if (deg[v] == 0) continue;
        g[v].push_back(x_or[v]);
        x_or[x_or[v]] ^= v; 
        deg[x_or[v]]--;
        if (deg[x_or[v]] == 1)
            q.push(x_or[v]);
    }
    vector <pair <int, int> > edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int) g[i].size(); j++) {
            edges.push_back({i, g[i][j]});
        }
    }
    cout << edges.size() << endl;
    for (int i = 0; i < (int) edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << endl;
}