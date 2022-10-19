#include <bits/stdc++.h>
using namespace std;

int group;
int leaf;

bool dfs(int pos, int bpos, vector<vector<int>> &G){
    bool flg = false;
    for(auto npos: G[pos]){
        if(npos == bpos) continue;
        flg |= dfs(npos, pos, G);
    }
    if(!flg){
        leaf++;
        return true;
    }
    else{
        group++;
        return false;
    }
    
}

void solve(){
    leaf = 0;
    group = 0;
    int n;
    scanf("%d", &n);
    vector<vector<int>> G(n, vector<int>());
    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool tmp = dfs(0, -1, G);
    int ans = leaf - group;
    if(!tmp) ans++;
    printf("%d\n", ans);
    
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}