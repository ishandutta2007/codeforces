#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

vector <int> c;
vector <vector<int>> g;
vector <bool> usd;
vector <bool> dp;

void dfs(int v) {
    usd[v] = true;
    dp[v] = true;
    if (c[v] == false) {
        dp[v] = false;
    }
    for (auto &to : g[v]) {
        if (!usd[to]) {
            dfs(to);
            if (c[to] == 0) {
                dp[v] = false;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    c.resize(n);
    g.resize(n);
    usd.resize(n);
    dp.resize(n);
    vector <int> par(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int p, cn;
        cin >> p >> cn;
        if (p == -1) {
            root = i;
        }
        else {
            g[i].push_back(p - 1);
            g[p - 1].push_back(i);
        }
        par[i] = p - 1;
        c[i] = cn;
    }
    dfs(root);
    set <int> s;
    for (int i = 0; i < n; i++) {
        if (dp[i] == true && i != root) {
            if (g[i].size() == 1 && c[i] == 0) {
                continue;
            }
            s.insert(i);
        }
    }
    vector <int> ans;
    vector <bool> in(n);
    while (s.size()) {
        int cur = *s.begin();
        in[cur] = true;
        s.erase(s.begin());
        ans.push_back(cur + 1);
        if (par[cur] != root && in[par[cur]] == false && dp[par[cur]] == true) {
            s.insert(par[cur]);
        }
    }
    if (ans.size() == 0) {
        cout << -1;
        return 0;
    }
    for (auto &u : ans) {
        cout << u << " ";
    }
    return 0;
}