#include <bits/stdc++.h>

using namespace std;

int Q, N, K;
vector<pair<int, int>> graph[500005];
long long dp[2][500005];
//how many edges left

void dfs(int n, int p, int val = 0){
    //cout << n << endl;
    vector<long long> v;
    long long tot = 0;
    for(auto e : graph[n]){
        if(e.first != p){
            dfs(e.first, n, e.second);
            tot += dp[0][e.first];
            v.push_back(max(0LL, dp[1][e.first]-dp[0][e.first]));
        }
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long k = 0;
    for(int i = 0; i<min(K-1, (int) (v.size())); i++){
        k += v[i];
    }
    dp[1][n] = k+tot+val;
    dp[0][n] = tot+k;
    if((int) (v.size()) >= K){
        k += v[K-1];
    }
    dp[0][n] = max(dp[0][n], k+tot);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        cin >> N >> K;
        for(int i = 1; i<=N; i++){
            graph[i].clear();
            dp[0][i] = dp[1][i] = 0;
        }
        for(int i =1; i<N; i++){
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
        dfs(1, 0);
        cout << max(dp[0][1], dp[1][1]) << endl;
    }
}