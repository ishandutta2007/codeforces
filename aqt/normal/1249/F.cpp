#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[205][505];
vector<int> graph[205];
int dep[205];
int val[205];
int ans = 0;

void dfs(int n, int p){
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        dep[e] = dep[n] + 1;
        dfs(e, n);
    }
    //dp[n][dep[n]] = val[n];
    for(int k = dep[n]; k<=N; k++){
        if(k == dep[n]){
            for(int e : graph[n]){
                if(e != p){
                    dp[n][k] += dp[e][K+dep[n]];
                }
            }
            dp[n][k] += val[n];
        }
        else if(k-dep[n]+k-dep[n] >= K){
            for(int e : graph[n]){
                if(e == p){
                    continue;
                }
                dp[n][k] += dp[e][k];
            }
        }
        else{
            //cout << n << " " << k << endl;
            for(int e1 : graph[n]){
                if(e1 == p){
                    continue;
                }
                int tot = dp[e1][k];
                for(int e2 : graph[n]){
                    if(e2 == e1 || e2 == p){
                        continue;
                    }
                    tot += dp[e2][K+2*dep[n]-k];
                }
                dp[n][k] = max(dp[n][k], tot);
                //cout << tot << " " << K+2*dep[n]-k<< endl;
            }
        }
    }
    for(int k = N; k>0; k--){
        dp[n][k] = max(dp[n][k+1], dp[n][k]);
        ans = max(dp[n][k], ans);
        //cout << n << " " << k << " " << dp[n][k] << endl;
    }
}

int main(){
    cin >> N >> K;
    K++;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dep[1] = 1;
    dfs(1, 0);
    cout << ans << endl;
}