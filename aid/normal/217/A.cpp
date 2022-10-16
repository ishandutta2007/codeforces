#include <iostream>
#include <vector>

using namespace std;

const int MAXX = 1005, MAXN = 105;
char used[2 * MAXX];
vector<int> g[2 * MAXX];

void dfs(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i]])
            dfs(g[v][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(MAXX + y);
        g[MAXX + y].push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < 2 * MAXX; i++)
        if(!used[i] && !g[i].empty()) {
            dfs(i);
            ans++;
        }
    ans--;
    cout << ans << '\n';
    return 0;
}