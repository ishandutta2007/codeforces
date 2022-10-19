#include <bits/stdc++.h>
using namespace std;
int dp[200200], ans[200200];

void dfs(int pos, int bpos, vector<int> &A, vector<vector<int>> &edges){
    if(A[pos] == 1) dp[pos] = 1;
    else dp[pos] = -1;
    for(auto npos: edges[pos]){
        if(npos == bpos) continue;
        dfs(npos, pos, A, edges);
        dp[pos] += max(0, dp[npos]);
    }
}

void rev_dfs(int pos, int bpos, vector<int> &A, vector<vector<int>> &edges){
    if(A[pos] == 1) ans[pos] = 1;
    else ans[pos] = -1;
    for(auto npos: edges[pos]){
        ans[pos] += max(0, dp[npos]);
    }
    dp[pos] += max(dp[bpos], 0);
    for(auto npos: edges[pos]){
        if(npos == bpos) continue;
        dp[pos] -= max(dp[npos], 0);
        rev_dfs(npos, pos, A, edges);
        dp[pos] += max(dp[npos], 0);
    }
    dp[pos] -= max(dp[bpos], 0);
}

int main(void){
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    vector<vector<int>> edges(n, vector<int>());
    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0, -1, A, edges);
    rev_dfs(0, -1, A, edges);
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i == n - 1) cout << "\n";
        else cout << " ";
    }
    
    
    
}