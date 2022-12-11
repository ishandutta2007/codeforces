#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[300005];
int dp[300005], sz[300005];
bool typ[300005];

void dfs(int n){
    if(graph[n].empty()){
        dp[n] = 1;
        sz[n] = 1;
        return;
    }
    for(int e : graph[n]){
        dfs(e);
        sz[n] += sz[e];
    }
    if(typ[n]){
        dp[n] = INT_MIN;
        for(int e : graph[n]){
            dp[n] = max(dp[n], dp[e]-sz[e]);
        }
        dp[n] += sz[n];
    }
    else{
        for(int e : graph[n]){
            dp[n] += dp[e]-1;
        }
        dp[n]++;
    }
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> typ[i];
    }
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    dfs(1);
    cout << dp[1] << endl;
}