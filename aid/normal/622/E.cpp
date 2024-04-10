#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int d[MAXN];
vector<int> g[MAXN];

void dfs(int v, int p, vector<int> &leafs) {
    d[v] = d[p] + 1;
    bool leaf = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            leaf = false;
            dfs(g[v][i], v, leafs);
        }
    if(leaf)
        leafs.push_back(v);
}

bool cmp(int a, int b) {
    return d[a] < d[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
    d[0] = 0;
    int ans = 0;
    for(size_t i = 0; i < g[0].size(); i++) {
        vector<int> v;
        dfs(g[0][i], 0, v);
        sort(v.begin(), v.end(), cmp);
        int cur = 0;
        for(size_t j = 0; j < v.size(); j++)
            cur = (d[v[j]] <= cur? cur + 1 : d[v[j]]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}