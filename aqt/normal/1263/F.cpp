#include <bits/stdc++.h>

using namespace std;

int N, A, B;
vector<int> graph[2][2005];
int who[2][1005];
int tbl[2][11][2005];
int dep[2][2005];
int dp[1005][1005];

void dfs(int n, int p, int t){
    for(int e : graph[t][n]){
        dep[t][e] = dep[t][n] + 1;
        dfs(e, n, t);
    }
}

int lca(int a, int b, int t){
    int s = a;
    //cout << "here: " << a << " " << b << endl;
    if(dep[t][a] < dep[t][b]){
        swap(a, b);
    }
    for(int d = 10; d>=0; d--){
        if(dep[t][tbl[t][d][a]] >= dep[t][b]){
            a = tbl[t][d][a];
        }
    }
    if(a == b){
        //cout << " " << s << " " << a << " " << dep[t][s] - dep[t][a] << endl;
        return dep[t][s] - dep[t][a];
    }
    for(int d = 10; d>=0; d--){
        if(tbl[t][d][a] != tbl[t][d][b]){
            a = tbl[t][d][a];
            b = tbl[t][d][b];
        }
    }
    //cout << " " << s << " " << tbl[t][0][a] << " " << dep[t][s] - dep[t][tbl[t][0][a]] + 1 << endl;
    return dep[t][s] - dep[t][tbl[t][0][a]];
}

int main(){
    cin >> N;
    cin >> A;
    for(int i = 2; i<=A; i++){
        int p;
        cin >> p;
        graph[0][p].push_back(i);
        tbl[0][0][i] = p;
    }
    for(int i = 1; i<=N; i++){
        cin >> who[0][i];
    }
    cin >> B;
    for(int i= 2; i<=B; i++){
        int p;
        cin >> p;
        graph[1][p].push_back(i);
        tbl[1][0][i] = p;
    }
    for(int i = 1; i<=N; i++){
        cin >> who[1][i];
    }
    who[0][0] = who[1][0] = 1;
    dep[0][1] = dep[1][1] = 1;
    dfs(1, 0, 0);
    dfs(1, 0, 1);
    for(int d = 1; d<11; d++){
        for(int n = 1; n<=A; n++){
            tbl[0][d][n] = tbl[0][d-1][tbl[0][d-1][n]];
        }
        for(int n = 1; n<=B; n++){
            tbl[1][d][n] = tbl[1][d-1][tbl[1][d-1][n]];
        }
    }
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            dp[i][j] = INT_MAX/2;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int nxt = max(i, j);
            dp[nxt+1][j] = min(dp[nxt+1][j], dp[i][j] + lca(who[0][nxt+1], who[0][i], 0));
            dp[i][nxt+1] = min(dp[i][nxt+1], dp[i][j] + lca(who[1][nxt+1], who[1][j], 1));
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int ans = INT_MAX/2;
    for(int i = 0; i<=N; i++){
        ans = min(ans, min(dp[i][N], dp[N][i]));
        //cout << i << " " << N << " " << dp[i][N] << endl;
        //cout << N << " " << i << " " << dp[N][i] << endl;
    }
   // cout << ans << endl;
    cout << A-1 + B-1 - ans;
}