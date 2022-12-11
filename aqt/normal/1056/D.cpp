#include <bits/stdc++.h>

using namespace std;

int N, par[100005], arr[100005];
vector<int> graph[100005];

int dfs(int n){
    if(graph[n].empty()){
        arr[n] = 1;
        return 1;
    }
    for(auto e : graph[n]){
        arr[n] += dfs(e);
    }
    return arr[n];
}

int main(){
    scanf("%d", &N);
    for(int i = 2; i<=N; i++){
        scanf("%d", &par[i]);
        graph[par[i]].push_back(i);
    }
    dfs(1);
    sort(arr+1, arr+N+1);
    for(int i = 1; i<=N; i++){
        printf("%d ", arr[i]);
    }
}