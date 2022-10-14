#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector <bool> usd;

void dfs(int v) {
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (!usd[to] && to != 0) {
            dfs(to);
        }
    }
}

void dfs1(int v, vector <pair<int, int>> &ans) {
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (!usd[to]) {
            ans.push_back({v, to});
            dfs1(to, ans);
        }
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (g[0].size() < d) {
        cout << "NO";
        return 0;
    }
    usd.resize(n);
    vector <int> need;
    usd[0] = 1;
    for (auto &to : g[0]) {
        if (usd[to]) {
            continue;
        }
        dfs(to);
        need.push_back(to);
    }
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            cout << "NO";
            return 0;
        }
    }
    if (need.size() > d) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    vector <pair<int, int>> ans;
    vector <bool> in(n);
    for (auto &c : need) {
        in[c] = 1;
    }
    d -= need.size();
    for (auto &c : g[0]) {
        if (d == 0) {
            break;
        }
        if (in[c]) {
            continue;
        }
        d--;
        need.push_back(c);
    }
    for (auto &c : need) {
        ans.push_back({0, c});
    }
    usd.assign(n, 0);
    for (auto &c : need) {
        usd[c] = 1;
    }
    usd[0] = 1;
    for (auto &c : need) {
        dfs1(c, ans);
    }
    for (auto &c : ans) {
        cout << c.first + 1 << " " << c.second + 1 << "\n";
    }
    return 0;
}