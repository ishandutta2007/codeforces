#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 101, sigma = 26;
vector<pair<int, char>> g[maxn];
int used[maxn][maxn][sigma][2];
int win[maxn][maxn][sigma][2];

void dfs(int v1, int v2, char c = 0, bool move = 0) {
    if(used[v1][v2][c][move]) {
        return;
    }
    used[v1][v2][c][move] = true;
    if(move == 0) {
        for(auto it: g[v1]) {
            int u1 = it.first;
            char nc = it.second - 'a';
            if(nc >= c) {
                dfs(u1, v2, nc, move ^ 1);
                win[v1][v2][c][move] |= !win[u1][v2][nc][move ^ 1];
            }
        }
    } else {
        for(auto it: g[v2]) {
            int u2 = it.first;
            char nc = it.second - 'a';
            if(nc >= c) {
                dfs(v1, u2, nc, move ^ 1);
                win[v1][v2][c][move] |= !win[v1][u2][nc][move ^ 1];
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (win[i][j][0][0] ? 'A' : 'B');
            if(j + 1 == n) {
                cout << endl;
            }
        }
    }
    return 0;
}
    
/*
 * (S)
 * ST
 * 
 */