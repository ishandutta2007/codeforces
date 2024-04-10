#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
long long arr[100005];
long long dp[100005][2][2]; //#paths-1, atnode?.

void dfs(int n, int p){
    dp[n][0][0] = dp[n][0][1] = arr[n];
    long long maxi00 = 0;
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
            dp[n][1][0] = max(dp[n][1][0], dp[e][1][0]);
            dp[n][1][0] = max(dp[n][1][0], dp[e][0][1] + dp[n][1][1]);
            dp[n][1][0] = max(dp[n][1][0], dp[e][1][1] + dp[n][0][1]);
            dp[n][1][0] = max(dp[n][1][0], dp[e][0][0] + dp[n][0][0]);
            dp[n][1][1] = max(dp[n][1][1], dp[e][1][1] + arr[n]);
            dp[n][1][1] = max(dp[n][1][1], dp[e][0][1] + maxi00 + arr[n]);
            dp[n][1][1] = max(dp[n][1][1], dp[e][0][0] + dp[n][0][1]);
            dp[n][0][0] = max(dp[n][0][0], dp[e][0][0]);
            dp[n][0][0] = max(dp[n][0][0], dp[e][0][1] + dp[n][0][1]);
            dp[n][0][1] = max(dp[n][0][1], dp[e][0][1] + arr[n]);
            maxi00 = max(maxi00, dp[e][0][0]);
        }
    }
//    dp[n][1][0] = max(dp[n][1][1], dp[n][1][0]);
//    dp[n][0][0] = max(dp[n][0][0], dp[n][0][1]);
}

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1][1][0] << endl;
}