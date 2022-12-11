#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[1000005];
int dp2[1000005], dp1[1000005];
int hg[1000005], dep[1000005];

void dfs1(int n){
    if(graph[n].empty()){
        dp2[n] = 1;
        hg[n] = dep[n];
        return;
    }
    hg[n] = INT_MAX;
    for(int e : graph[n]){
        dep[e] = dep[n]+1;
        dfs1(e);
        if(hg[e]-K <= dep[n]){
            dp2[n] += dp2[e];
        }
        hg[n] = min(hg[e], hg[n]);
    }
}

void dfs2(int n){
    dp1[n] += dp2[n];
    for(int e : graph[n]){
        dp1[e] = dp1[n];
        if(hg[e]-K <= dep[n]){
            dp1[e] -= dp2[e];
        }
        dfs2(e);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    int ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, dp1[i]);
    }
    cout << ans << endl;
}