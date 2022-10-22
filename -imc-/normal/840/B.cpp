#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

vector<int> d;
vector<vector<pair<int, int>>> e;
vector<int> answer;
vector<char> used;

int dfs(int v) {
    int deg = 0;
    used[v] = true;
    for (auto edge: e[v]) {
        int u = edge.first;
        if (used[u]) continue;
        
        int x = dfs(u);
        if (x) answer.push_back(edge.second);
        deg += x;
    }
    
    if (d[v] == -1) return 0;
    if (d[v] != deg % 2) return 1;
    return 0;
}

void print_ans() {
    cout << answer.size() << "\n";
    for (int x: answer)
        cout << x << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    e.resize(n);
    d.resize(n);
    used.resize(n);
    
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        deg[u]++; deg[v]++;
        e[u].emplace_back(v, i + 1);
        e[v].emplace_back(u, i + 1);
    }
    
    for (int i = 0; i < n; i++)
        if (d[i] == -1) {
            dfs(i);
            print_ans();
            return;
        }
        
    if (dfs(0) == 0) {
        print_ans();
        return;
    }
    
    cout << "-1\n";
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    
    return 0;
}