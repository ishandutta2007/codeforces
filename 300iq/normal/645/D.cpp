#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

vector <int> g[MAXN];
vector <int> topsort;
set <pair <int, int> > edges;
bool used[MAXN];
int u, v, a[MAXN], b[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to);
        }
    }
    topsort.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        a[i] = u, b[i] = v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    for (int i = 1; i < (int) topsort.size(); i++) {
        u = topsort[i - 1];
        v = topsort[i];
        edges.insert(make_pair(u, v));
    }
    for (int i = 0; i < m; i++) {
        if (edges.size() == 0) {
            cout << i << endl;
            return 0;
        } else {
            u = a[i], v = b[i];
            edges.erase(make_pair(u, v));
        }
    }
    if (edges.size() == 0) {
        cout << m << endl;
    } else {
        cout << -1 << endl;
    }
}