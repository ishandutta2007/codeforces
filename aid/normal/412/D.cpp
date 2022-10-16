#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 30 * 1000 + 5;
char used[MAXN];
vector<int> g[MAXN], ans;

void dfs(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i]])
            dfs(g[v][i]);
    ans.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        if(!used[i])
            dfs(i);
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}