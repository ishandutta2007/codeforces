#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m;
pair<int, int> e[maxn];
vector<int> g[maxn];
int p[maxn];
int T;
int u[maxn];
bool dfs(int v) {
    if(u[v] == T) return false;
    u[v] = T;
    for(int to: g[v]) {
        if(p[to] == -1 || dfs(p[to])) {
            p[to] = v;
            p[v] = to;
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[j * 2 - 1].clear();
            g[j * 2].clear();
            p[j * 2 - 1] = -1;
            p[j * 2] = -1;
        }
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(e[j].first == i || e[j].second == i) {
                cnt++;
                continue;
            }
            g[e[j].first * 2 - 1].emplace_back(e[j].second * 2);

            g[e[j].second * 2].emplace_back(e[j].first * 2 - 1);
        }
        T = 1;
        for(int i = 1; i <= 2 * n; i++) {
            u[i] = 0;
        }
        while(true) {
            T++;
            int ok = false;
            for(int i = 1; i <= 2 * n; i++) {
                if(p[i] == -1 && dfs(i)) {
                    ok = true;
                    cnt++;
                }
            }
            if(ok) continue;
            break;
        }
        ans = min(ans, m + (n-1) * 2 + 1 + (n-1) - 2 * cnt);
    }
    cout << ans << "\n";
    return 0;
}