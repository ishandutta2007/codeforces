#include <bits/stdc++.h>

using namespace std;

int N;
long long dp1[200005], dp2[200005], sz[200005];
vector<int> graph[200005];

void dfs(int n, int p){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
            sz[n] += sz[e];
            dp2[n] += dp2[e];
        }
    }
    dp2[n] += sz[n];
    dp1[n] = N;
    for(int e : graph[n]){
        if(e != p){
            dp1[n] = max(dp1[n], dp2[n] - dp2[e] + dp1[e] + N - sz[e] - sz[n]);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]) << endl;
}