#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5;
char c[MAXN];
int cnt[MAXN];
long long s[MAXN];
vector<int> g[MAXN];

void dfs0(int v, int p, int dep) {
    cnt[v] = 0;
    s[v] = 0;
    if(c[v]) {
        cnt[v]++;
        s[v] += dep;
    }
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(u == p)
            continue;
        dfs0(u, v, dep + 1);
        cnt[v] += cnt[u];
        s[v] += s[u];
    }
}

long long dfs1(int v, int p, int k) {
    int maxCnt = c[v];
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(u != p)
            maxCnt = max(maxCnt, cnt[u]);
    }
    if(2 * (maxCnt - k) <= cnt[v] - k)
        return 0;
    int nk = k + cnt[v] - maxCnt;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(u != p && cnt[u] == maxCnt)
            return maxCnt - nk + dfs1(u, v, nk);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2 * k; i++) {
        int v;
        cin >> v;
        v--;
        c[v] = true;
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs0(0, -1, 0);
    cout << s[0] - dfs1(0, -1, 0) << '\n';
    return 0;
}