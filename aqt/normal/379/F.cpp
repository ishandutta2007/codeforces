#include <bits/stdc++.h>

using namespace std;

int Q, N, D1, D2;
int dep[1000050];
int lca[1000050][25];

int par(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    for(int i = 20; i>=0; i--){
        if(dep[lca[u][i]] >= dep[v]){
            u = lca[u][i];
        }
    }
    if(u == v){
        return u;
    }
    for(int i = 20; i>=0; i--){
        if(lca[u][i] != lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}

void upd(int n){
    for(int i = 1; i<=20; i++){
        lca[n][i] = lca[lca[n][i-1]][i-1];
    }
}

int dia(int n){
    int p1 = par(n, D1), p2 = par(n, D2), p3 = par(D1, D2);
    if(dep[D1] + dep[n] - 2*dep[p1] > dep[D2] + dep[n] - 2*dep[p2]){
        if(dep[D1] + dep[n] - 2*dep[p1] > dep[D1] + dep[D2] - 2*dep[p3]){
            D2 = n;
        }
    }
    else{
        if(dep[D2] + dep[n] - 2*dep[p2] > dep[D1] + dep[D2] - 2*dep[p3]){
            D1 = n;
        }
    }
    return dep[D1] + dep[D2] - 2*dep[par(D1, D2)];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    dep[1] = 1;
    dep[2] = dep[3] = dep[4] = 2;
    lca[2][0] = lca[3][0] = lca[4][0] = 1;
    D1 = 2;
    D2 = 4;
    N = 4;
    while(Q--){
        cin >> lca[N+1][0];
        lca[N+2][0] = lca[N+1][0];
        dep[N+1] = dep[N+2] = dep[lca[N+1][0]]+1;
        N++;
        upd(N);
        N++;
        upd(N);
        cout << dia(N) << "\n";
    }
}