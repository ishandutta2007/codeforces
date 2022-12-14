# include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 77 , L = 19;
int par[N][L] , d[N] , n , m , s;
bool mark[N];
vector < int > adj[N];
int get_par(int v , int k) {
    for(int i = 0;i < L;++ i)
        if(k & (1 << i))
            v = par[v][i];
    return v;
}
int get_lca(int v , int u) {
    if(d[v] > d[u]) swap(v , u);
    u = get_par(u , d[u] - d[v]);
    if(v == u) return v;
    for(int i = L - 1;i >= 0;-- i)
        if(par[v][i] != par[u][i])
            v = par[v][i] , u = par[u][i];
    return par[v][0];
}
void dfs(int v , int pv = -1) {
    for(int i = 1;i < L;++ i)
        par[v][i] = par[par[v][i - 1]][i - 1];
    mark[v] = 1;
    for(int u : adj[v]) {
        if(mark[u]) continue ;
        d[u] = d[v] + 1;
        par[u][0] = v;
        dfs(u , v);
    }
}
void printV(int x , int append = -1) {
    vector < int > vp;
    while(x)
        vp.push_back(x) , x = par[x][0];
    reverse(vp.begin() , vp.end());
    if(append != -1) vp.push_back(append);
    printf("%d\n" , vp.size());
    for(int x : vp) printf("%d " , x);
    printf("\n");
}
int main() {
    scanf("%d %d %d" , & n , & m , & s);
    for(int v , u , i = 1;i <= m;++ i) {
        scanf("%d %d" , & v , & u);
        adj[v].push_back(u);
    }
    dfs(s);
    for(int i = 1;i <= n;++ i) {
        for(int j : adj[i]) {
            if(par[j][0] == i) continue ;
            if(! mark[i] || j == s) continue ;
            if(get_lca(i , j) == s) {
                printf("Possible\n");
                printV(i , j);
                printV(j);
                return 0;
            }
        }
    }
    printf("Impossible");
    return 0;
}