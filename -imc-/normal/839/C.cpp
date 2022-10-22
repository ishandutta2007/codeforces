#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

vector<vector<int>> e;

long double answer;

void dfs(int v, long double prob, int p = -1) {
    answer += prob;
    
    int x = e[v].size() - (p != -1);
    
    for (int u: e[v])
        if (u != p)
            dfs(u, prob / x, v);
}

void solve() {
    int n;
    cin >> n;
    
    e.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    answer = -1;
    dfs(0, 1);
    cout << fixed << setprecision(12) << answer << "\n";
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    
    return 0;
}