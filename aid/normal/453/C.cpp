#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int x[MAXN];
char used[MAXN];
vector<int> g[MAXN], ans;

void dfs(int v, int p) {
    used[v] = true;
    ans.push_back(v);
    x[v] ^= 1;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i]]) {
            dfs(g[v][i], v);
            ans.push_back(v);
            x[v] ^= 1;
        }
    if(x[v]) {
        if(p != -1) {
            ans.push_back(p);
            x[p] ^= 1;
            ans.push_back(v);
            x[v] ^= 1;
        }
        else if(!g[v].empty()) {
            ans.push_back(g[v][0]);
            ans.push_back(v);
            x[v] ^= 1;
            ans.push_back(g[v][0]);
        }
    }
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
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        if(x[i]) {
            dfs(i, -1);
            break;
        }
    for(int i = 0; i < n; i++)
        if(x[i]) {
            cout << -1 << '\n';
            return 0;
        }
    cout << ans.size() << '\n';
    if(!ans.empty()) {
        for(size_t i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}