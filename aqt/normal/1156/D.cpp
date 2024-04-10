#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005][2];
int par[200005][2];
int sz[200005][3];

int getrt(int n, int c){
    return par[n][c] = (par[n][c] == n ? n : getrt(par[n][c], c));
}

void dfs0(int n, int p){
    for(int e : graph[n][0]){
        if(e != p){
            dfs0(e, n);
            sz[n][0] += sz[e][0];
            sz[n][2] += sz[e][2];
            par[e][0] = n;
        }
    }
    sz[getrt(n, 0)][2] += sz[getrt(n, 1)][1]-1;
}

void dfs1(int n, int p){
    for(int e : graph[n][1]){
        if(e != p){
            dfs1(e, n);
            sz[n][1] += sz[e][1];
            par[e][1] = n;
        }
    }
}

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        par[i][0] = par[i][1] = i;
        sz[i][0] = sz[i][1] = 1;
    }
    for(int i =1; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][c].push_back(b);
        graph[b][c].push_back(a);
    }
    for(int i= 1; i<=N; i++){
        if(par[i][1] == i){
            dfs1(i, 0);
        }
    }
    for(int i =1 ; i<=N; i++){
        if(par[i][0] == i){
            dfs0(i, 0);
        }
    }
    long long ans = -N;
    for(int i= 1; i<=N; i++){
        ans += (sz[getrt(i, 0)][0] + sz[getrt(i, 0)][2]);
    }
    cout << ans << endl;
}