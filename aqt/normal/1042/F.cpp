#include <bits/stdc++.h>

using namespace std;

int N, K;
int dep[1000005];
int par[1000005];
vector<int> graph[1000005];
int rt, S;
int dp[1000005];

void dfs(int n){
    if(graph[n].size() == 1){
        dp[n] = dep[n];
        return;
    }
    vector<int> v;
    for(int e : graph[n]){
        if(e != par[n]){
            dep[e] = dep[n]+1;
            par[e] = n;
            dfs(e);
            if(dp[e]){
                v.push_back(dp[e]);
            }
        }
    }
    sort(v.begin(), v.end());
    dp[n] = v[0];
    for(int i = 1; i<v.size(); i++){
        if(v[i]+v[i-1]-2*dep[n] <= K){
            dp[n] = v[i];
            S--;
        }
        else{
            break;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i= 1; i<=N; i++){
        if(graph[i].size() == 1){
            S++;
        }
        else{
            rt = i;
        }
    }
    dfs(rt);
    cout << S << endl;
}