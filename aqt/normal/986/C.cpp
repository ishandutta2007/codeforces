#include <bits/stdc++.h>

using namespace std;

int N, M;
bool vis[2][5000000];

int comp(int n){
    return (1<<N)-1-n;
}

void dfs(int n, int t){
    vis[t][n] = 1;
    if(t){
        for(int k = 0; k<N; k++){
            if(!vis[1][n|(1<<k)]){
                dfs(n|(1<<k), 1);
            }
        }
        if(!vis[0][comp(n)]){
            dfs(comp(n), 0);
        }
    }
    else{
        if(!vis[1][n]){
            dfs(n, 1);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<1<<N; i++){
        vis[0][i] = 1;
    }
    for(int i= 0; i<M; i++){
        int n;
        cin >> n;
        vis[0][n] = 0;
    }
    int cnt = 0;
    for(int i = 0; i<1<<N; i++){
        if(!vis[0][i]){
            cnt++;
            dfs(i, 0);
        }
    }
    cout << cnt<< endl;
}