#include <bits/stdc++.h>
using namespace std;
long long la[100100];
long long ra[100100];
long long ans_l[100100];
long long ans_r[100100];

void dfs(int pos, int bpos, vector<vector<int>> &edges){
    ans_l[pos] = 0;
    ans_r[pos] = 0;
    for(auto npos: edges[pos]){
        if(npos == bpos) continue;
        dfs(npos, pos, edges);
        ans_l[pos] += max(abs(la[pos] - la[npos]) + ans_l[npos], abs(la[pos] - ra[npos]) + ans_r[npos]);
        ans_r[pos] += max(abs(ra[pos] - la[npos]) + ans_l[npos], abs(ra[pos] - ra[npos]) + ans_r[npos]);
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%llu %llu", &la[i], &ra[i]);
    }
    vector<vector<int>> edges(n, vector<int>());
    int u, v;
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0, -1, edges);
    printf("%llu\n", max(ans_l[0], ans_r[0]));
    return;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}