#include <bits/stdc++.h>

using namespace std;

vector < int > g[200005];
int ans = 0, kol = 0;
bool f = true;

int isi[200005];

void dfs(int v){
    kol++;
    isi[v] = 1;
    if (g[v].size() != 2)
        f = false;
    for (auto u : g[v]){
        if (isi[u] == 0)
            dfs(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <=m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        if (isi[i] == 0){
            f = true;
            kol = 0;
            dfs(i);
            if (f && kol > 2)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}