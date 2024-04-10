#include <bits/stdc++.h>
using namespace std;

int dist[200200];
int dp[200200];
bool used[200200];

void dfs(int pos, vector<vector<int>> &G){
    used[pos] = true;
    dp[pos] = dist[pos];
    for(auto npos: G[pos]){
        if(!used[npos] && dist[pos] < dist[npos]) dfs(npos, G);
        if(dist[pos] < dist[npos]) dp[pos] = min(dp[pos], dp[npos]);
        else dp[pos] = min(dp[pos], dist[npos]);
    }
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> G(n);
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        G[u - 1].push_back(v - 1);
    }
    for(int i = 0; i < n; i++){
        dist[i] = -1;
        used[i] = false;
    }
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(auto npos: G[pos]){
            if(dist[npos] == -1){
                dist[npos] = dist[pos] + 1;
                que.push(npos);
            }
        }
    }
    dfs(0, G);
    for(int i = 0; i < n; i++){
        printf("%d", dp[i]);
        if(i == n - 1) printf("\n");
        else printf(" ");
    }
}


int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}