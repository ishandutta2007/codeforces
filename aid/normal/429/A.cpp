#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int a[MAXN];
vector<int> g[MAXN], ans;

void dfs(int v, int p, int mask) {
    int mask0 = 0;
    if(mask & 1)
        mask0 += 2;
    if(mask & 2)
        mask0 += 1;
    if((mask & 1) ^ a[v]) {
        mask0 ^= 2;
        ans.push_back(v);
    }
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p)
            dfs(g[v][i], v, mask0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int goal;
        cin >> goal;
        a[i] ^= goal;
    }
    dfs(0, -1, 0);
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << '\n';
    return 0;
}