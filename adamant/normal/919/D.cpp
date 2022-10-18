#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 42, sigma = 26;
string s;
int used[maxn];
vector<int> g[maxn];
int cnt[maxn][sigma];
int ans = 0;
void dfs(int v) {
    if(used[v]) {
        return;
    }
    used[v] = 1;
    cnt[v][s[v] - 'a'] = 1;
    for(auto u: g[v]) {
        if(used[u] == 1) {
            cout << -1 << endl;
            exit(0);
        } else if(!used[u]) {
            dfs(u);
        }
        for(int c = 0; c < sigma; c++) {
            cnt[v][c] = max(cnt[v][c], (s[v] - 'a' == c) + cnt[u][c]);
        }
    }
    for(int c = 0; c < sigma; c++) {
        ans = max(ans, cnt[v][c]);
    }
    used[v] = 2;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    for(int i = 0; i < n; i++) {
        dfs(i);
    }
    cout << ans << endl;
    return 0;
}