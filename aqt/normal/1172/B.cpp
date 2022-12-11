#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
long long dp[200005];
long long MOD = 998244353;

void dfs(int n, int p){
    int dgr = !!p;
    dp[n] = 1;
    for(int e : graph[n]){
        if(e != p){
            dgr++;
            dfs(e, n);
            dp[n] *= dp[e];
            dp[n] %= MOD;
        }
    }
    for(int i = 1; i<=dgr; i++){
        dp[n] *= i;
        dp[n] %= MOD;
    }
}

int main(){
    cin >> N;
    for(int i= 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1]*N%MOD << endl;
}