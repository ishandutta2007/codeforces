#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

#define int li

vector<vector<int>> e;

const int max_n = 100500;
int d[max_n][11][3];
int n, m;
int k, num_special;

// 0 = < k
// 1 = = k
// 2 = > k

const li MOD = 1e9 + 7;

void mult(int& x, li by) {
    x = x * (li)by % MOD;
}

void add(int& x, int by) {
    x += by;
    if (x >= MOD)
        x -= MOD;
}

void dfs(int v, int p = -1) {
    memset(d[v], 0, sizeof(d[v]));
    d[v][0][0] = k - 1;
    d[v][1][1] = 1;
    d[v][0][2] = m - k;
    
    for (int u: e[v]) {
        if (u == p) continue;
        
        dfs(u, v);
        
        int merge[11][3];
        memset(merge, 0, sizeof(merge));
        
        for (int cnt = 0; cnt <= num_special; cnt++)
            for (int cnt_u = 0; cnt_u + cnt <= num_special; cnt_u++) {
                add(merge[cnt + cnt_u][0], (d[u][cnt_u][0] + (li)d[u][cnt_u][1] + d[u][cnt_u][2]) * d[v][cnt][0] % MOD);
                add(merge[cnt + cnt_u][2], (d[u][cnt_u][0] + d[u][cnt_u][2]) * (li)d[v][cnt][2] % MOD);
                add(merge[cnt + cnt_u][1], (d[u][cnt_u][0]) * (li)d[v][cnt][1] % MOD);
                //mult(merge[0], d[u][cnt][0] + (li)d[u][cnt][1] + d[u][cnt][2]);
                //mult(d[v][cnt][2], d[u][cnt][0] + d[u][cnt][2]);
                
                //if (cnt)
                //    mult(d[v][cnt][1], d[u][cnt - 1][0]);
            }
            
        memcpy(d[v], merge, sizeof(merge));
    }
}

void solve(bool read) {
    cin >> n >> m;
    
    e.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    cin >> k >> num_special;
    dfs(0);
    
    li answer = 0;
    for (int i = 0; i <= num_special; i++) {
        answer = (answer + d[0][i][0] + d[0][i][1] + d[0][i][2]) % MOD;
        //printf("%d: %d %d %d\n", i, d[0][i][0], d[0][i][1], d[0][i][2]);
    }
    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        guessed = false;
        solve(false);
        assert(guessed);
    }
#endif
    
    return 0;
}