#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> graph[100005];
int par[20][100005];
int dep[100005];
int sz[100005];

int lca(int x, int y){
    if(dep[x] < dep[y]){
        swap(x, y);
    }
    for(int i = 18; i>=0; i--){
        if(dep[par[i][x]] >= dep[y]){
            x = par[i][x];
        }
    }
    if(x == y){
        return y;
    }
    for(int i = 18; i>=0; i--){
        if(par[i][x] != par[i][y]){
            x = par[i][x];
            y = par[i][y];
        }
    }
    return par[0][x];
}

int climb(int x, int d){
    for(int i = 18; i>=0; i--){
        if(dep[par[i][x]] >= d){
            x = par[i][x];
        }
    }
    return x;
}

void dfs(int n){
    sz[n] = 1;
    for(int e : graph[n]){
        if(par[0][n] != e){
            par[0][e] = n;
            dep[e] = dep[n] + 1;
            dfs(e);
            sz[n] += sz[e];
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
    dep[1] = 1;
    dfs(1);
    for(int d = 1; d<=18; d++){
        for(int i =1; i<=N; i++){
            par[d][i] = par[d-1][par[d-1][i]];
        }
    }
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << N << "\n";
            continue;
        }
        int top = lca(a, b);
        int dis = (dep[a] + dep[b] - 2*dep[top]);
        if(dis%2){
            cout << 0 << "\n";
            continue;
        }
        if(dep[a] == dep[b]){
            int pa = climb(a, dep[a] - dis/2+1), pb = climb(b, dep[b] - dis/2+1);
            cout << N - sz[pa] - sz[pb] << "\n";
        }
        else{
            if(dep[a] < dep[b]){
                swap(a, b);
            }
            int pa = climb(a, dep[a] - dis/2+1);
            cout << sz[par[0][pa]] - sz[pa] << "\n";
        }
    }
}