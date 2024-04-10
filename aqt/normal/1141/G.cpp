#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
int dgr[200005];
int u[200005], v[200005];
int ans[200005];

void dfs(int n, int p){
    int clr = 1;
    if(clr == ans[p]){
        clr++;
    }
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        ans[e] = clr++;
        if(graph[n].size() > K){
            ans[e] = 1;
        }
        if(clr == ans[p]){
            clr++;
        }
        if(u[e] == n){
            dfs(v[e], e);
        }
        else{
            dfs(u[e], e);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i=1 ; i<N; i++){
        cin >> u[i] >> v[i];
        graph[u[i]].push_back(i);
        graph[v[i]].push_back(i);
        dgr[u[i]]++;
        dgr[v[i]]++;
    }
    sort(dgr+1, dgr+1+N, greater<int>());
    K = dgr[K+1];
    dfs(1, 0);
    cout << K << "\n";
    for(int i = 1; i<N; i++){
        cout << ans[i] << " ";
    }
}